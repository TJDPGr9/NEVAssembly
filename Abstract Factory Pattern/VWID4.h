// VWID4.h
#pragma once
#include "Abstract.h"

// 具体产品 - 大众ID4的车身框架
class ID4CarFrame : public CarFrame {
public:
    void display() const override;
};

// 具体产品 - 大众ID4的外部构件
class ID4ExternalComponents : public ExternalComponents {
public:
    void display() const override;
};

// 具体产品 - 大众ID4的内部装饰
class ID4InternalDecoration : public InternalDecoration {
public:
    void display() const override;
};

// 具体工厂 - 大众ID4工厂
class ID4CarFactory : public CarFactory {
public:
    CarFrame* createCarFrame() override;
    ExternalComponents* createExternalComponents() override;
    InternalDecoration* createInternalDecoration() override;
};
