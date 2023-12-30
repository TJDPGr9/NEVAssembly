#pragma once
#include <iostream>
using namespace std;

// �������
class NewEnergyCar {
public:
    NewEnergyCar() {}
    virtual ~NewEnergyCar() {}

    virtual void showStatus() = 0;  //�������ӿ�
};

// ����Ԫ����
class BasicNewEnergyCar : public NewEnergyCar {
public:
    BasicNewEnergyCar() {}
    ~BasicNewEnergyCar() {}

    void showStatus() override {
        cout << "Basic New Energy Car" << endl;
    }
};

// ����װ����
class CarDecorator : public NewEnergyCar {
protected:
    NewEnergyCar* carComponent;  //Ҫ��ӵ��������
public:
    CarDecorator(NewEnergyCar* component) : carComponent(component) {}

    virtual void showStatus() override {
        if (carComponent) {   //���ָ��ǿ�
            carComponent->showStatus();
        }
    }
};

// ����װ������
class DashCameraDecorator : public CarDecorator {
public:
    DashCameraDecorator(NewEnergyCar* component) : CarDecorator(component) {}

    void addDashCamera() {
        cout << "Added Dash Camera" << endl;
    }

    void showStatus() override {
        CarDecorator::showStatus();
        addDashCamera();
    }
};

class AirPurifierDecorator : public CarDecorator {
public:
    AirPurifierDecorator(NewEnergyCar* component) : CarDecorator(component) {}

    void addAirPurifier() {
        cout << "Added Air Purifier" << endl;
    }

    void showStatus() override {
        CarDecorator::showStatus();
        addAirPurifier();
    }
};

class AsternCameraDecorator : public CarDecorator {
public:
    AsternCameraDecorator(NewEnergyCar* component) : CarDecorator(component) {}

    void addAsternCamera() {
        cout << "Added Astern Camera" << endl;
    }

    void showStatus() override {
        CarDecorator::showStatus();
        addAsternCamera();
    }
};

class AsternRadarDecorator : public CarDecorator {
public:
    AsternRadarDecorator(NewEnergyCar* component) : CarDecorator(component) {}

    void addAsternRadar() {
        cout << "Added Astern Radar" << endl;
    }

    void showStatus() override {
        CarDecorator::showStatus();
        addAsternRadar();
    }
};

class NavigationDecorator : public CarDecorator {
public:
    NavigationDecorator(NewEnergyCar* component) : CarDecorator(component) {}

    void addNavigation() {
        cout << "Added Navigation System" << endl;
    }

    void showStatus() override {
        CarDecorator::showStatus();
        addNavigation();
    }
};