#include "decorator.h"
#include <iostream>

int main() {
    // ��������������Դ����
    NewEnergyCar* myCar = new BasicNewEnergyCar();

    // �û�ѡ����ӵ����
    std::cout << "ѡ��ҪΪ����Դ������ӵ����:" << std::endl;
    std::cout << "1. �г���¼��\n2. ���ؿ���������\n3. ��������ͷ\n4. �����״�\n5. ���ص���ϵͳ\n";

    int choice;
    std::cout << "������������ (0 ����): ";
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
            std::cout << "��Чѡ����������Ч�������š�" << std::endl;
            break;
        }

        std::cout << "��ǰ����״̬: ";
        myCar->showStatus();

        std::cout << "������������ (0 ����): ";
        std::cin >> choice;
    }

    std::cout << "���Ϊ����Դ����������������״̬: ";
    myCar->showStatus();
    
    // �ͷ��ڴ�
    delete myCar;

    return 0;
}
