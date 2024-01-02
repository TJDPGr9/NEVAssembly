#pragma once
#include <iostream>


using namespace std;

// 抽象交流电机类
class ACmotor {
public:
    virtual void produce() = 0;
    virtual ~ACmotor() {} 
};

// 不同类型的交流电机
class InductionMotor : public ACmotor {
public:
    void produce() override {
        std::cout << "Produce Induction Motor." << std::endl;
    }
};

class SynchronousMotor : public ACmotor {
public:
    void produce() override {
        std::cout << "Produce Synchronous Motor." << std::endl;
    }
};

class SwitchedReluctanceMotor : public ACmotor {
public:
    void produce() override {
        std::cout << "Produce witched Reluctance Motor." << std::endl;
    }
};

class PermanentMagnetSynchronousMotor : public ACmotor {
public:
    void produce() override {
        std::cout << "Produce Permanent Magnet Synchronous Motor." << std::endl;
    }
};

// 工厂类 - 工厂方法模式
class ACmotorFactory {
public:
    virtual ACmotor* createMotor() = 0;
    virtual ~ACmotorFactory() {} 
};

// 具体的交流电机工厂
class InductionMotorFactory : public ACmotorFactory {
public:
    ACmotor* createMotor() override {
        return new InductionMotor();
    }
};

class SynchronousMotorFactory : public ACmotorFactory {
public:
    ACmotor* createMotor() override {
        return new SynchronousMotor();
    }
};

class SwitchedReluctanceMotorFactory : public ACmotorFactory {
public:
    ACmotor* createMotor() override {
        return new SwitchedReluctanceMotor();
    }
};

class PermanentMagnetSynchronousMotorFactory : public ACmotorFactory {
public:
    ACmotor* createMotor() override {
        return new PermanentMagnetSynchronousMotor();
    }
};

// 客户端代码
void produceMotor(ACmotorFactory* factory) {
    ACmotor* motor = factory->createMotor();
    motor->produce();
    delete motor;
};


