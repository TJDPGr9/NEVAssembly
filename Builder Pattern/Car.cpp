#include"Car.h"
// 映射枚举值到字符串的函数
extern std::map<BodyType, std::string> bodyTypeToString{
    {BodyType::WELDED_METAL, "Welded Metal"},
    {BodyType::ALUMINUM, "Aluminum"},
    {BodyType::CARBON_FIBER, "Carbon Fiber"}
};

extern std::map<PaintType, std::string> paintTypeToString{
    {PaintType::PRIMED_AND_PAINTED, "Primed and Painted"},
    {PaintType::METALLIC, "Metallic"},
    {PaintType::CLEAR_COAT, "Clear Coat"}
};

extern std::map<ChassisType, std::string> chassisTypeToString{
    {ChassisType::ASSEMBLED, "Assembled"},
    {ChassisType::MONOCOQUE, "Monocoque"},
    {ChassisType::SPACE_FRAME, "Space Frame"}
};

extern std::map<EngineType, std::string> engineTypeToString{
    {EngineType::INSTALLED, "Installed"},
    {EngineType::ELECTRIC, "Electric"},
    {EngineType::HYBRID, "Hybrid"}
};

extern std::map<ElectricalSystemType, std::string> electricalSystemTypeToString{
    {ElectricalSystemType::WIRED, "Wired"},
    {ElectricalSystemType::WIRELESS, "Wireless"},
    {ElectricalSystemType::SMART, "Smart"}
};

extern std::map<InteriorType, std::string> interiorTypeToString{
    {InteriorType::INSTALLED, "Installed"},
    {InteriorType::LEATHER, "Leather"},
    {InteriorType::CLOTH, "Cloth"}
};

extern std::map<LightsType, std::string> lightsTypeToString{
    {LightsType::MOUNTED, "Mounted"},
    {LightsType::LED, "LED"},
    {LightsType::XENON, "Xenon"}
};

extern std::map<DecorationsType, std::string> decorationsTypeToString{
    {DecorationsType::APPLIED, "Applied"},
    {DecorationsType::CUSTOM, "Custom"},
    {DecorationsType::STANDARD, "Standard"}
};
void Car::display() {
    std::cout << "Car Details:" << std::endl;
    std::cout << "Body: " << bodyTypeToString[body] << std::endl;
    std::cout << "Paint: " << paintTypeToString[paint] << std::endl;
    std::cout << "Chassis: " << chassisTypeToString[chassis] << std::endl;
    std::cout << "Engine: " << engineTypeToString[engine] << std::endl;
    std::cout << "Electrical System: " << electricalSystemTypeToString[electricalSystem] << std::endl;
    std::cout << "Interior: " << interiorTypeToString[interior] << std::endl;
    std::cout << "Lights: " << lightsTypeToString[lights] << std::endl;
    std::cout << "Decorations: " << decorationsTypeToString[decorations] << std::endl;
    std::cout << "Final Assembly&Insepction: " << (finalAssemblyandInspection ? "Assemblied successfully!" : "Wrong assembly!") << std::endl;
    std::cout << "-----------------------" << std::endl;
}