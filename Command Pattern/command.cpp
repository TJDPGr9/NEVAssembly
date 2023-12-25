// main.cpp
#include "command.h"
#include <thread>

void executeParallelCommands(Command* command1, Command* command2, Command* command3) {
    std::thread thread1([&]() { if (command1) command1->execute(); });
    thread1.join();  // 等待 command1 执行完成

    std::thread thread2([&]() { if (command2) command2->execute(); });
    thread2.join();  // 等待 command2 执行完成

    std::thread thread3([&]() { if (command3) command3->execute(); });
    thread3.join();  // 等待 command3 执行完成
}

int main() {
    DevelopmentTeam team;

    SplitRequirementsCommand splitRequirements(&team, "高性能、电动、自动驾驶");
    SetPriorityAndDueCommand setPriority1(&team, "电动机", 1, "2023-01-01");
    SetPriorityAndDueCommand setPriority2(&team, "自动驾驶", 2, "2023-02-01");
    SetPriorityAndDueCommand setPriority3(&team, "高性能电池", 3, "2023-03-01");
    DevelopFeatureCommand developFeature1(&team, "电动机");
    DevelopFeatureCommand developFeature2(&team, "自动驾驶");
    DevelopFeatureCommand developFeature3(&team, "高性能电池");

    executeParallelCommands(&splitRequirements, nullptr, nullptr);
    executeParallelCommands(&setPriority1, &developFeature1, nullptr);
    executeParallelCommands(&setPriority2, &developFeature2, nullptr);
    executeParallelCommands(&setPriority3, &developFeature3, nullptr);

    return 0;
}
