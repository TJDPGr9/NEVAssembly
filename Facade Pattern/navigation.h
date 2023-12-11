#pragma once

#include <string>

// 地图数据获取子系统
class MapDataSubsystem {
public:
    std::string getMapData();
};

// 实时交通信息处理子系统
class TrafficInfoSubsystem {
public:
    std::string processTrafficInfo();
};

// GPS定位子系统
class GPSLocationSubsystem {
public:
    std::string getCurrentLocation();
};

// 语音导航子系统
class VoiceNavigationSubsystem {
public:
    std::string generateVoiceCommand();
};

// 外观类
class NavigationFacade {
private:
    MapDataSubsystem mapSubsystem;
    TrafficInfoSubsystem trafficSubsystem;
    GPSLocationSubsystem gpsSubsystem;
    VoiceNavigationSubsystem voiceSubsystem;

public:
    std::string startNavigation();
};


// 类方法的外部实现
// MapDataSubsystem implementation
std::string MapDataSubsystem::getMapData() {
    return "实时地图数据获取完成\n";
}

// TrafficInfoSubsystem implementation
std::string TrafficInfoSubsystem::processTrafficInfo() {
    return "实时交通信息处理完成\n";
}

// GPSLocationSubsystem implementation
std::string GPSLocationSubsystem::getCurrentLocation() {
    return "当前位置信息获取完成\n";
}

// VoiceNavigationSubsystem implementation
std::string VoiceNavigationSubsystem::generateVoiceCommand() {
    return "语音导航指令生成完毕\n";
}

// NavigationFacade implementation
std::string NavigationFacade::startNavigation() {
    std::string mapData = mapSubsystem.getMapData();
    std::string trafficInfo = trafficSubsystem.processTrafficInfo();
    std::string currentLocation = gpsSubsystem.getCurrentLocation();
    std::string voiceCommand = voiceSubsystem.generateVoiceCommand();

    return "导航开始：\n" + mapData + trafficInfo + currentLocation + voiceCommand;
}