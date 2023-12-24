#ifndef CAR_ASSEMBLY_COMMAND_H
#define CAR_ASSEMBLY_COMMAND_H

#include <iostream>
#include <string>
#include <vector>

// 抽象命令类
class Command {
public:
    virtual void execute() = 0;
};

// 接收者类 - 研发团队
class DevelopmentTeam {
public:
    void splitRequirements(const std::string& requirements);
    void setPriorityAndDue(const std::string& feature, int priority, const std::string& due);
    void developFeature(const std::string& feature);

private:
    std::vector<std::string> features_;
};

// 具体命令类 - 拆分需求
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

// 具体命令类 - 设置优先级与截止日期
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

// 具体命令类 - 进行研发
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
