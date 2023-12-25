// main.cpp
#include "command.h"
#include <thread>
#include<list>
#include<chrono>

#include <future>
#ifdef _WIN32
#include <Windows.h>
#include <windows.h>
static int setCodePage() {
    if (SetConsoleCP(936) == 0) {
        std::cerr << "Failed to set input console code page." << std::endl;
        return 1;
    }
    // 设置输出控制台代码页为GBK
    if (SetConsoleOutputCP(936) == 0) {
        std::cerr << "Failed to set output console code page." << std::endl;
        return 1;
    }
}
#elif __linux__
#include<unistd.h>
#endif
class Marketing {
private:
    list<Command*> _commands;
    void _resetCommands() {
        _commands.clear();
    }
public:
    Marketing() {
        _resetCommands();
    }
    void setCommand(Command* command) {
        _commands.push_back(command);
    }
    void setCommands(list<Command*> commands,bool reset=true) {
        if(reset)
            _resetCommands();
        for(Command* command : commands)
        {
            _commands.push_back(command);
        }
    }
    void executeParallelCommands() {
        vector<std::future<void>> futures;

        for (Command* command : _commands) {
            futures.push_back(std::async(std::launch::async, [command]() {
                if (command) command->execute();
                }));
        }

        // 等待所有异步任务完成
        for (auto& future : futures) {
            future.get();
        }
        
    }
};
int main() {
    #ifdef _WIN32
    setCodePage();
    if (!IsDebuggerPresent()) {
        // Enable ANSI escape codes for console color in Release mode
        SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }
    #endif
    DevelopmentTeam team;

    SplitRequirementsCommand splitRequirements(&team, "¸ßÐÔÄÜ¡¢µç¶¯¡¢×Ô¶¯¼ÝÊ»");
    SetPriorityAndDueCommand setPriority1(&team, "µç¶¯»ú", 1, "2023-01-01");
    SetPriorityAndDueCommand setPriority2(&team, "×Ô¶¯¼ÝÊ»", 2, "2023-02-01");
    SetPriorityAndDueCommand setPriority3(&team, "¸ßÐÔÄÜµç³Ø", 3, "2023-03-01");
    DevelopFeatureCommand developFeature1(&team, "µç¶¯»ú");
    DevelopFeatureCommand developFeature2(&team, "×Ô¶¯¼ÝÊ»");
    DevelopFeatureCommand developFeature3(&team, "¸ßÐÔÄÜµç³Ø");
    Marketing* market = new Marketing();
    market->setCommand(&splitRequirements);
    market->executeParallelCommands();
    list<Command*> args;
    args.push_back(&setPriority1);
    args.push_back(&setPriority2);
    args.push_back(&setPriority3);
    market->setCommands(args);
    market->executeParallelCommands();
    args.clear();
    args.push_back(&developFeature1);
    args.push_back(&developFeature2);
    args.push_back(&developFeature3);
    market->setCommands(args);
    market->executeParallelCommands();
    std::cin.get();
    return 0;
}
