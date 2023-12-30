#pragma once
#include <string>

#define MAXCAPACITY 10000 //kWh
#define MAXPOWER 3000  //kW
#define MAXTORQUE 1000 //Nm

// CarPart Interface
class CarPart {
public:
    virtual ~CarPart() = default;
    virtual std::string getName() const = 0;
    virtual int getAvailableNums() const = 0;
};

// Concrete Battery Class
class Battery : public CarPart {
public:
    explicit Battery(int capacity, std::string components, int availableNums) : capacity(capacity), components(components), availableNums(availableNums), name("Battery") {}

    std::string getName() const override {
        return name;
    }

    int getCapacity() const{
        return capacity;
    }

    std::string getComponents() const {
        return components;
    }

    int getAvailableNums() const override {
        return availableNums;
    }

private:
    std::string name;
    int availableNums;
    int capacity;
    std::string components;
};

// Concrete Motor Class
class Motor : public CarPart {
public:
    explicit Motor(int maxTorque, int maxPower, int availableNums) : maxTorque(maxTorque), maxPower(maxPower), availableNums(availableNums), name("Motor") {}

    std::string getName() const override {
        return name;
    }

    int getAvailableNums() const override {
        return availableNums;
    }

    int getTorque() const {
        return maxTorque;
    }

    int getPower() const {
        return maxPower;
    }

private:
    std::string name;
    int availableNums;
    int maxTorque; //最大扭矩
    int maxPower;  //最大功率
};
