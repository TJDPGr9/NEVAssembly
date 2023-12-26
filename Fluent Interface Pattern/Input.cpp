// Input.cpp
#include "Input.h"

std::string Input::selectChargingMode() {
    std::string chargingMode;
    std::cout << "请选择充电模式 (1 - 快充, 2 - 慢充): ";
    std::cin >> chargingMode;

    while (chargingMode != "1" && chargingMode != "2") {
        std::cout << "请输入有效的充电模式 (1 - 快充, 2 - 慢充): ";
        std::cin >> chargingMode;
    }

    return (chargingMode=="1" ? "快充" : "慢充");
}

std::string Input::selectConnectorType() {
    std::string connectorType;
    std::cout << "请选择充电连接器 (1 - 直流快速充电连接器, 2 - 交流家用充电连接器): ";
    std::cin >> connectorType;

    while (connectorType != "1" && connectorType != "2") {
        std::cout << "请输入有效的充电连接器 (1 - 直流快速充电连接器, 2 - 交流家用充电连接器): ";
        std::cin >> connectorType;
    }

    return (connectorType == "1" ? "直流快速充电连接器" : "交流家用充电连接器");
}

std::string Input::selectBatterySaveMode() {
    std::string batterySaveMode;
    std::cout << "请选择电池保存模式 (1 - 启用, 2 - 禁用): ";
    std::cin >> batterySaveMode;

    while (batterySaveMode != "1" && batterySaveMode != "2") {
        std::cout << "请输入有效的电池保存模式 (1 - 启用, 2 - 禁用): ";
        std::cin >> batterySaveMode;
    }

    return (batterySaveMode == "1" ? "启用" : "禁用");

}

std::string Input::selectDriveMode() {
    std::string driveMode;
    std::cout << "请选择驾驶模式 (1 - 纯电动, 2 - 混合动力): ";
    std::cin >> driveMode;

    while (driveMode != "1" && driveMode != "2") {
        std::cout << "请输入有效的驾驶模式 (1 - 纯电动, 2 - 混合动力): ";
        std::cin >> driveMode;
    }

    return (driveMode == "1" ? "纯电动" : "混合动力");
}

std::string Input::selectEnergyRecoveryMode() {
    std::string energyRecoveryMode;
    std::cout << "请选择能量回收模式 (1 - 高, 2 - 低，3 - 关闭): ";
    std::cin >> energyRecoveryMode;

    while (energyRecoveryMode != "1" && energyRecoveryMode != "2" && energyRecoveryMode != "3") {
        std::cout << "请输入有效的能量回收模式 (1 - 高, 2 - 低，3 - 关闭): ";
        std::cin >> energyRecoveryMode;
    }
    if (energyRecoveryMode == "1") {
        return "高";
   }
    else if(energyRecoveryMode == "2"){
        return "低";
    }
    else {
        return "关闭";
    }
   
}

std::string Input::selectChargingPlan() {
    std::string chargingPlan;
    std::cout << "请选择充电计划 (1 - 即时充电, 2 - 定时充电): ";
    std::cin >> chargingPlan;

    while (chargingPlan != "1" && chargingPlan != "2") {
        std::cout << "请输入有效的充电计划 (1 - 即时充电, 2 - 定时充电): ";
        std::cin >> chargingPlan;
    }
    if (chargingPlan == "1") {
        return "即时充电";
    }
    else {
        return "定时充电";
    }
}

std::string Input::selectBatteryTemperatureManagement() {
    std::string batteryTemperatureManagement;
    std::cout << "请选择电池温度管理 (1 - 主动, 2 - 被动): ";
    std::cin >> batteryTemperatureManagement;

    while (batteryTemperatureManagement != "1" && batteryTemperatureManagement != "2") {
        std::cout << "请输入有效的电池温度管理 (1 - 主动, 2 - 被动): ";
        std::cin >> batteryTemperatureManagement;
    }
    if (batteryTemperatureManagement == "1") {
        return "主动";
    }
    else {
        return "被动";
    }
}

//数字参数输入
int Input::selectPreheatCoolSettingTime() {
    int time;
    std::cout << "请输入预热/预冷设定时间 (单位：分钟，大于0): ";
    std::cin >> time;

    while (time <= 0 || std::cin.fail()) {
        std::cout << "请输入有效的预热/预冷设定时间 (单位：分钟，大于0): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> time;
    }

    return time;
}

int Input::selectPreheatCoolTargetTemperature() {
    int temperature;
    std::cout << "请输入预热/预冷目标温度 (范围16-30，单位：摄氏度): ";
    std::cin >> temperature;

    while (temperature < 16 || temperature > 30 || std::cin.fail()) {
        std::cout << "请输入有效的预热/预冷目标温度 (范围16-30，单位：摄氏度): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> temperature;
    }

    return temperature;
}

int Input::selectMaxDrivingSpeedLimit() {
    int speedLimit;
    std::cout << "请输入最大行驶速度限制 (范围30-300，单位：千米/时): ";
    std::cin >> speedLimit;

    while (speedLimit < 30 || speedLimit > 300 || std::cin.fail()) {
        std::cout << "请输入有效的最大行驶速度限制 (范围30-300，单位：千米/时): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> speedLimit;
    }

    return speedLimit;
}

int Input::selectVolumeAdjustment() {
    int volume;
    std::cout << "请输入音量调节 (范围0-100，单位：%): ";
    std::cin >> volume;

    while (volume < 0 || volume > 100 || std::cin.fail()) {
        std::cout << "请输入有效的音量调节 (范围0-100，单位：%): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> volume;
    }

    return volume;
}