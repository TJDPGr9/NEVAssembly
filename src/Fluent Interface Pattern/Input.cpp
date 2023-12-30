// Input.cpp
#include "Input.h"

std::string Input::selectChargingMode() {
    std::vector<std::string> chargingModes;
    for (const auto& pair : ElectricCarSettings::chargingModeMap) {
        chargingModes.push_back(pair.first);
    }

    std::cout << "��ѡ����ģʽ��" << std::endl;

    for (size_t i = 0; i < chargingModes.size(); ++i) {
        std::cout << i + 1 << " - " << chargingModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "������ѡ��ĳ��ģʽ��ţ�";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(chargingModes.size())) {
        std::cout << "��������Ч�ĳ��ģʽ��ţ�";
        std::cin >> userChoice;
    }
    std::cout << std::endl;
    return chargingModes[userChoice - 1];
}

std::string Input::selectConnectorType() {
    std::vector<std::string> connectorTypes;
    for (const auto& pair : ElectricCarSettings::connectorTypeMap) {
        connectorTypes.push_back(pair.first);
    }

    std::cout << "��ѡ������������" << std::endl;

    for (size_t i = 0; i < connectorTypes.size(); ++i) {
        std::cout << i + 1 << " - " << connectorTypes[i] << std::endl;
    }

    int userChoice;
    std::cout << "������ѡ��ĳ����������ţ�";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(connectorTypes.size())) {
        std::cout << "��������Ч�ĳ����������ţ�";
        std::cin >> userChoice;
    }
    std::cout << std::endl;
    return connectorTypes[userChoice - 1] ;
}

std::string Input::selectBatterySaveMode() {
    std::vector<std::string> batterySaveModes;
    for (const auto& pair : ElectricCarSettings::batterySaveModeMap) {
        batterySaveModes.push_back(pair.first);
    }
    std::cout << "��ѡ���ر���ģʽ��" << std::endl;

    for (size_t i = 0; i < batterySaveModes.size(); ++i) {
        std::cout << i + 1 << " - " << batterySaveModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "������ѡ��ĵ�ر���ģʽ��ţ�";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(batterySaveModes.size())) {
        std::cout << "��������Ч�ĵ�ر���ģʽ��ţ�";
        std::cin >> userChoice;
    }
    std::cout << std::endl;
    return batterySaveModes[userChoice - 1];
}
std::string Input::selectDriveMode() {
    std::vector<std::string> driveModes;
    for (const auto& pair : ElectricCarSettings::driveModeMap) {
        driveModes.push_back(pair.first);
    }
    std::cout << "��ѡ���ʻģʽ��" << std::endl;

    for (size_t i = 0; i < driveModes.size(); ++i) {
        std::cout << i + 1 << " - " << driveModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "������ѡ��ļ�ʻģʽ��ţ�";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(driveModes.size())) {
        std::cout << "��������Ч�ļ�ʻģʽ��ţ�";
        std::cin >> userChoice;
    }
    std::cout << std::endl;
    return driveModes[userChoice - 1];
}


std::string Input::selectEnergyRecoveryMode() {
    std::vector<std::string> energyRecoveryModes;
    for (const auto& pair : ElectricCarSettings::energyRecoveryModeMap) {
        energyRecoveryModes.push_back(pair.first);
    }
    std::cout << "��ѡ����������ģʽ��" << std::endl;

    for (size_t i = 0; i < energyRecoveryModes.size(); ++i) {
        std::cout << i + 1 << " - " << energyRecoveryModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "������ѡ�����������ģʽ��ţ�";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(energyRecoveryModes.size())) {
        std::cout << "��������Ч����������ģʽ��ţ�";
        std::cin >> userChoice;
    }
    std::cout<< std::endl;
    return energyRecoveryModes[userChoice - 1];
   
}

std::string Input::selectChargingPlan() {
    std::vector<std::string> chargingPlans;
    for (const auto& pair : ElectricCarSettings::chargingPlanMap) {
        chargingPlans.push_back(pair.first);
    }
    std::cout << "��ѡ����ƻ���" << std::endl;

    for (size_t i = 0; i < chargingPlans.size(); ++i) {
        std::cout << i + 1 << " - " << chargingPlans[i] << std::endl;
    }

    int userChoice;
    std::cout << "������ѡ��ĳ��ƻ���ţ�";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(chargingPlans.size())) {
        std::cout << "��������Ч�ĳ��ƻ���ţ�";
        std::cin >> userChoice;
    }
    std::cout << std::endl;
    return chargingPlans[userChoice - 1];

}

