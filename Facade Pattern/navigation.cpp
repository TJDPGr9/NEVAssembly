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
    // 客户端代码只需与外观类交互，无需关心子系统的复杂性
    NavigationFacade navigationSystem;
    std::string result = navigationSystem.startNavigation();

    std::cout << result << std::endl;
    std::cin.get();
    return 0;
}
