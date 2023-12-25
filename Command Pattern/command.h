// command.h
#ifndef CAR_ASSEMBLY_COMMAND_H
#define CAR_ASSEMBLY_COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include<windows.h>
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
};

void DevelopmentTeam::splitRequirements(const std::string& requirements) {
    std::cout << "研发团队收到需求：" << requirements << std::endl;
    // 模拟拆分需求的过程
    // 将需求拆分为多个特性
    features_ = { "电动机", "自动驾驶", "高性能电池" };
}

void DevelopmentTeam::setPriorityAndDue(const std::string& feature, int priority, const std::string& due) {
    std::cout << "为特性 '" << feature << "' 设置优先级和截止日期：优先级 " << priority << "，截止日期 " << due << std::endl;
    // 模拟设置优先级与截止日期的过程
    // 实际应用中会涉及更复杂的逻辑
}

void DevelopmentTeam::developFeature(const std::string& feature) {
    std::cout << "研发特性：" << feature << std::endl;
    // 模拟研发过程
    Sleep(500);
    std::cout << "特性 '" << feature << "' 研发完成。" << std::endl;
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
