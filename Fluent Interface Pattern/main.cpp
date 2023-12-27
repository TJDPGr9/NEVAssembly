#include "FluentInterface.h"
#include "Input.h"
#ifdef _WIN32
#include<Windows.h>
#endif
namespace FluentInterface {
    int test() {
#ifdef _WIN32
        SetConsoleOutputCP(936);
        SetConsoleCP(936);
#endif
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
}