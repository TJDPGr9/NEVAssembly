#include "FluentInterface.h"
#include "Input.h"
int main() {
   
    ElectricCarSettings settings;
    
    settings
        
        .setVolumeAdjustment(Input::selectVolumeAdjustment())
        .setMaxDrivingSpeedLimit(Input::selectMaxDrivingSpeedLimit())
        .setPreheatCoolTargetTemperature(Input::selectPreHeatCoolTargetTemperature())
        .setPreheatCoolSettingTime(Input::selectPreHeatCoolSettingTime())
       
        .setBatteryTemperatureManagement(Input::selectBatteryTemperatureManagement())
        .setChargingPlan(Input::selectChargingPlan())
        .setEnergyRecoveryMode(Input::selectEnergyRecoveryMode())
        .setDriveMode(Input::selectDriveMode())
        .enableBatterySaveMode(Input::selectBatterySaveMode())
        .setConnectorType(Input::selectConnectorType())
        .setChargingMode(Input::selectChargingMode())
        .displaySettings();

    return 0;
}