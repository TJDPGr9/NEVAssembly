// main.cpp
#include "command.h"
#include <thread>

void executeParallelCommands(Command* command1, Command* command2, Command* command3) {
    std::thread thread1([&]() { if (command1) command1->execute(); });
    thread1.join();  // �ȴ� command1 ִ�����

    std::thread thread2([&]() { if (command2) command2->execute(); });
    thread2.join();  // �ȴ� command2 ִ�����

    std::thread thread3([&]() { if (command3) command3->execute(); });
    thread3.join();  // �ȴ� command3 ִ�����
}

int main() {
    DevelopmentTeam team;

    SplitRequirementsCommand splitRequirements(&team, "�����ܡ��綯���Զ���ʻ");
    SetPriorityAndDueCommand setPriority1(&team, "�綯��", 1, "2023-01-01");
    SetPriorityAndDueCommand setPriority2(&team, "�Զ���ʻ", 2, "2023-02-01");
    SetPriorityAndDueCommand setPriority3(&team, "�����ܵ��", 3, "2023-03-01");
    DevelopFeatureCommand developFeature1(&team, "�綯��");
    DevelopFeatureCommand developFeature2(&team, "�Զ���ʻ");
    DevelopFeatureCommand developFeature3(&team, "�����ܵ��");

    executeParallelCommands(&splitRequirements, nullptr, nullptr);
    executeParallelCommands(&setPriority1, &developFeature1, nullptr);
    executeParallelCommands(&setPriority2, &developFeature2, nullptr);
    executeParallelCommands(&setPriority3, &developFeature3, nullptr);

    return 0;
}
