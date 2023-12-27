#pragma once
#include"Builder.h"
// 具体构造者类
using namespace Builder_Car;
class CarBuilder : public Builder {
private:
    Builder_Car::Car car;

public:
    void buildBody();
    void buildPaint();
    void buildChassis();
    void buildEngine();
    void buildElectricalSystem();
    void buildInterior();
    void buildLights();
    void buildDecorations();

    void buildFinalAssembly();

    Builder_Car::Car getResult();
};