#include "navigation.h"
#include <iostream>
#ifdef _WIN32
#include<Windows.h>
#endif
int main() {
#ifdef _WIN32
    SetConsoleCP(936);
    SetConsoleOutputCP(936);
#endif
    // �ͻ��˴���ֻ��������ཻ�������������ϵͳ�ĸ�����
    NavigationFacade navigationSystem;
    std::string result = navigationSystem.startNavigation();

    std::cout << result << std::endl;
    std::cin.get();
    return 0;
}
