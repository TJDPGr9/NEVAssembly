// Input.cpp
#include "Input.h"

std::string Input::selectChargingMode() {
    std::string chargingMode;
    std::cout << "��ѡ����ģʽ (1 - ���, 2 - ����): ";
    std::cin >> chargingMode;

    while (chargingMode != "1" && chargingMode != "2") {
        std::cout << "��������Ч�ĳ��ģʽ (1 - ���, 2 - ����): ";
        std::cin >> chargingMode;
    }

    return (chargingMode=="1" ? "���" : "����");
}

std::string Input::selectConnectorType() {
    std::string connectorType;
    std::cout << "��ѡ���������� (1 - ֱ�����ٳ��������, 2 - �������ó��������): ";
    std::cin >> connectorType;

    while (connectorType != "1" && connectorType != "2") {
        std::cout << "��������Ч�ĳ�������� (1 - ֱ�����ٳ��������, 2 - �������ó��������): ";
        std::cin >> connectorType;
    }

    return (connectorType == "1" ? "ֱ�����ٳ��������" : "�������ó��������");
}

std::string Input::selectBatterySaveMode() {
    std::string batterySaveMode;
    std::cout << "��ѡ���ر���ģʽ (1 - ����, 2 - ����): ";
    std::cin >> batterySaveMode;

    while (batterySaveMode != "1" && batterySaveMode != "2") {
        std::cout << "��������Ч�ĵ�ر���ģʽ (1 - ����, 2 - ����): ";
        std::cin >> batterySaveMode;
    }

    return (batterySaveMode == "1" ? "����" : "����");

}

std::string Input::selectDriveMode() {
    std::string driveMode;
    std::cout << "��ѡ���ʻģʽ (1 - ���綯, 2 - ��϶���): ";
    std::cin >> driveMode;

    while (driveMode != "1" && driveMode != "2") {
        std::cout << "��������Ч�ļ�ʻģʽ (1 - ���綯, 2 - ��϶���): ";
        std::cin >> driveMode;
    }

    return (driveMode == "1" ? "���綯" : "��϶���");
}

std::string Input::selectEnergyRecoveryMode() {
    std::string energyRecoveryMode;
    std::cout << "��ѡ����������ģʽ (1 - ��, 2 - �ͣ�3 - �ر�): ";
    std::cin >> energyRecoveryMode;

    while (energyRecoveryMode != "1" && energyRecoveryMode != "2" && energyRecoveryMode != "3") {
        std::cout << "��������Ч����������ģʽ (1 - ��, 2 - �ͣ�3 - �ر�): ";
        std::cin >> energyRecoveryMode;
    }
    if (energyRecoveryMode == "1") {
        return "��";
   }
    else if(energyRecoveryMode == "2"){
        return "��";
    }
    else {
        return "�ر�";
    }
   
}

std::string Input::selectChargingPlan() {
    std::string chargingPlan;
    std::cout << "��ѡ����ƻ� (1 - ��ʱ���, 2 - ��ʱ���): ";
    std::cin >> chargingPlan;

    while (chargingPlan != "1" && chargingPlan != "2") {
        std::cout << "��������Ч�ĳ��ƻ� (1 - ��ʱ���, 2 - ��ʱ���): ";
        std::cin >> chargingPlan;
    }
    if (chargingPlan == "1") {
        return "��ʱ���";
    }
    else {
        return "��ʱ���";
    }
}

std::string Input::selectBatteryTemperatureManagement() {
    std::string batteryTemperatureManagement;
    std::cout << "��ѡ�����¶ȹ��� (1 - ����, 2 - ����): ";
    std::cin >> batteryTemperatureManagement;

    while (batteryTemperatureManagement != "1" && batteryTemperatureManagement != "2") {
        std::cout << "��������Ч�ĵ���¶ȹ��� (1 - ����, 2 - ����): ";
        std::cin >> batteryTemperatureManagement;
    }
    if (batteryTemperatureManagement == "1") {
        return "����";
    }
    else {
        return "����";
    }
}

//���ֲ�������
int Input::selectPreheatCoolSettingTime() {
    int time;
    std::cout << "������Ԥ��/Ԥ���趨ʱ�� (��λ�����ӣ�����0): ";
    std::cin >> time;

    while (time <= 0 || std::cin.fail()) {
        std::cout << "��������Ч��Ԥ��/Ԥ���趨ʱ�� (��λ�����ӣ�����0): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> time;
    }

    return time;
}

int Input::selectPreheatCoolTargetTemperature() {
    int temperature;
    std::cout << "������Ԥ��/Ԥ��Ŀ���¶� (��Χ16-30����λ�����϶�): ";
    std::cin >> temperature;

    while (temperature < 16 || temperature > 30 || std::cin.fail()) {
        std::cout << "��������Ч��Ԥ��/Ԥ��Ŀ���¶� (��Χ16-30����λ�����϶�): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> temperature;
    }

    return temperature;
}

int Input::selectMaxDrivingSpeedLimit() {
    int speedLimit;
    std::cout << "�����������ʻ�ٶ����� (��Χ30-300����λ��ǧ��/ʱ): ";
    std::cin >> speedLimit;

    while (speedLimit < 30 || speedLimit > 300 || std::cin.fail()) {
        std::cout << "��������Ч�������ʻ�ٶ����� (��Χ30-300����λ��ǧ��/ʱ): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> speedLimit;
    }

    return speedLimit;
}

int Input::selectVolumeAdjustment() {
    int volume;
    std::cout << "�������������� (��Χ0-100����λ��%): ";
    std::cin >> volume;

    while (volume < 0 || volume > 100 || std::cin.fail()) {
        std::cout << "��������Ч���������� (��Χ0-100����λ��%): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> volume;
    }

    return volume;
}