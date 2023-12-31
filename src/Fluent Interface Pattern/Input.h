#pragma once
// Input.h
#ifndef INPUT_H
#define INPUT_H
#include "FluentInterface.h"
#include <iostream>
#include <string>
#include <vector>
class Input {
public:
    static std::string selectChargingMode();
    static std::string selectConnectorType();
    static std::string selectBatterySaveMode();
    static std::string selectDriveMode();
    static std::string selectEnergyRecoveryMode();
    static std::string selectChargingPlan();
    static std::string selectBatteryTemperatureManagement();

   
    static int selectPreHeatCoolSettingTime();
    static int selectPreHeatCoolTargetTemperature();
    static int selectMaxDrivingSpeedLimit();
    static int selectVolumeAdjustment();
};

#endif // INPUT_H
