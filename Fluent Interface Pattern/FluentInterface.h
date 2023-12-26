#pragma once
#ifndef ELECTRIC_CAR_SETTINGS_H
#define ELECTRIC_CAR_SETTINGS_H
#include "Input.h"
#include <iostream>
#include <string>
#include <map>
class ElectricCarSettings {
    friend class Input; // ���� Input ��Ϊ��Ԫ
private:
    

    //���ģʽ
    enum class ChargingMode { Fast, Slow };
    ChargingMode chargingMode;
    static std::map<std::string, ChargingMode> chargingModeMap;
    std::string set_chargingMode;
    //������
    enum class ConnectorType { DC_FastCharger, AC_HomeCharger };
    ConnectorType connectorType;
    static std::map<std::string, ConnectorType> connectorTypeMap;
    std::string set_connectorType;
    //��ر���ģʽ
    enum class BatterySaveMode { Enabled, Disabled };
    BatterySaveMode batterySaveMode;
    static std::map<std::string, BatterySaveMode> batterySaveModeMap;
    std::string set_batterySaveMode;
    //��ʻģʽ
    enum class DriveMode { PureElectric, Hybrid };
    DriveMode driveMode;
    static std::map<std::string, DriveMode> driveModeMap;
    std::string set_driveMode;
    //��������ģʽ
    enum class EnergyRecoveryMode { High, Low, Off };
    EnergyRecoveryMode energyRecoveryMode;
    static std::map<std::string, EnergyRecoveryMode> energyRecoveryModeMap;
    std::string set_energyRecoveryMode;
    //���ƻ�
    enum class ChargingPlan { Immediate, Scheduled };
    ChargingPlan chargingPlan;
    static std::map<std::string, ChargingPlan> chargingPlanMap;
    std::string set_chargingPlan;
    //����¶ȹ���
    enum class TemperatureManagement { Active, Passive };
    TemperatureManagement batteryTemperatureManagement;
    static std::map<std::string, TemperatureManagement> temperatureManagementMap;
    std::string set_batteryTemperatureManagement;

   
    // ������ֲ���
    int preHeatCoolSettingTime;
    int preHeatCoolTargetTemperature;
    int maxDrivingSpeedLimit;
    int volumeAdjustment;
public:
    ElectricCarSettings();
    //ö�ٲ���
    ElectricCarSettings& setChargingMode(const std::string& mode);
    ElectricCarSettings& setConnectorType(const std::string& type);
    ElectricCarSettings& enableBatterySaveMode(const std::string& savemode);
    ElectricCarSettings& setDriveMode(const std::string& mode);
    ElectricCarSettings& setEnergyRecoveryMode(const std::string& mode);
    ElectricCarSettings& setChargingPlan(const std::string& plan);
    ElectricCarSettings& setBatteryTemperatureManagement(const std::string& management);
    //���ֲ���
    
    ElectricCarSettings& setPreheatCoolSettingTime(int time);
    ElectricCarSettings& setPreheatCoolTargetTemperature(int temperature);
    ElectricCarSettings& setMaxDrivingSpeedLimit(int speedLimit);
    ElectricCarSettings& setVolumeAdjustment(int volume);

    void displaySettings() const;
};

#endif  // ELECTRIC_CAR_SETTINGS_H