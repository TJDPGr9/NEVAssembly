#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <algorithm>
#include <list>
#include <string>
#include <vector>
#include <stdio.h>


/*设计模式：访问者模式
  功能：不同的测试者针对不同部分装置或整体汽车进行磨损评估或功能评估*/
namespace lsr {
    class Element;
    class Motor; 
    class Door;
    class Tyre;

    class Visitor {
    public:
        Visitor(std::string name) {
            visitorName = name;
        }
        virtual void examineMotor(Motor* motor) {};
        virtual void examineDoor(Door* door) {};
        virtual void examineTyre(Tyre* tyre) {};

        std::string getName() {
            return this->visitorName;
        };
    private:
        std::string visitorName;
    };

    class Element {
    public:
        Element(std::string name) {
            eleName = name;
        }
        virtual void accept(Visitor* visitor) {};

        virtual std::string getName() {
            return this->eleName;
        }
    private:
        std::string eleName;
    };

    class Motor : public Element {
    public:
        Motor(std::string name) : Element(name) {}

        void accept(Visitor* visitor) {
            visitor->examineMotor(this);
        }
    };

    class Door : public Element {
    public:
        Door(std::string name) : Element(name) {}

        void accept(Visitor* visitor) {
            visitor->examineDoor(this);
        }
    };

    class Tyre : public Element {
    public:
        Tyre(std::string name) : Element(name) {}

        void accept(Visitor* visitor) {
            visitor->examineTyre(this);
        }
    };

    class FrayDetector : public Visitor {
    public:
        FrayDetector(std::string name) : Visitor(name) {}

        // checking Motor
        void examineMotor(Motor* motor) {
            std::cout << Visitor::getName() << " checks Motor's quality.(" << motor->getName() << ")" << std::endl;
        }

        // checking Door
        void examineDoor(Door* door) {
            std::cout << Visitor::getName() << " checks Door's quality.(" << door->getName() << ")" << std::endl;
        }

        // checking Mouse
        void examineMouse(Tyre* tyre) {
            std::cout << Visitor::getName() << " checks Tyre's quality.(" << tyre->getName() << ")" << std::endl;
        }

    };

    class FunctionDetector : public Visitor {
    public:
        FunctionDetector(std::string name) : Visitor(name) {}
        virtual void examineMotor(Motor* motor) {
            std::cout << Visitor::getName() << " checks Motor's function." << std::endl;
        }

        // checking Door
        void examineDoor(Door* Door) {
            std::cout << Visitor::getName() << " checks Door's function." << std::endl;
        }

        // checking Mouse
        void examineMouse(Tyre* tyre) {
            std::cout << Visitor::getName() << " checks Tyre's function." << std::endl;
        }
    };


    class Car {
    public:
        Car(Motor* motor,
            Door* door,
            Tyre* tyre) {
            elementList.push_back(motor);
            elementList.push_back(door);
            elementList.push_back(tyre);
        };
        void Accept(Visitor* visitor) {
            for (std::vector<Element*>::iterator i = elementList.begin(); i != elementList.end(); i++)
            {
                (*i)->accept(visitor);
            }
        };
    private:
        std::vector<Element*> elementList;
    };

    void client_visitor() {
        Motor* motor = new Motor("Motor");
        Door* door = new Door("Door");
        Tyre* tyre = new Tyre("Tyre");
        Car* myCar = new Car(motor, door, tyre);

        FrayDetector* frayDetector = new FrayDetector("Visitor1(FrayDetector)");
        FunctionDetector* functionDetector = new FunctionDetector("Visitor2(FunctionDetector)");

        std::cout << "\nStep 1:\n" << frayDetector->getName() << " begin to check the quality of car's frays:" << std::endl;
        myCar->Accept(frayDetector);

        std::cout << "\nStep 2:\n" << functionDetector->getName() << " begin to check checks car's functions:" << std::endl;
        myCar->Accept(functionDetector);
    }
}
#pragma once
