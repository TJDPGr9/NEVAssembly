#include "FluentInterface.h"


ElectricCarSettings::ElectricCarSettings() {}
//���ģʽ

std::map<std::string, ElectricCarSettings::ChargingMode> ElectricCarSettings::chargingModeMap = {
    {"Fast Charging Mode", ChargingMode::Fast},
    {"Slow Charging Mode", ChargingMode::Slow}
};
ElectricCarSettings& ElectricCarSettings::setChargingMode(const std::string& mode) {
    auto it = chargingModeMap.find(mode);
    if (it != chargingModeMap.end()) {
        chargingMode = it->second;
        set_chargingMode = mode;
    }
    else {
        std::cout << "Failed to match" << std::endl;
    }
    return *this;
}
//����������
std::map<std::string, ElectricCarSettings::ConnectorType> ElectricCarSettings::connectorTypeMap = {
    {"DC Fast Charging Connector", ConnectorType::DC_FastCharger},
    {"AC Home Charging Connector", ConnectorType::AC_HomeCharger}
};
ElectricCarSettings& ElectricCarSettings::setConnectorType(const std::string& type) {
    auto it = connectorTypeMap.find(type);
    if (it != connectorTypeMap.end()) {
        connectorType = it->second;
        set_connectorType = type;
    }
    else {
        std::cout <<"Failed to match" << std::endl;
    }
    return *this;
}
//��ر���ģʽ	
std::map<std::string, ElectricCarSettings::BatterySaveMode> ElectricCarSettings::batterySaveModeMap = {
    {"Enabled", BatterySaveMode::Enabled},
    {"Disabled", BatterySaveMode::Disabled}
};

ElectricCarSettings& ElectricCarSettings::enableBatterySaveMode(const std::string& savemode) {
    auto it = batterySaveModeMap.find(savemode);
    if (it != batterySaveModeMap.end()) {
        batterySaveMode = it->second;
        set_batterySaveMode = savemode;
    }
    else {
        std::cout << "Failed to match" << std::endl;
    }
    return *this;
}
//��ʻģʽ
std::map<std::string, ElectricCarSettings::DriveMode> ElectricCarSettings::driveModeMap = {
    {"Pure Electric", DriveMode::PureElectric},
    {"Hybrid Power", DriveMode::Hybrid}
};

ElectricCarSettings& ElectricCarSettings::setDriveMode(const std::string& mode) {
    auto it = driveModeMap.find(mode);
    if (it != driveModeMap.end()) {
        driveMode = it->second;
        set_driveMode = mode;
    }
    else {
        std::cout << "Failed to match" << std::endl;
    }
    return *this;
}
//��������ģʽ
std::map<std::string, ElectricCarSettings::EnergyRecoveryMode> ElectricCarSettings::energyRecoveryModeMap = {
    {"High", EnergyRecoveryMode::High},
    {"Low", EnergyRecoveryMode::Low},
    {"Off", EnergyRecoveryMode::Off}
};

ElectricCarSettings& ElectricCarSettings::setEnergyRecoveryMode(const std::string& mode) {
    auto it = energyRecoveryModeMap.find(mode);
    if (it != energyRecoveryModeMap.end()) {
        energyRecoveryMode = it->second;
        set_energyRecoveryMode = mode;
    }
    else {
        std::cout << "Failed to match" << std::endl;
    }
    return *this;
}
//���ƻ�

std::map<std::string, ElectricCarSettings::ChargingPlan> ElectricCarSettings::chargingPlanMap = {
    {"Instant Charging", ChargingPlan::Immediate},
    {"Timed Charging", ChargingPlan::Scheduled}
};

ElectricCarSettings& ElectricCarSettings::setChargingPlan(const std::string& plan) {
    auto it = chargingPlanMap.find(plan);
    if (it != chargingPlanMap.end()) {
        chargingPlan = it->second;
        set_chargingPlan = plan;
    }
    else {
        std::cout << "Failed to match" << std::endl;
    }
    return *this;
}
//����¶ȹ���
std::map<std::string, ElectricCarSettings::TemperatureManagement> ElectricCarSettings::temperatureManagementMap = {
    {"Active", TemperatureManagement::Active},
    {"Passive", TemperatureManagement::Passive}
};

ElectricCarSettings& ElectricCarSettings::setBatteryTemperatureManagement(const std::string& management) {
    auto it = temperatureManagementMap.find(management);
    if (it != temperatureManagementMap.end()) {
        batteryTemperatureManagement = it->second;
        set_batteryTemperatureManagement = management;
    }
    else {
        std::cout << "Failed to match" << std::endl;
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
    std::cout << "Electric vehicle settings: " << std::endl;
    std::cout << "Charging Mode: " << set_chargingMode  << std::endl;
    std::cout << "ConnectorType: " << set_connectorType << std::endl;
    std::cout << "BatterySaveMode: " << set_batterySaveMode << std::endl;
    std::cout << "DriveMode: " << set_driveMode << std::endl;
    std::cout << "EnergyRecoveryMode��" << set_energyRecoveryMode << std::endl;
    std::cout << "ChargingPlan: " << set_chargingPlan << std::endl;
    std::cout << "BatteryTemperatureManagement: " << set_batteryTemperatureManagement << std::endl;

    std::cout << "Set pre cooling/preheating time: " << preHeatCoolSettingTime <<" minutes"<< std::endl;
    std::cout << "Set pre cooling/preheating target temperature: " << preHeatCoolTargetTemperature << " ��C" << std::endl;
    std::cout << "Set maximum driving speed: " << maxDrivingSpeedLimit << " km/h" << std::endl;
    std::cout << "Adjusting volume: " << volumeAdjustment << " %" << std::endl;
}