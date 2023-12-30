#include "FluentInterface.h"


ElectricCarSettings::ElectricCarSettings() {}
//充电模式
std::map<std::string, ElectricCarSettings::ChargingMode> ElectricCarSettings::chargingModeMap = {
    {"快充", ChargingMode::Fast},
    {"慢充", ChargingMode::Slow}
};
ElectricCarSettings& ElectricCarSettings::setChargingMode(const std::string& mode) {
    auto it = chargingModeMap.find(mode);
    if (it != chargingModeMap.end()) {
        chargingMode = it->second;
        set_chargingMode = mode;
    }
    else {
        std::cout << "未能匹配" << std::endl;
    }
    return *this;
}
//连接器类型
std::map<std::string, ElectricCarSettings::ConnectorType> ElectricCarSettings::connectorTypeMap = {
    {"直流快速充电连接器", ConnectorType::DC_FastCharger},
    {"交流家用充电连接器", ConnectorType::AC_HomeCharger}
};
ElectricCarSettings& ElectricCarSettings::setConnectorType(const std::string& type) {
    auto it = connectorTypeMap.find(type);
    if (it != connectorTypeMap.end()) {
        connectorType = it->second;
        set_connectorType = type;
    }
    else {
        std::cout <<"未能匹配" << std::endl;
    }
    return *this;
}
//电池保存模式	
std::map<std::string, ElectricCarSettings::BatterySaveMode> ElectricCarSettings::batterySaveModeMap = {
    {"启用", BatterySaveMode::Enabled},
    {"禁用", BatterySaveMode::Disabled}
};

ElectricCarSettings& ElectricCarSettings::enableBatterySaveMode(const std::string& savemode) {
    auto it = batterySaveModeMap.find(savemode);
    if (it != batterySaveModeMap.end()) {
        batterySaveMode = it->second;
        set_batterySaveMode = savemode;
    }
    else {
        std::cout << "未能匹配" << std::endl;
    }
    return *this;
}
//驾驶模式
std::map<std::string, ElectricCarSettings::DriveMode> ElectricCarSettings::driveModeMap = {
    {"纯电动", DriveMode::PureElectric},
    {"混合动力", DriveMode::Hybrid}
};

ElectricCarSettings& ElectricCarSettings::setDriveMode(const std::string& mode) {
    auto it = driveModeMap.find(mode);
    if (it != driveModeMap.end()) {
        driveMode = it->second;
        set_driveMode = mode;
    }
    else {
        std::cout << "未能匹配" << std::endl;
    }
    return *this;
}
//能量回收模式
std::map<std::string, ElectricCarSettings::EnergyRecoveryMode> ElectricCarSettings::energyRecoveryModeMap = {
    {"高", EnergyRecoveryMode::High},
    {"低", EnergyRecoveryMode::Low},
    {"关闭", EnergyRecoveryMode::Off}
};

ElectricCarSettings& ElectricCarSettings::setEnergyRecoveryMode(const std::string& mode) {
    auto it = energyRecoveryModeMap.find(mode);
    if (it != energyRecoveryModeMap.end()) {
        energyRecoveryMode = it->second;
        set_energyRecoveryMode = mode;
    }
    else {
        std::cout << "未能匹配" << std::endl;
    }
    return *this;
}
//充电计划

std::map<std::string, ElectricCarSettings::ChargingPlan> ElectricCarSettings::chargingPlanMap = {
    {"即时充电", ChargingPlan::Immediate},
    {"定时充电", ChargingPlan::Scheduled}
};

ElectricCarSettings& ElectricCarSettings::setChargingPlan(const std::string& plan) {
    auto it = chargingPlanMap.find(plan);
    if (it != chargingPlanMap.end()) {
        chargingPlan = it->second;
        set_chargingPlan = plan;
    }
    else {
        std::cout << "未能匹配" << std::endl;
    }
    return *this;
}
//电池温度管理
std::map<std::string, ElectricCarSettings::TemperatureManagement> ElectricCarSettings::temperatureManagementMap = {
    {"主动", TemperatureManagement::Active},
    {"被动", TemperatureManagement::Passive}
};

ElectricCarSettings& ElectricCarSettings::setBatteryTemperatureManagement(const std::string& management) {
    auto it = temperatureManagementMap.find(management);
    if (it != temperatureManagementMap.end()) {
        batteryTemperatureManagement = it->second;
        set_batteryTemperatureManagement = management;
    }
    else {
        std::cout << "未能匹配" << std::endl;
    }
    return *this;
}
//数字参数函数实现：
// 设置数字参数的函数实现
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
    std::cout << "电动车设置" << std::endl;
    std::cout << "充电模式: " << set_chargingMode  << std::endl;
    std::cout << "充电连接器: " << set_connectorType << std::endl;
    std::cout << "电池保存模式: " << set_batterySaveMode << std::endl;
    std::cout << "驾驶模式: " << set_driveMode << std::endl;
    std::cout << "能量回收模式： " << set_energyRecoveryMode << std::endl;
    std::cout << "充电计划: " << set_chargingPlan << std::endl;
    std::cout << "电池温度管理: " << set_batteryTemperatureManagement << std::endl;

    std::cout << "预热/预冷设定时间: " << preHeatCoolSettingTime <<"分钟"<< std::endl;
    std::cout << "预热/预冷目标温度: " << preHeatCoolTargetTemperature << "摄氏度" << std::endl;
    std::cout << "最大行驶速度设定: " << maxDrivingSpeedLimit << "千米/时" << std::endl;
    std::cout << "音响音量调节: " << volumeAdjustment << "%" << std::endl;
}