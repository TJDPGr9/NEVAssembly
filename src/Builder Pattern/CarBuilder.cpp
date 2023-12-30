#include"CarBuilder.h"
void CarBuilder::buildBody() 
{ 
    car.body = BodyType::WELDED_METAL; 
}
void CarBuilder::buildPaint()  
{ 
    car.paint = PaintType::PRIMED_AND_PAINTED; 
}
void CarBuilder::buildChassis()  
{ 
    car.chassis = ChassisType::ASSEMBLED; 
}
void CarBuilder::buildEngine()  
{ 
    car.engine = EngineType::INSTALLED; 
}
void CarBuilder::buildElectricalSystem()  
{ 
    car.electricalSystem = ElectricalSystemType::WIRED; 
}
void CarBuilder::buildInterior() 
{ 
    car.interior = InteriorType::INSTALLED; 
}
void CarBuilder::buildLights()  
{ 
    car.lights = LightsType::MOUNTED; 
}
void CarBuilder::buildDecorations()  
{ 
    car.decorations = DecorationsType::APPLIED; 
}

void CarBuilder::buildFinalAssembly() 
{
    // 确保前面的变量值不为空
    if (static_cast<int>(car.body) == 0 || static_cast<int>(car.paint) == 0 || static_cast<int>(car.chassis) == 0 ||
        static_cast<int>(car.engine) == 0 || static_cast<int>(car.electricalSystem) == 0 || static_cast<int>(car.interior) == 0 ||
        static_cast<int>(car.lights) == 0 || static_cast<int>(car.decorations) == 0) {
        // 可以选择抛出异常或采取其他错误处理措施
        car.finalAssemblyandInspection = false;
        throw std::runtime_error("Error: Incomplete data for final assembly.");
    }
    else {
        car.finalAssemblyandInspection = true;
    }
}

Car CarBuilder::getResult()  
{ 
    return car; 
}