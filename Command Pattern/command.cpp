#include "command.h"
#include <thread>

// ʵ�ֽ�������ķ���
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
    // ʵ��Ӧ���л��漰�����ӵ��߼�
    // ����ֻ��Ϊ����ʾ������ִ�еĿ����ԣ�ʹ���˼򵥵� sleep
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "���� '" << feature << "' �з���ɡ�" << std::endl;
}

// �ͻ��˴���
int main() {
    DevelopmentTeam team;

    SplitRequirementsCommand splitRequirements(&team, "�����ܡ��綯���Զ���ʻ");
    SetPriorityAndDueCommand setPriority1(&team, "�綯��", 1, "2023-01-01");
    SetPriorityAndDueCommand setPriority2(&team, "�Զ���ʻ", 2, "2023-02-01");
    SetPriorityAndDueCommand setPriority3(&team, "�����ܵ��", 3, "2023-03-01");
    DevelopFeatureCommand developFeature1(&team, "�綯��");
    DevelopFeatureCommand developFeature2(&team, "�Զ���ʻ");
    DevelopFeatureCommand developFeature3(&team, "�����ܵ��");

    // ����ִ������
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

    // �ȴ��߳�ִ�����
    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
