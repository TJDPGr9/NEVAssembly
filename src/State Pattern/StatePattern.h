#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

namespace State_Car {
    class Car;
}

// State interface
class InspectionState {
public:
    virtual void inspect(State_Car::Car& car) = 0;
    virtual string getStateName() const = 0;
};

// State definitions

// Not inspected state
class NotInspectedState : public InspectionState {
public:
    void inspect(State_Car::Car& car) override;
    string getStateName() const override {
        return "Not Inspected";
    }
};

// Module inspection state
class ModuleInspectionState : public InspectionState {
private:
    string moduleName;

public:
    ModuleInspectionState(string module) : moduleName(module) {}

    void inspect(State_Car::Car& car) override;
    string getStateName() const override {
        return "Module Inspection - " + moduleName;
    }
};

// Pass inspection state
class PassInspectionState : public InspectionState {
public:
    void inspect(State_Car::Car& car) override;
    string getStateName() const override {
        return "Pass";
    }
};

// Fail inspection state
class FailInspectionState : public InspectionState {
public:
    void inspect(State_Car::Car& car) override;
    string getStateName() const override {
        return "Fail";
    }
};

// Car class
class State_Car::Car {
public:
    InspectionState* currentState;
    vector<string> modules; // Store names of all modules
    size_t currentModuleIndex;        // Current module index undergoing inspection

public:
    Car() : currentState(new NotInspectedState()), currentModuleIndex(0) {
        // Initialize all modules
        modules = {
            "Engine", "Transmission System", "Chassis", "Electrical System", "Fuel System",
            "Cooling System", "Air Conditioning and Heating System", "Body", "Interior", "Safety System",
            "Communication and Entertainment System"
        };
    }

    void setState(InspectionState* state) {
        delete currentState;
        currentState = state;
    }

    void inspect() {
        currentState->inspect(*this);
    }

    string getCurrentModuleName() const {
        return modules[currentModuleIndex];
    }

    size_t getCurrentModuleIndex() const {
        return currentModuleIndex;
    }

    size_t getModuleCount() const {
        return modules.size();
    }

    string getStateName() const {
        return currentState->getStateName();
    }
};

// State implementations

// Not inspected state implementation
void NotInspectedState::inspect(State_Car::Car& car) {
    cout << "Assembling the car...\n";
    this_thread::sleep_for(chrono::seconds(2));
    // Simulate inspecting each module one by one
    car.setState(new ModuleInspectionState(car.getCurrentModuleName()));
}

// Module inspection state implementation
void ModuleInspectionState::inspect(State_Car::Car& car) {
    string result;
    cout << car.getStateName() << "\n";
    cout << "Enter inspection result (Y for Pass, N for Fail): ";
    cin >> result;

    if (result == "Y" || result == "y") {
        cout << car.getCurrentModuleName() << " module inspection passed!\n";
        car.currentModuleIndex++;
        if (car.getCurrentModuleIndex() < car.getModuleCount()) {
            // More modules to inspect, continue
            car.setState(new ModuleInspectionState(car.getCurrentModuleName()));
        }
        else {
            // All modules passed inspection, enter pass state
            car.setState(new PassInspectionState());
        }
    }
    else {
        cout << car.getCurrentModuleName() << " module inspection failed, car enters fail state.\n";
        car.setState(new FailInspectionState());
    }
    this_thread::sleep_for(chrono::seconds(2));
}

// Pass inspection state implementation
void PassInspectionState::inspect(State_Car::Car& car) {
    cout << "Car has passed all inspections and is in a pass state.\n";
    this_thread::sleep_for(chrono::seconds(2));
}

// Fail inspection state implementation
void FailInspectionState::inspect(State_Car::Car& car) {
    cout << "Car did not pass inspections and is in a fail state.\n";
    this_thread::sleep_for(chrono::seconds(2));

    string result;
    cout << "Would you like to reinspect the current module? (Y for Yes, N for No): ";
    cin >> result;

    if (result == "Y" || result == "y") {
        // Reinspect the current module
        car.setState(new ModuleInspectionState(car.getCurrentModuleName()));
    }
    else {
        // End inspection, switch to fail state
        cout << "End of inspection, car remains in a fail state.\n";
        car.setState(new FailInspectionState());
    }
}
