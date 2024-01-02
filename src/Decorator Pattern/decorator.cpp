#include "decorator.h"
#include <iostream>
namespace Decorator {
    int test() {
        // 创建基本的新能源汽车
        NewEnergyCar* myCar = new BasicNewEnergyCar();

        // 用户选择添加的配件
        std::cout << "Select accessories to add to the new energy car:" << std::endl;
        std::cout << "1. Dash Camera\n2. Car Air Purifier\n3. Reverse Camera\n4. Reverse Radar\n5. Car Navigation System\n";

        int choice;
        std::cout << "Enter accessory number (0 to finish): ";
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
                std::cout << "Invalid choice, please enter a valid accessory number." << std::endl;
                break;
            }

            std::cout << "Current car status: ";
            myCar->showStatus();

            std::cout << "Enter accessory number (0 to finish): ";
            std::cin >> choice;
        }

        std::cout << "Finished adding accessories to the new energy car. Final status: ";
        myCar->showStatus();

        // 释放内存
        delete myCar;

        return 0;
    }
}
