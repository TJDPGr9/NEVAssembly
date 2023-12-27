#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;
namespace State_Car {
    class Car;
}
// 状态接口
class InspectionState {
public:
    virtual void inspect(State_Car::Car& car) = 0;
    virtual string getStateName() const = 0;
};
// 状态定义
// 未检验状态
class NotInspectedState : public InspectionState {
public:
    void inspect(State_Car::Car& car) override;
    string getStateName() const override {
        return "未检验";
    }
};
// 模块质检状态
class ModuleInspectionState : public InspectionState {
private:
    string moduleName;

public:
    ModuleInspectionState(string module) : moduleName(module) {}

    void inspect(State_Car::Car& car) override;
    string getStateName() const override {
        return "模块质检 - " + moduleName;
    }
};

// 合格状态
class PassInspectionState : public InspectionState {
public:
    void inspect(State_Car::Car& car) override;
    string getStateName() const override {
        return "合格";
    }
};

// 不合格状态
class FailInspectionState : public InspectionState {
public:
    void inspect(State_Car::Car& car) override;
    string getStateName() const override {
        return "不合格";
    }
};
// 汽车类
class State_Car::Car {
public:
    InspectionState* currentState;
    vector<string> modules; // 存储所有模块的名称
    size_t currentModuleIndex;        // 当前进行质检的模块索引

public:
    Car() : currentState(new NotInspectedState()), currentModuleIndex(0) {
        // 初始化所有模块 
        modules = {
            "引擎", "传动系统", "底盘", "电气系统", "燃油系统",
            "冷却系统", "空调和暖风系统", "车身", "内饰", "安全系统",
            "通信和娱乐系统"
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












// 状态实现

// 未检验状态实现
void NotInspectedState::inspect(State_Car::Car& car) {
    cout << "开始组装汽车...\n";
    this_thread::sleep_for(chrono::seconds(2));
    // 模拟逐个模块进行质检
    car.setState(new ModuleInspectionState(car.getCurrentModuleName()));
}

// 模块质检状态实现
void ModuleInspectionState::inspect(State_Car::Car& car) {
    string result;
    cout << car.getStateName() << "\n";
    cout << "请输入质检结果 (Y代表合格，N代表不合格): ";
    cin >> result;

    if (result == "Y" || result == "y") {
        cout << car.getCurrentModuleName() << " 模块质检通过！\n";
        car.currentModuleIndex++;
        if (car.getCurrentModuleIndex() < car.getModuleCount()) {
            // 还有模块需要质检，继续
            car.setState(new ModuleInspectionState(car.getCurrentModuleName()));
        }
        else {
            // 所有模块质检通过，进入合格状态
            car.setState(new PassInspectionState());
        }
    }
    else {
        cout << car.getCurrentModuleName() << " 模块质检不通过，汽车进入不合格状态。\n";
        car.setState(new FailInspectionState());
    }
    this_thread::sleep_for(chrono::seconds(2));
}

// 合格状态实现
void PassInspectionState::inspect(State_Car::Car& car) {
    cout << "汽车已通过所有质检，为合格状态。\n";
    this_thread::sleep_for(chrono::seconds(2));
}

// 不合格状态实现
void FailInspectionState::inspect(State_Car::Car& car) {
    cout << "汽车未通过质检，为不合格状态。\n";
    this_thread::sleep_for(chrono::seconds(2));

    string result;
    cout << "是否重新检测当前模块？(Y代表重新检测，N代表结束): ";
    cin >> result;

    if (result == "Y" || result == "y") {
        // 重新检测当前模块
        car.setState(new ModuleInspectionState(car.getCurrentModuleName()));
    }
    else {
        // 结束质检，切换到不合格状态
        cout << "结束质检，汽车仍为不合格状态。\n";
        car.setState(new FailInspectionState());
    }
}
