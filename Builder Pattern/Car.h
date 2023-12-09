#pragma once
#include<iostream>
#include"EnumType.h"
class Car {
public:
    BodyType body;
    PaintType paint;
    ChassisType chassis;
    EngineType engine;
    ElectricalSystemType electricalSystem;
    InteriorType interior;
    LightsType lights;
    DecorationsType decorations;
    bool finalAssemblyandInspection;

    void display();
};