std::string Input::selectBatteryTemperatureManagement() {
    std::vector<std::string> batteryTemperatureManagements;
    for (const auto& pair : ElectricCarSettings::temperatureManagementMap) {
        batteryTemperatureManagements.push_back(pair.first);
    }
    std::cout << "��ѡ�����¶ȹ���" << std::endl;

    for (size_t i = 0; i < batteryTemperatureManagements.size(); ++i) {
        std::cout << i + 1 << " - " << batteryTemperatureManagements[i] << std::endl;
    }

    int userChoice;
    std::cout << "������ѡ��ĵ���¶ȹ����ţ�";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(batteryTemperatureManagements.size())) {
        std::cout << "��������Ч�ĵ���¶ȹ����ţ�";
        std::cin >> userChoice;
    }
    std::cout << std::endl;
    return batteryTemperatureManagements[userChoice - 1];
}



//���ֲ�������
int Input::selectPreHeatCoolSettingTime() {
    std::cout << "������Ԥ��/Ԥ���趨ʱ�� (��Χ��" << ElectricCarSettings::minPreHeatCoolTime << " - " << ElectricCarSettings::maxPreHeatCoolTime << ", ��λ�����ӣ�): ";
    int time;
    std::cin >> time;

    while (time < ElectricCarSettings::minPreHeatCoolTime || time > ElectricCarSettings::maxPreHeatCoolTime || std::cin.fail()) {
        std::cout << "��������Ч��Ԥ��/Ԥ���趨ʱ�� (��Χ��" << ElectricCarSettings::minPreHeatCoolTime << " - " << ElectricCarSettings::maxPreHeatCoolTime << ", ��λ�����ӣ�): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> time;
    }
    std::cout << std::endl;
    return time;
}

int Input::selectPreHeatCoolTargetTemperature() {
    std::cout << "������Ԥ��/Ԥ��Ŀ���¶� (��Χ��" << ElectricCarSettings::minPreHeatCoolTargetTemp << " - " << ElectricCarSettings::maxPreHeatCoolTargetTemp << "����λ�����϶�): ";
    int temperature;
    std::cin >> temperature;

    while (temperature < ElectricCarSettings::minPreHeatCoolTargetTemp || temperature > ElectricCarSettings::maxPreHeatCoolTargetTemp || std::cin.fail()) {
        std::cout << "��������Ч��Ԥ��/Ԥ��Ŀ���¶� (��Χ��" << ElectricCarSettings::minPreHeatCoolTargetTemp << " - " << ElectricCarSettings::maxPreHeatCoolTargetTemp << "����λ�����϶�): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> temperature;
    }
    std::cout << std::endl;
    return temperature;
}

int Input::selectMaxDrivingSpeedLimit() {
    std::cout << "�����������ʻ�ٶ����� (��Χ��" << ElectricCarSettings::minSpeedLimit << " - " << ElectricCarSettings::maxSpeedLimit << "����λ��ǧ��/ʱ): ";
    int speedLimit;
    std::cin >> speedLimit;

    while (speedLimit < ElectricCarSettings::minSpeedLimit || speedLimit > ElectricCarSettings::maxSpeedLimit || std::cin.fail()) {
        std::cout << "��������Ч�������ʻ�ٶ����� (��Χ" << ElectricCarSettings::minSpeedLimit << " - " << ElectricCarSettings::maxSpeedLimit << "����λ��ǧ��/ʱ): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> speedLimit;
    }
    std::cout << std::endl;
    return speedLimit;
}

int Input::selectVolumeAdjustment() {
    std::cout << "�������������� (��Χ��" << ElectricCarSettings::minVolume << " - " << ElectricCarSettings::maxVolume << "����λ��%): ";
    int volume;
    std::cin >> volume;

    while (volume < ElectricCarSettings::minVolume || volume > ElectricCarSettings::maxVolume || std::cin.fail()) {
        std::cout << "��������Ч���������� (��Χ��" << ElectricCarSettings::minVolume << " - " << ElectricCarSettings::maxVolume << "����λ��%): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> volume;
    }
    std::cout << std::endl;
    return volume;
}