#include "decorator.h"
#include <iostream>
namespace Decorator{
int test() {
    // 创建基本的新能源汽车
    NewEnergyCar* myCar = new BasicNewEnergyCar();

    // 用户选择添加的配件
    std::cout << "选择要为新能源汽车添加的配件:" << std::endl;
    std::cout << "1. 行车记录仪\n2. 车载空气净化器\n3. 倒车摄像头\n4. 倒车雷达\n5. 车载导航系统\n";

    int choice;
    std::cout << "请输入配件编号 (0 结束): ";
    std::cin >> choice;

    while (choice != 0) {
        switch (choice) {
        case 1:
            myCar = new DashCameraDecorator(myCar);
            break;
        case 2:
            myCar = new AirPurifierDecorator(myCar);
            break;
        case 3:
            myCar = new AsternCameraDecorator(myCar);
            break;
        case 4:
            myCar = new AsternRadarDecorator(myCar);
            break;
        case 5:
            myCar = new NavigationDecorator(myCar);
            break;
        default:
            std::cout << "无效选择，请输入有效的配件编号。" << std::endl;
            break;
        }

        std::cout << "当前汽车状态: ";
        myCar->showStatus();

        std::cout << "请输入配件编号 (0 结束): ";
        std::cin >> choice;
    }

    std::cout << "完成为新能源汽车添加配件。最终状态: ";
    myCar->showStatus();
    
    // 释放内存
    delete myCar;

    return 0;
}
}
