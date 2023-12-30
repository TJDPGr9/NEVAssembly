#include "FluentInterface.h"


ElectricCarSettings::ElectricCarSettings() {}
//���ģʽ
std::map<std::string, ElectricCarSettings::ChargingMode> ElectricCarSettings::chargingModeMap = {
    {"���", ChargingMode::Fast},
    {"����", ChargingMode::Slow}
};
ElectricCarSettings& ElectricCarSettings::setChargingMode(const std::string& mode) {
    auto it = chargingModeMap.find(mode);
    if (it != chargingModeMap.end()) {
        chargingMode = it->second;
        set_chargingMode = mode;
    }
    else {
        std::cout << "δ��ƥ��" << std::endl;
    }
    return *this;
}
//����������
std::map<std::string, ElectricCarSettings::ConnectorType> ElectricCarSettings::connectorTypeMap = {
    {"ֱ�����ٳ��������", ConnectorType::DC_FastCharger},
    {"�������ó��������", ConnectorType::AC_HomeCharger}
};
ElectricCarSettings& ElectricCarSettings::setConnectorType(const std::string& type) {
    auto it = connectorTypeMap.find(type);
    if (it != connectorTypeMap.end()) {
        connectorType = it->second;
        set_connectorType = type;
    }
    else {
        std::cout <<"δ��ƥ��" << std::endl;
    }
    return *this;
}
//��ر���ģʽ	
std::map<std::string, ElectricCarSettings::BatterySaveMode> ElectricCarSettings::batterySaveModeMap = {
    {"����", BatterySaveMode::Enabled},
    {"����", BatterySaveMode::Disabled}
};

ElectricCarSettings& ElectricCarSettings::enableBatterySaveMode(const std::string& savemode) {
    auto it = batterySaveModeMap.find(savemode);
    if (it != batterySaveModeMap.end()) {
        batterySaveMode = it->second;
        set_batterySaveMode = savemode;
    }
    else {
        std::cout << "δ��ƥ��" << std::endl;
    }
    return *this;
}
//��ʻģʽ
std::map<std::string, ElectricCarSettings::DriveMode> ElectricCarSettings::driveModeMap = {
    {"���綯", DriveMode::PureElectric},
    {"��϶���", DriveMode::Hybrid}
};

ElectricCarSettings& ElectricCarSettings::setDriveMode(const std::string& mode) {
    auto it = driveModeMap.find(mode);
    if (it != driveModeMap.end()) {
        driveMode = it->second;
        set_driveMode = mode;
    }
    else {
        std::cout << "δ��ƥ��" << std::endl;
    }
    return *this;
}
//��������ģʽ
std::map<std::string, ElectricCarSettings::EnergyRecoveryMode> ElectricCarSettings::energyRecoveryModeMap = {
    {"��", EnergyRecoveryMode::High},
    {"��", EnergyRecoveryMode::Low},
    {"�ر�", EnergyRecoveryMode::Off}
};

ElectricCarSettings& ElectricCarSettings::setEnergyRecoveryMode(const std::string& mode) {
    auto it = energyRecoveryModeMap.find(mode);
    if (it != energyRecoveryModeMap.end()) {
        energyRecoveryMode = it->second;
        set_energyRecoveryMode = mode;
    }
    else {
        std::cout << "δ��ƥ��" << std::endl;
    }
    return *this;
}
//���ƻ�

std::map<std::string, ElectricCarSettings::ChargingPlan> ElectricCarSettings::chargingPlanMap = {
    {"��ʱ���", ChargingPlan::Immediate},
    {"��ʱ���", ChargingPlan::Scheduled}
};

ElectricCarSettings& ElectricCarSettings::setChargingPlan(const std::string& plan) {
    auto it = chargingPlanMap.find(plan);
    if (it != chargingPlanMap.end()) {
        chargingPlan = it->second;
        set_chargingPlan = plan;
    }
    else {
        std::cout << "δ��ƥ��" << std::endl;
    }
    return *this;
}
//����¶ȹ���
std::map<std::string, ElectricCarSettings::TemperatureManagement> ElectricCarSettings::temperatureManagementMap = {
    {"����", TemperatureManagement::Active},
    {"����", TemperatureManagement::Passive}
};

ElectricCarSettings& ElectricCarSettings::setBatteryTemperatureManagement(const std::string& management) {
    auto it = temperatureManagementMap.find(management);
    if (it != temperatureManagementMap.end()) {
        batteryTemperatureManagement = it->second;
        set_batteryTemperatureManagement = management;
    }
    else {
        std::cout << "δ��ƥ��" << std::endl;
    }
    return *this;
}
//���ֲ�������ʵ�֣�
// �������ֲ����ĺ���ʵ��
ElectricCarSettings& ElectricCarSettings::setPreheatCoolSettingTime(int time) {
    preHeatCoolSettingTime = time;
    return *this;
}

ElectricCarSettings& ElectricCarSettings::setPreheatCoolTargetTemperature(int temperature) {
    preHeatCoolTargetTemperature = temperature;
    return *this;
}

ElectricCarSettings& ElectricCarSettings::setMaxDrivingSpeedLimit(int speedLimit) {
    maxDrivingSpeedLimit = speedLimit;
    return *this;
}

ElectricCarSettings& ElectricCarSettings::setVolumeAdjustment(int volume) {
    volumeAdjustment = volume;
    return *this;
}
void ElectricCarSettings::displaySettings() const {
    std::cout << std::endl;
    std::cout << "�綯������" << std::endl;
    std::cout << "���ģʽ: " << set_chargingMode  << std::endl;
    std::cout << "���������: " << set_connectorType << std::endl;
    std::cout << "��ر���ģʽ: " << set_batterySaveMode << std::endl;
    std::cout << "��ʻģʽ: " << set_driveMode << std::endl;
    std::cout << "��������ģʽ�� " << set_energyRecoveryMode << std::endl;
    std::cout << "���ƻ�: " << set_chargingPlan << std::endl;
    std::cout << "����¶ȹ���: " << set_batteryTemperatureManagement << std::endl;

    std::cout << "Ԥ��/Ԥ���趨ʱ��: " << preHeatCoolSettingTime <<"����"<< std::endl;
    std::cout << "Ԥ��/Ԥ��Ŀ���¶�: " << preHeatCoolTargetTemperature << "���϶�" << std::endl;
    std::cout << "�����ʻ�ٶ��趨: " << maxDrivingSpeedLimit << "ǧ��/ʱ" << std::endl;
    std::cout << "������������: " << volumeAdjustment << "%" << std::endl;
}