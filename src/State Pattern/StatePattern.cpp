#include "StatePattern.h"
namespace State {
    int test() {
        State_Car::Car car;

        // 模拟汽车组装和质检
        while (typeid(*car.currentState) != typeid(PassInspectionState)) {
            cout << "The current state: " << car.getStateName() << "\n";
            car.inspect();
        }
        cout << "The current state: " << car.getStateName() << "\n";
        car.inspect();

        return 0;
    }
}