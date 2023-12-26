#include "FluentInterface.h"
#include "Input.h"
int main() {
   
   

    ElectricCarSettings settings;
    



    settings
        .setChargingMode(Input::selectChargingMode())
        .setConnectorType(Input::selectConnectorType())
        .enableBatterySaveMode(Input::selectBatterySaveMode())
        .setDriveMode(Input::selectDriveMode())
        .setEnergyRecoveryMode(Input::selectEnergyRecoveryMode())
        .setChargingPlan(Input::selectChargingPlan())
        .setBatteryTemperatureManagement(Input::selectBatteryTemperatureManagement())
        .displaySettings();

    return 0;
}