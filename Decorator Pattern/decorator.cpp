#include "decorator.h"

int main() {
    // ������������Դ��������
    NewEnergyCar* basicNewEnergyCar = new BasicNewEnergyCar();

    // ���װ��
    NewEnergyCar* newEnergyCarWithDashCamera = new DashCameraDecorator(basicNewEnergyCar);
    NewEnergyCar* newEnergyCarWithAirPurifier = new AirPurifierDecorator(newEnergyCarWithDashCamera);
    NewEnergyCar* fullyEquippedNewEnergyCar = new NavigationDecorator(new AsternRadarDecorator(newEnergyCarWithAirPurifier));

    // ��ʾ״̬
    cout << "Basic New Energy Car Status:\n";
    basicNewEnergyCar->showStatus();
    cout << "\nNew Energy Car with Dash Camera:\n";
    newEnergyCarWithDashCamera->showStatus();
    cout << "\nNew Energy Car with Air Purifier:\n";
    newEnergyCarWithAirPurifier->showStatus();
    cout << "\nFully Equipped New Energy Car:\n";
    fullyEquippedNewEnergyCar->showStatus();

    // �ͷ��ڴ�
    delete basicNewEnergyCar;
    delete newEnergyCarWithDashCamera;
    delete newEnergyCarWithAirPurifier;
    delete fullyEquippedNewEnergyCar;

    return 0;
}