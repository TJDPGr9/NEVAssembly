#include "navigation.h"
#include <iostream>
namespace Navigation {
    int test() {
        // �ͻ��˴���ֻ��������ཻ�������������ϵͳ�ĸ�����
        NavigationFacade navigationSystem;
        std::string result = navigationSystem.startNavigation();

        std::cout << result << std::endl;

        return 0;
    }
}
