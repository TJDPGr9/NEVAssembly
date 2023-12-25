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
    std::cout << "�з��Ŷ��յ�����" << requirements << std::endl;
    // ģ��������Ĺ���
    // ��������Ϊ�������
    features_ = { "�綯��", "�Զ���ʻ", "�����ܵ��" };
}

void DevelopmentTeam::setPriorityAndDue(const std::string& feature, int priority, const std::string& due) {
    std::cout << "Ϊ���� '" << feature << "' �������ȼ��ͽ�ֹ���ڣ����ȼ� " << priority << "����ֹ���� " << due << std::endl;
    // ģ���������ȼ����ֹ���ڵĹ���
    // ʵ��Ӧ���л��漰�����ӵ��߼�
}

void DevelopmentTeam::developFeature(const std::string& feature) {
    std::cout << "�з����ԣ�" << feature << std::endl;
    // ģ���з�����
    Sleep(500);
    std::cout << "���� '" << feature << "' �з���ɡ�" << std::endl;
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
