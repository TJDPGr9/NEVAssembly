#pragma once
#ifndef ELECTRIC_CAR_SETTINGS_H
#define ELECTRIC_CAR_SETTINGS_H
#include "Input.h"
#include <iostream>
#include <string>
#include <map>
class ElectricCarSettings {
    friend class Input; // 声明 Input 类为友元
private:
    

    //充电模式
    enum class ChargingMode { Fast, Slow };
    ChargingMode chargingMode;
    static std::map<std::string, ChargingMode> chargingModeMap;
    std::string set_chargingMode;
    //连接器
    enum class ConnectorType { DC_FastCharger, AC_HomeCharger };
    ConnectorType connectorType;
    static std::map<std::string, ConnectorType> connectorTypeMap;
    std::string set_connectorType;
    //电池保存模式
    enum class BatterySaveMode { Enabled, Disabled };
    BatterySaveMode batterySaveMode;
    static std::map<std::string, BatterySaveMode> batterySaveModeMap;
    std::string set_batterySaveMode;
    //驾驶模式
    enum class DriveMode { PureElectric, Hybrid };
    DriveMode driveMode;
    static std::map<std::string, DriveMode> driveModeMap;
    std::string set_driveMode;
    //能量回收模式
    enum class EnergyRecoveryMode { High, Low, Off };
    EnergyRecoveryMode energyRecoveryMode;
    static std::map<std::string, EnergyRecoveryMode> energyRecoveryModeMap;
    std::string set_energyRecoveryMode;
    //充电计划
    enum class ChargingPlan { Immediate, Scheduled };
    ChargingPlan chargingPlan;
    static std::map<std::string, ChargingPlan> chargingPlanMap;
    std::string set_chargingPlan;
    //电池温度管理
    enum class TemperatureManagement { Active, Passive };
    TemperatureManagement batteryTemperatureManagement;
    static std::map<std::string, TemperatureManagement> temperatureManagementMap;
    std::string set_batteryTemperatureManagement;

   
    // 添加数字参数
    int preHeatCoolSettingTime;
    int preHeatCoolTargetTemperature;
    int maxDrivingSpeedLimit;
    int volumeAdjustment;
public:
    ElectricCarSettings();
    //枚举参数
    ElectricCarSettings& setChargingMode(const std::string& mode);
    ElectricCarSettings& setConnectorType(const std::string& type);
    ElectricCarSettings& enableBatterySaveMode(const std::string& savemode);
    ElectricCarSettings& setDriveMode(const std::string& mode);
    ElectricCarSettings& setEnergyRecoveryMode(const std::string& mode);
    ElectricCarSettings& setChargingPlan(const std::string& plan);
    ElectricCarSettings& setBatteryTemperatureManagement(const std::string& management);
    //数字参数
    
    ElectricCarSettings& setPreheatCoolSettingTime(int time);
    ElectricCarSettings& setPreheatCoolTargetTemperature(int temperature);
    ElectricCarSettings& setMaxDrivingSpeedLimit(int speedLimit);
    ElectricCarSettings& setVolumeAdjustment(int volume);

    void displaySettings() const;
};

#endif  // ELECTRIC_CAR_SETTINGS_H