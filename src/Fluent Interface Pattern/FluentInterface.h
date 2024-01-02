#pragma once
#ifndef ELECTRIC_CAR_SETTINGS_H
#define ELECTRIC_CAR_SETTINGS_H
#include "Input.h"
#include <iostream>
#include <string>
#include <map>
class ElectricCarSettings {
    friend class Input; 
    

    
    enum class ChargingMode { Fast, Slow };
    ChargingMode chargingMode;
    static std::map<std::string, ChargingMode> chargingModeMap;
    std::string set_chargingMode;
    
    enum class ConnectorType { DC_FastCharger, AC_HomeCharger };
    ConnectorType connectorType;
    static std::map<std::string, ConnectorType> connectorTypeMap;
    std::string set_connectorType;
    
    enum class BatterySaveMode { Enabled, Disabled };
    BatterySaveMode batterySaveMode;
    static std::map<std::string, BatterySaveMode> batterySaveModeMap;
    std::string set_batterySaveMode;
    
    enum class DriveMode { PureElectric, Hybrid };
    DriveMode driveMode;
    static std::map<std::string, DriveMode> driveModeMap;
    std::string set_driveMode;
   
    enum class EnergyRecoveryMode { High, Low, Off };
    EnergyRecoveryMode energyRecoveryMode;
    static std::map<std::string, EnergyRecoveryMode> energyRecoveryModeMap;
    std::string set_energyRecoveryMode;
    
    enum class ChargingPlan { Immediate, Scheduled };
    ChargingPlan chargingPlan;
    static std::map<std::string, ChargingPlan> chargingPlanMap;
    std::string set_chargingPlan;
    
    enum class TemperatureManagement { Active, Passive };
    TemperatureManagement batteryTemperatureManagement;
    static std::map<std::string, TemperatureManagement> temperatureManagementMap;
    std::string set_batteryTemperatureManagement;

   
    
    int preHeatCoolSettingTime;
    static const int minPreHeatCoolTime = 5;
    static const int maxPreHeatCoolTime = 30;
    
    int preHeatCoolTargetTemperature;
    static const int minPreHeatCoolTargetTemp = 16;
    static const int maxPreHeatCoolTargetTemp = 30;

    int maxDrivingSpeedLimit;
    static const int maxSpeedLimit = 300;
    static const int minSpeedLimit = 30;

    int volumeAdjustment;
    static const int minVolume = 0;
    static const int maxVolume = 100;

public:
    ElectricCarSettings();
    
    ElectricCarSettings& setChargingMode(const std::string& mode);
    ElectricCarSettings& setConnectorType(const std::string& type);
    ElectricCarSettings& enableBatterySaveMode(const std::string& savemode);
    ElectricCarSettings& setDriveMode(const std::string& mode);
    ElectricCarSettings& setEnergyRecoveryMode(const std::string& mode);
    ElectricCarSettings& setChargingPlan(const std::string& plan);
    ElectricCarSettings& setBatteryTemperatureManagement(const std::string& management);
    
    ElectricCarSettings& setPreheatCoolSettingTime(int time);
    ElectricCarSettings& setPreheatCoolTargetTemperature(int temperature);
    ElectricCarSettings& setMaxDrivingSpeedLimit(int speedLimit);
    ElectricCarSettings& setVolumeAdjustment(int volume);

    void displaySettings() const;
};

#endif  // ELECTRIC_CAR_SETTINGS_H