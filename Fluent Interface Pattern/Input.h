#pragma once
// Input.h
#ifndef INPUT_H
#define INPUT_H
#include "FluentInterface.h"
#include <iostream>
#include <string>

class Input {
public:
    static std::string selectChargingMode();
    static std::string selectConnectorType();
    static std::string selectBatterySaveMode();
    static std::string selectDriveMode();
    static std::string selectEnergyRecoveryMode();
    static std::string selectChargingPlan();
    static std::string selectBatteryTemperatureManagement();

    // 添加数字参数的选择函数
    static int selectPreheatCoolSettingTime();
    static int selectPreheatCoolTargetTemperature();
    static int selectMaxDrivingSpeedLimit();
    static int selectVolumeAdjustment();
};

#endif // INPUT_H
