// Input.cpp
#include "Input.h"

std::string Input::selectChargingMode() {
    std::vector<std::string> chargingModes;
    for (const auto& pair : ElectricCarSettings::chargingModeMap) {
        chargingModes.push_back(pair.first);
    }

    std::cout << "Please select the charging mode:" << std::endl;

    for (size_t i = 0; i < chargingModes.size(); ++i) {
        std::cout << i + 1 << " - " << chargingModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "Please enter the selected charging mode number:";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(chargingModes.size())) {
        std::cout << "Please enter a valid charging mode number:";
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

    std::cout << "Please select a charging connector:" << std::endl;

    for (size_t i = 0; i < connectorTypes.size(); ++i) {
        std::cout << i + 1 << " - " << connectorTypes[i] << std::endl;
    }

    int userChoice;
    std::cout << "Please enter the selected charging connector number:";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(connectorTypes.size())) {
        std::cout << "Please enter a valid charging connector number:";
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
    std::cout << "Please select battery save mode:" << std::endl;

    for (size_t i = 0; i < batterySaveModes.size(); ++i) {
        std::cout << i + 1 << " - " << batterySaveModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "Please enter the selected battery save mode number:";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(batterySaveModes.size())) {
        std::cout << "Please enter a valid battery save mode number:";
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
    std::cout << "Please select driving mode:" << std::endl;

    for (size_t i = 0; i < driveModes.size(); ++i) {
        std::cout << i + 1 << " - " << driveModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "Please enter the selected driving mode number:";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(driveModes.size())) {
        std::cout << "Please enter a valid driving mode number:";
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
    std::cout << "Please select the energy recovery mode:" << std::endl;

    for (size_t i = 0; i < energyRecoveryModes.size(); ++i) {
        std::cout << i + 1 << " - " << energyRecoveryModes[i] << std::endl;
    }

    int userChoice;
    std::cout << "Please enter the selected energy recovery mode number:";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(energyRecoveryModes.size())) {
        std::cout << "Please enter a valid energy recovery mode number:";
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
    std::cout << "Please select a charging plan:" << std::endl;

    for (size_t i = 0; i < chargingPlans.size(); ++i) {
        std::cout << i + 1 << " - " << chargingPlans[i] << std::endl;
    }

    int userChoice;
    std::cout << "Please enter the selected charging plan number:";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(chargingPlans.size())) {
        std::cout << "Please enter a valid charging plan number:";
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
    std::cout << "Please select battery temperature management:" << std::endl;

    for (size_t i = 0; i < batteryTemperatureManagements.size(); ++i) {
        std::cout << i + 1 << " - " << batteryTemperatureManagements[i] << std::endl;
    }

    int userChoice;
    std::cout << "Please enter the selected battery temperature management number:";
    std::cin >> userChoice;

    while (userChoice < 1 || userChoice > static_cast<int>(batteryTemperatureManagements.size())) {
        std::cout << "Please enter a valid battery temperature management number:";
        std::cin >> userChoice;
    }
    std::cout << std::endl;
    return batteryTemperatureManagements[userChoice - 1];
}



//数字参数输入
int Input::selectPreHeatCoolSettingTime() {
    std::cout << "Please enter the preheating/pre cooling setting time (Scope:" << ElectricCarSettings::minPreHeatCoolTime << " - " << ElectricCarSettings::maxPreHeatCoolTime << " minutes): ";
    int time;
    std::cin >> time;

    while (time < ElectricCarSettings::minPreHeatCoolTime || time > ElectricCarSettings::maxPreHeatCoolTime || std::cin.fail()) {
        std::cout << "Please enter a valid preheating/pre cooling setting time (Scope:" << ElectricCarSettings::minPreHeatCoolTime << " - " << ElectricCarSettings::maxPreHeatCoolTime << " minutes): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> time;
    }
    std::cout << std::endl;
    return time;
}

int Input::selectPreHeatCoolTargetTemperature() {
    std::cout << "Please enter the target temperature for preheating/pre cooling (Scope:" << ElectricCarSettings::minPreHeatCoolTargetTemp << " - " << ElectricCarSettings::maxPreHeatCoolTargetTemp << " °C): ";
    int temperature;
    std::cin >> temperature;

    while (temperature < ElectricCarSettings::minPreHeatCoolTargetTemp || temperature > ElectricCarSettings::maxPreHeatCoolTargetTemp || std::cin.fail()) {
        std::cout << "Please enter a valid preheating/precooling target temperature (Scope:" << ElectricCarSettings::minPreHeatCoolTargetTemp << " - " << ElectricCarSettings::maxPreHeatCoolTargetTemp << " °C): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> temperature;
    }
    std::cout << std::endl;
    return temperature;
}

int Input::selectMaxDrivingSpeedLimit() {
    std::cout << "Please enter the maximum driving speed limit (Scope:" << ElectricCarSettings::minSpeedLimit << " - " << ElectricCarSettings::maxSpeedLimit << " km/h): ";
    int speedLimit;
    std::cin >> speedLimit;

    while (speedLimit < ElectricCarSettings::minSpeedLimit || speedLimit > ElectricCarSettings::maxSpeedLimit || std::cin.fail()) {
        std::cout << "Please enter a valid maximum driving speed limit (Scope:" << ElectricCarSettings::minSpeedLimit << " - " << ElectricCarSettings::maxSpeedLimit << " km/h): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> speedLimit;
    }
    std::cout << std::endl;
    return speedLimit;
}

int Input::selectVolumeAdjustment() {
    std::cout << "Please enter volume adjustment (Scope:" << ElectricCarSettings::minVolume << " - " << ElectricCarSettings::maxVolume << " %): ";
    int volume;
    std::cin >> volume;

    while (volume < ElectricCarSettings::minVolume || volume > ElectricCarSettings::maxVolume || std::cin.fail()) {
        std::cout << "Please enter a valid volume adjustment (Scope:" << ElectricCarSettings::minVolume << " - " << ElectricCarSettings::maxVolume << " %): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> volume;
    }
    std::cout << std::endl;
    return volume;
}   