// Input.cpp
#include "Input.h"

std::string Input::selectChargingMode() {
    std::vector<std::string> chargingModes;
    for (const auto& pair : ElectricCarSettings::chargingModeMap) {
        chargingModes.push_back(pair.first);
    }

    std::cout << "请选择充电模式：" << std::endl;

    for (size_t i = 0; i < chargingModes.size(); ++i) {
        std::cout << i + 1 << " - " << chargingModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "请输入选择的充电模式编号：";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(chargingModes.size())) {
        std::cout << "请输入有效的充电模式编号：";
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

    std::cout << "请选择充电连接器：" << std::endl;

    for (size_t i = 0; i < connectorTypes.size(); ++i) {
        std::cout << i + 1 << " - " << connectorTypes[i] << std::endl;
    }

    int userChoice;
    std::cout << "请输入选择的充电连接器编号：";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(connectorTypes.size())) {
        std::cout << "请输入有效的充电连接器编号：";
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
    std::cout << "请选择电池保存模式：" << std::endl;

    for (size_t i = 0; i < batterySaveModes.size(); ++i) {
        std::cout << i + 1 << " - " << batterySaveModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "请输入选择的电池保存模式编号：";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(batterySaveModes.size())) {
        std::cout << "请输入有效的电池保存模式编号：";
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
    std::cout << "请选择驾驶模式：" << std::endl;

    for (size_t i = 0; i < driveModes.size(); ++i) {
        std::cout << i + 1 << " - " << driveModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "请输入选择的驾驶模式编号：";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(driveModes.size())) {
        std::cout << "请输入有效的驾驶模式编号：";
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
    std::cout << "请选择能量回收模式：" << std::endl;

    for (size_t i = 0; i < energyRecoveryModes.size(); ++i) {
        std::cout << i + 1 << " - " << energyRecoveryModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "请输入选择的能量回收模式编号：";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(energyRecoveryModes.size())) {
        std::cout << "请输入有效的能量回收模式编号：";
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
    std::cout << "请选择充电计划：" << std::endl;

    for (size_t i = 0; i < chargingPlans.size(); ++i) {
        std::cout << i + 1 << " - " << chargingPlans[i] << std::endl;
    }

    int userChoice;
    std::cout << "请输入选择的充电计划编号：";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(chargingPlans.size())) {
        std::cout << "请输入有效的充电计划编号：";
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
    std::cout << "请选择电池温度管理：" << std::endl;

    for (size_t i = 0; i < batteryTemperatureManagements.size(); ++i) {
        std::cout << i + 1 << " - " << batteryTemperatureManagements[i] << std::endl;
    }

    int userChoice;
    std::cout << "请输入选择的电池温度管理编号：";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(batteryTemperatureManagements.size())) {
        std::cout << "请输入有效的电池温度管理编号：";
        std::cin >> userChoice;
    }
    std::cout << std::endl;
    return batteryTemperatureManagements[userChoice - 1];
}



//数字参数输入
int Input::selectPreHeatCoolSettingTime() {
    std::cout << "请输入预热/预冷设定时间 (范围：" << ElectricCarSettings::minPreHeatCoolTime << " - " << ElectricCarSettings::maxPreHeatCoolTime << ", 单位：分钟，): ";
    int time;
    std::cin >> time;

    while (time < ElectricCarSettings::minPreHeatCoolTime || time > ElectricCarSettings::maxPreHeatCoolTime || std::cin.fail()) {
        std::cout << "请输入有效的预热/预冷设定时间 (范围：" << ElectricCarSettings::minPreHeatCoolTime << " - " << ElectricCarSettings::maxPreHeatCoolTime << ", 单位：分钟，): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> time;
    }
    std::cout << std::endl;
    return time;
}

int Input::selectPreHeatCoolTargetTemperature() {
    std::cout << "请输入预热/预冷目标温度 (范围：" << ElectricCarSettings::minPreHeatCoolTargetTemp << " - " << ElectricCarSettings::maxPreHeatCoolTargetTemp << "，单位：摄氏度): ";
    int temperature;
    std::cin >> temperature;

    while (temperature < ElectricCarSettings::minPreHeatCoolTargetTemp || temperature > ElectricCarSettings::maxPreHeatCoolTargetTemp || std::cin.fail()) {
        std::cout << "请输入有效的预热/预冷目标温度 (范围：" << ElectricCarSettings::minPreHeatCoolTargetTemp << " - " << ElectricCarSettings::maxPreHeatCoolTargetTemp << "，单位：摄氏度): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> temperature;
    }
    std::cout << std::endl;
    return temperature;
}

int Input::selectMaxDrivingSpeedLimit() {
    std::cout << "请输入最大行驶速度限制 (范围：" << ElectricCarSettings::minSpeedLimit << " - " << ElectricCarSettings::maxSpeedLimit << "，单位：千米/时): ";
    int speedLimit;
    std::cin >> speedLimit;

    while (speedLimit < ElectricCarSettings::minSpeedLimit || speedLimit > ElectricCarSettings::maxSpeedLimit || std::cin.fail()) {
        std::cout << "请输入有效的最大行驶速度限制 (范围" << ElectricCarSettings::minSpeedLimit << " - " << ElectricCarSettings::maxSpeedLimit << "，单位：千米/时): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> speedLimit;
    }
    std::cout << std::endl;
    return speedLimit;
}

int Input::selectVolumeAdjustment() {
    std::cout << "请输入音量调节 (范围：" << ElectricCarSettings::minVolume << " - " << ElectricCarSettings::maxVolume << "，单位：%): ";
    int volume;
    std::cin >> volume;

    while (volume < ElectricCarSettings::minVolume || volume > ElectricCarSettings::maxVolume || std::cin.fail()) {
        std::cout << "请输入有效的音量调节 (范围：" << ElectricCarSettings::minVolume << " - " << ElectricCarSettings::maxVolume << "，单位：%): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> volume;
    }
    std::cout << std::endl;
    return volume;
}