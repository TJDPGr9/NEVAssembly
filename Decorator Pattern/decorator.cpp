#include "decorator.h"

int main() {
    // 创建基本新能源汽车对象
    NewEnergyCar* basicNewEnergyCar = new BasicNewEnergyCar();

    // 添加装饰
    NewEnergyCar* newEnergyCarWithDashCamera = new DashCameraDecorator(basicNewEnergyCar);
    NewEnergyCar* newEnergyCarWithAirPurifier = new AirPurifierDecorator(newEnergyCarWithDashCamera);
    NewEnergyCar* fullyEquippedNewEnergyCar = new NavigationDecorator(new AsternRadarDecorator(newEnergyCarWithAirPurifier));

    // 显示状态
    cout << "Basic New Energy Car Status:\n";
    basicNewEnergyCar->showStatus();
    cout << "\nNew Energy Car with Dash Camera:\n";
    newEnergyCarWithDashCamera->showStatus();
    cout << "\nNew Energy Car with Air Purifier:\n";
    newEnergyCarWithAirPurifier->showStatus();
    cout << "\nFully Equipped New Energy Car:\n";
    fullyEquippedNewEnergyCar->showStatus();

    // 释放内存
    delete basicNewEnergyCar;
    delete newEnergyCarWithDashCamera;
    delete newEnergyCarWithAirPurifier;
    delete fullyEquippedNewEnergyCar;

    return 0;
}