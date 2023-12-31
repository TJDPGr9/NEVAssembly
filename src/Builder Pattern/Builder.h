#pragma once
#include"Car.h"
using namespace Builder_Car;
class Builder {
public:
    virtual void buildBody() = 0;
    virtual void buildPaint() = 0;
    virtual void buildChassis() = 0;
    virtual void buildEngine() = 0;
    virtual void buildElectricalSystem() = 0;
    virtual void buildInterior() = 0;
    virtual void buildLights() = 0;
    virtual void buildDecorations() = 0;
    virtual void buildFinalAssembly() = 0;
    virtual Builder_Car::Car getResult() = 0;
};


