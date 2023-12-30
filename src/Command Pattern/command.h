// command.h
#ifndef CAR_ASSEMBLY_COMMAND_H
#define CAR_ASSEMBLY_COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#include <sys/ioctl.h>
#endif
#include<map>
#include<utility>
#include<regex>
#include<mutex>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"
using namespace std;

class Command {
public:
    virtual void execute() = 0;
};

class DevelopmentTeam {
public:
    void splitRequirements(const std::string& requirements);
    void setPriorityAndDue(const std::string& feature, int priority, const std::string& due);
    void developFeature(const std::string& feature);

private:
    std::vector<std::string> features_;
    std::map<std::string, std::pair<int, std::string>> featureInfoMap_;
    int firstLine=0;
    mutex lineNoMutex;
    void setFirstLine(int val) {
        std::lock_guard<std::mutex> lock(lineNoMutex);
        firstLine = val;
    }
};

void DevelopmentTeam::splitRequirements(const std::string& requirements) {
    std::cout << "ÑÐ·¢ÍÅ¶ÓÊÕµ½ÐèÇó£º" << requirements << std::endl;
    regex pattern("([^，]+)");

    sregex_iterator it(requirements.begin(), requirements.end(), pattern);
    sregex_iterator end;
    // Ä£Äâ²ð·ÖÐèÇóµÄ¹ý³Ì
    // ½«ÐèÇó²ð·ÖÎª¶à¸öÌØÐÔ
    while (it != end) {
        smatch match = *it;
        string item = match.str(1); 
        features_.push_back(item);
        ++it;
    }
    
    //features_ = { "µç¶¯»ú", "×Ô¶¯¼ÝÊ»", "¸ßÐÔÄÜµç³Ø" };
}
std::mutex consoleMutex;
void DevelopmentTeam::setPriorityAndDue(const std::string& feature, int priority, const std::string& due) {
    {
        lock_guard<mutex> lock(consoleMutex);
        featureInfoMap_[feature] = std::make_pair(priority, due);
        std::cout << "ÎªÌØÐÔ '" << feature << "' ÉèÖÃÓÅÏÈ¼¶ºÍ½ØÖ¹ÈÕÆÚ£ºÓÅÏÈ¼¶ " << priority << "£¬½ØÖ¹ÈÕÆÚ " << due << std::endl;
    }
    // Ä£ÄâÉèÖÃÓÅÏÈ¼¶Óë½ØÖ¹ÈÕÆÚµÄ¹ý³Ì
    // Êµ¼ÊÓ¦ÓÃÖÐ»áÉæ¼°¸ü¸´ÔÓµÄÂß¼­
}
std::mutex infoMutex;
void setCursorPosition(int x, int y) {
    #ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #elif __linux__
    std::cout << "\033[" << y << ";" << x << "H";
    #endif
}
int getCurrentConsoleLine() {
    #ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.dwCursorPosition.Y;
    }
    return -1; // 错误情况，返回-1或其他合适的值
    #elif __linux__
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
    #endif
}
void DevelopmentTeam::developFeature(const std::string& feature) {
    pair<int, string> info = featureInfoMap_[feature];
    {
        lock_guard<std::mutex> lock(infoMutex);
        cout << ANSI_COLOR_RESET;
        if (firstLine)
            setCursorPosition(0, firstLine + get<0>(info) * 3 - 4);
        cout << ANSI_COLOR_RESET << "ÑÐ·¢ÌØÐÔ£º" << feature << std::endl;
        if (firstLine == 0) {
            setFirstLine(getCurrentConsoleLine());
        }
    }

    // Ä£ÄâÑÐ·¢¹ý³Ì
    for (int i = 0; i < 10; i++) {
        if (i < 3)
            cout << ANSI_COLOR_RED;
        else if (i < 6)
            cout << ANSI_COLOR_YELLOW;
        else if (i < 10)
            cout << ANSI_COLOR_GREEN;
        {
            std::lock_guard<std::mutex> lock(infoMutex);
            setCursorPosition(0, firstLine + get<0>(info) * 3 - 3);
            std::cout << ": [";
        }
        for (int j = 0; j < 100; ++j) {
            {
                std::lock_guard<std::mutex> lock(infoMutex);
                if (j < (i + 1) * 10) {
                    setCursorPosition(3 + j, firstLine + get<0>(info) * 3 - 3);
                    std::cout << "=";
                }
                else {
                    setCursorPosition(3 + j, firstLine + get<0>(info) * 3 - 3);
                    std::cout << " ";
                }
            }
        }
        {
            std::lock_guard<std::mutex> lock(infoMutex);
            setCursorPosition(103, firstLine + get<0>(info) * 3 - 3);
            std::cout << "] " << (i + 1) * 10 << "%";
        }
        std::cout.flush(); // 刷新输出缓冲区
        #ifdef _WIN32
        Sleep(100 * get<0>(info));
        #elif __linux__
        sleep(100 * get<0>(info));
        #endif
    }
    cout << ANSI_COLOR_RESET;
    std::cout << endl;
    {
        std::lock_guard<std::mutex> lock(infoMutex);
        setCursorPosition(0, firstLine + get<0>(info) * 3 - 2);
        std::cout << "ÌØÐÔ '" << feature << "' ÑÐ·¢Íê³É¡£" << std::endl;
    }
}

class SplitRequirementsCommand : public Command {
public:
    SplitRequirementsCommand(DevelopmentTeam* team, const std::string& requirements)
        : team_(team), requirements_(requirements) {}

    void execute() override {
        team_->splitRequirements(requirements_);
    }

private:
    DevelopmentTeam* team_;
    std::string requirements_;
};

class SetPriorityAndDueCommand : public Command {
public:
    SetPriorityAndDueCommand(DevelopmentTeam* team, const std::string& feature, int priority, const std::string& due)
        : team_(team), feature_(feature), priority_(priority), due_(due) {}

    void execute() override {
        team_->setPriorityAndDue(feature_, priority_, due_);
    }

private:
    DevelopmentTeam* team_;
    std::string feature_;
    int priority_;
    std::string due_;
};

class DevelopFeatureCommand : public Command {
public:
    DevelopFeatureCommand(DevelopmentTeam* team, const std::string& feature)
        : team_(team), feature_(feature) {}

    void execute() override {
        team_->developFeature(feature_);
    }

private:
    DevelopmentTeam* team_;
    std::string feature_;
};

#endif // CAR_ASSEMBLY_COMMAND_H
