#include "navigation.h"
#include <iostream>

int main() {
    // �ͻ��˴���ֻ��������ཻ�������������ϵͳ�ĸ�����
    NavigationFacade navigationSystem;
    std::string result = navigationSystem.startNavigation();

    std::cout << result << std::endl;
    std::cin.get();
    return 0;
}
