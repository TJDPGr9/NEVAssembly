#include "factory.h"


int main() {
    ACmotorFactory* factory1 = new InductionMotorFactory();
    ACmotorFactory* factory2 = new SynchronousMotorFactory();
    ACmotorFactory* factory3 = new SwitchedReluctanceMotorFactory();
    ACmotorFactory* factory4 = new PermanentMagnetSynchronousMotorFactory();

    
    factory1->createMotor()->produce();
    factory2->createMotor()->produce();
    factory3->createMotor()->produce();
    factory4->createMotor()->produce();

    delete factory1;
    delete factory2;
    delete factory3;
    delete factory4;
    std::cin.get();
    return 0;
}
