#pragma once
#include"Builder.h"
// 具体构造者类
class CarBuilder : public Builder {
private:
    Car car;

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

    Car getResult();
};