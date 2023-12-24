#include "command.h"
#include <thread>

// 实现接收者类的方法
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
    // 实际应用中会涉及更复杂的逻辑
    // 这里只是为了演示，并行执行的可能性，使用了简单的 sleep
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "特性 '" << feature << "' 研发完成。" << std::endl;
}

// 客户端代码
int main() {
    DevelopmentTeam team;

    SplitRequirementsCommand splitRequirements(&team, "高性能、电动、自动驾驶");
    SetPriorityAndDueCommand setPriority1(&team, "电动机", 1, "2023-01-01");
    SetPriorityAndDueCommand setPriority2(&team, "自动驾驶", 2, "2023-02-01");
    SetPriorityAndDueCommand setPriority3(&team, "高性能电池", 3, "2023-03-01");
    DevelopFeatureCommand developFeature1(&team, "电动机");
    DevelopFeatureCommand developFeature2(&team, "自动驾驶");
    DevelopFeatureCommand developFeature3(&team, "高性能电池");

    // 并行执行命令
    std::thread thread1([&]() {
        splitRequirements.execute();
        setPriority1.execute();
        developFeature1.execute();
        });

    std::thread thread2([&]() {
        setPriority2.execute();
        developFeature2.execute();
        });

    std::thread thread3([&]() {
        setPriority3.execute();
        developFeature3.execute();
        });

    // 等待线程执行完成
    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
