#include "navigation.h"
#include <iostream>

int main() {
    // 客户端代码只需与外观类交互，无需关心子系统的复杂性
    NavigationFacade navigationSystem;
    std::string result = navigationSystem.startNavigation();

    std::cout << result << std::endl;
    std::cin.get();
    return 0;
}
