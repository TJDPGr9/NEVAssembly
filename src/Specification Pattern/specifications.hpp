#pragma once

#include "specification_template.hpp"
#include "CarPart.hpp"
#include <memory>

// Concrete Specification for Battery Capacity
class BatteryCapacitySpecification final: public CompositeSpecification<CarPart> {
public:
	explicit BatteryCapacitySpecification(int minCapacity = 0, int maxCapacity = MAXCAPACITY)
        : minCapacity(minCapacity), maxCapacity(maxCapacity) {}

    bool IsSatisfiedBy(const std::shared_ptr<CarPart>& part) const override {
        if (part->getName() == "Battery") {
            auto battery = std::dynamic_pointer_cast<Battery>(part);
            return battery->getCapacity() >= minCapacity && battery->getCapacity() <= maxCapacity;
        }
        return false;
    }

private:
    int minCapacity;
    int maxCapacity;
};

// Concrete Specification for Battery Components
class BatteryComponentsSpecification final: public CompositeSpecification<CarPart> {
public:
    explicit BatteryComponentsSpecification(std::string components)
        : components(components) {}

    bool IsSatisfiedBy(const std::shared_ptr<CarPart>& part) const override {
        if (part->getName() == "Battery") {
            auto battery = std::dynamic_pointer_cast<Battery>(part);
            return battery->getComponents() == components;
        }
        return false;
    }

private:
    std::string components;
};

// Concrete Specification for Motor Torque
class MotorTorqueSpecification final: public CompositeSpecification<CarPart> {
public:
    explicit MotorTorqueSpecification(int minTorque=0, int maxTorque=MAXTORQUE) : minTorque(minTorque),maxTorque(maxTorque) {}

    bool IsSatisfiedBy(const std::shared_ptr<CarPart>& part) const override {
        if (part->getName() == "Motor") {
            auto motor = std::dynamic_pointer_cast<Specification::Motor>(part);
            return motor->getTorque() >= minTorque && motor->getTorque() <= maxTorque;
        }
        return false;
    }

private:
    int minTorque;
    int maxTorque;
};

// Concrete Specification for Motor Power
class MotorPowerSpecification final: public CompositeSpecification<CarPart> {
public:
    explicit MotorPowerSpecification(int minPower = 0, int maxPower = MAXPOWER) : minPower(minPower), maxPower(maxPower) {}

    bool IsSatisfiedBy(const std::shared_ptr<CarPart>& part) const override {
        if (part->getName() == "Motor") {
            auto motor = std::dynamic_pointer_cast<Specification::Motor>(part);
            return motor->getPower() >= minPower && motor->getPower() <= maxPower;
        }
        return false;
    }

private:
    int minPower;
    int maxPower;
};

// Concrete Specification for Available Nums
class AvailableSpecification : public CompositeSpecification<CarPart> {
public:
    explicit AvailableSpecification(int minAvailableNums) : minAvailableNums(minAvailableNums) {}

    bool IsSatisfiedBy(const std::shared_ptr<CarPart>& part) const override {
        return part->getAvailableNums() >= minAvailableNums;
    }

private:
    int minAvailableNums;
};
