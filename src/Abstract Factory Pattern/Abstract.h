// CarFactory.h
#pragma once

// 抽象产品接口 - 车身框架
class CarFrame {
public:
    virtual ~CarFrame() = default;
    virtual void display() const = 0;
};

// 抽象产品接口 - 外部构件
class ExternalComponents {
public:
    virtual ~ExternalComponents() = default;
    virtual void display() const = 0;
};

// 抽象产品接口 - 内部装饰
class InternalDecoration {
public:
    virtual ~InternalDecoration() = default;
    virtual void display() const = 0;
};

// 抽象工厂接口
class CarFactory {
public:
    virtual ~CarFactory() = default;
    virtual CarFrame* createCarFrame() = 0;
    virtual ExternalComponents* createExternalComponents() = 0;
    virtual InternalDecoration* createInternalDecoration() = 0;
};
