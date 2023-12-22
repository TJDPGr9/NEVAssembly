// BYDSeagull.h
#pragma once
#include "Abstract.h"

// 具体产品 - 比亚迪海鸥的车身框架
class SeagullCarFrame : public CarFrame {
public:
    void display() const override;
};

// 具体产品 - 比亚迪海鸥的外部构件
class SeagullExternalComponents : public ExternalComponents {
public:
    void display() const override;
};

// 具体产品 - 比亚迪海鸥的内部装饰
class SeagullInternalDecoration : public InternalDecoration {
public:
    void display() const override;
};

// 具体工厂 - 比亚迪海鸥工厂
class SeagullCarFactory : public CarFactory {
public:
    CarFrame* createCarFrame() override;
    ExternalComponents* createExternalComponents() override;
    InternalDecoration* createInternalDecoration() override;
};
