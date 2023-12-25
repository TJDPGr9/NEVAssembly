// Main.cpp
#include "Abstract.h"
#include "BYDSeagull.h"
#include "VWID4.h"
#include <iostream>

void assembleCar(CarFactory* factory);

int main() {
    // 生产比亚迪海鸥
    CarFactory* SeagullFactory = new SeagullCarFactory();
    assembleCar(SeagullFactory);
    delete SeagullFactory;

    std::cout << std::endl;

    // 生产大众ID4
    CarFactory* ID4Factory = new ID4CarFactory();
    assembleCar(ID4Factory);
    delete ID4Factory;
    std::cin.get();
    return 0;
}

void assembleCar(CarFactory* factory) {
    CarFrame* frame = factory->createCarFrame();
    ExternalComponents* externalComponents = factory->createExternalComponents();
    InternalDecoration* internalDecoration = factory->createInternalDecoration();

    std::cout << "Assembling a new car:" << std::endl;
    frame->display();
    externalComponents->display();
    internalDecoration->display();

    // 清理资源
    delete frame;
    delete externalComponents;
    delete internalDecoration;
}
