// VWID4.cpp
#include "VWID4.h"
#include <iostream>

// 具体产品 - 大众ID4的车身框架
void ID4CarFrame::display() const {
    std::cout << "VW ID4 Car Frame" << std::endl;
}

// 具体产品 - 大众ID4的外部构件
void ID4ExternalComponents::display() const {
    std::cout << "VW ID4 External Components" << std::endl;
}

// 具体产品 - 大众ID4的内部装饰
void ID4InternalDecoration::display() const {
    std::cout << "VW ID4 Internal Decoration" << std::endl;
}

/* 具体工厂 - 大众ID4工厂 */
CarFrame* ID4CarFactory::createCarFrame() {
    return new ID4CarFrame();
}

ExternalComponents* ID4CarFactory::createExternalComponents() {
    return new ID4ExternalComponents();
}

InternalDecoration* ID4CarFactory::createInternalDecoration() {
    return new ID4InternalDecoration();
}
