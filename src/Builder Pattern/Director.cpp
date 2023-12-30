#include"Director.h"
void Director::construct() {
    builder->buildBody();
    builder->buildPaint();
    builder->buildChassis();
    builder->buildEngine();
    builder->buildElectricalSystem();
    builder->buildInterior();
    builder->buildLights();
    builder->buildDecorations();
    builder->buildFinalAssembly();
}