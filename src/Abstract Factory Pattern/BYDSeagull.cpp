// BYDSeagull.cpp
#include "BYDSeagull.h"
#include <iostream>

// 具体产品 - 比亚迪海鸥的车身框架
void SeagullCarFrame::display() const {
    std::cout << "BYD Seagull Car Frame" << std::endl;
}

// 具体产品 - 比亚迪海鸥的外部构件
void SeagullExternalComponents::display() const {
    std::cout << "BYD Seagull External Components" << std::endl;
}

// 具体产品 - 比亚迪海鸥的内部装饰
void SeagullInternalDecoration::display() const {
    std::cout << "BYD Seagull Internal Decoration" << std::endl;
}

/* 具体工厂 - 比亚迪海鸥工厂 */
CarFrame* SeagullCarFactory::createCarFrame() {
    return new SeagullCarFrame();
}

ExternalComponents* SeagullCarFactory::createExternalComponents() {
    return new SeagullExternalComponents();
}

InternalDecoration* SeagullCarFactory::createInternalDecoration() {
    return new SeagullInternalDecoration();
}
