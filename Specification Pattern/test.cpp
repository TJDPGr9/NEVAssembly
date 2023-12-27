#include "specifications.hpp"
#include "CarPart.h"
#include <vector>
#include <iostream>

void display(std::vector<std::shared_ptr<CarPart>> parts)
{
    for (const auto& part : parts) {
        if (part->getName() == "Battery") {
            auto battery = std::dynamic_pointer_cast<Battery>(part);
            std::cout << "Battery (Capacity: " << battery->getCapacity() << ", Components: " << battery->getComponents() <<", Available Numbers: "<<battery->getAvailableNums()<< ")" << std::endl;
        }
        else if (part->getName() == "Motor") {
            auto motor = std::dynamic_pointer_cast<Motor>(part);
            std::cout << "Motor (MaxPower: " << motor->getPower() << ",MaxTorque: " << motor->getTorque() <<", Available Numbers: "<<motor->getAvailableNums()<< ")" << std::endl;
        }
    }
}

int main()
{
    // Create some parts
    auto battery1 = std::make_shared<Battery>(43,"FeLiO4P",0);
    auto battery2 = std::make_shared<Battery>(18, "FeLiO4P", 200);
    auto battery3 = std::make_shared<Battery>(72, "FeLiO4P", 8);
    auto battery4 = std::make_shared<Battery>(87, "FeLiO4P", 100);
    auto motor1 = std::make_shared<Motor>(310, 150, 0);
    auto motor2 = std::make_shared<Motor>(125, 55, 150);
    auto motor3 = std::make_shared<Motor>(250, 150, 50);

    // Define specifications
    BatteryCapacitySpecification highCapacityBatterySpec(70);
    MotorPowerSpecification highPowerMotorSpec(100);
    AvailableSpecification AvailableSpec(1);

    // Use composite specification
    auto highCapacityBatteryOrHighTorqueMotorSpec = highCapacityBatterySpec.Or(highPowerMotorSpec)->And(AvailableSpec);

    // Search for parts
    std::vector<std::shared_ptr<CarPart>> availableParts = { battery1, battery2,battery3,battery4,motor1,motor2,motor3 };
    std::vector<std::shared_ptr<CarPart>> selectedParts;

    for (const auto& part : availableParts) {
        if (highCapacityBatteryOrHighTorqueMotorSpec->IsSatisfiedBy(part)) {
            selectedParts.push_back(part);
        }
    }

    // Display all parts
    std::cout << "All Parts:" << std::endl;
    display(availableParts);

    // Display selected parts
    std::cout << "Selected Parts:" << std::endl;
    display(selectedParts);

    return 0;
}