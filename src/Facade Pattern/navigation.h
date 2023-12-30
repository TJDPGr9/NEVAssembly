#pragma once

#include <string>

// ��ͼ���ݻ�ȡ��ϵͳ
class MapDataSubsystem {
public:
    std::string getMapData();
};

// ʵʱ��ͨ��Ϣ������ϵͳ
class TrafficInfoSubsystem {
public:
    std::string processTrafficInfo();
};

// GPS��λ��ϵͳ
class GPSLocationSubsystem {
public:
    std::string getCurrentLocation();
};

// ����������ϵͳ
class VoiceNavigationSubsystem {
public:
    std::string generateVoiceCommand();
};

// �����
class NavigationFacade {
private:
    MapDataSubsystem mapSubsystem;
    TrafficInfoSubsystem trafficSubsystem;
    GPSLocationSubsystem gpsSubsystem;
    VoiceNavigationSubsystem voiceSubsystem;

public:
    std::string startNavigation();
};


// �෽�����ⲿʵ��
// MapDataSubsystem implementation
std::string MapDataSubsystem::getMapData() {
    return "ʵʱ��ͼ���ݻ�ȡ���\n";
}

// TrafficInfoSubsystem implementation
std::string TrafficInfoSubsystem::processTrafficInfo() {
    return "ʵʱ��ͨ��Ϣ�������\n";
}

// GPSLocationSubsystem implementation
std::string GPSLocationSubsystem::getCurrentLocation() {
    return "��ǰλ����Ϣ��ȡ���\n";
}

// VoiceNavigationSubsystem implementation
std::string VoiceNavigationSubsystem::generateVoiceCommand() {
    return "��������ָ���������\n";
}

// NavigationFacade implementation
std::string NavigationFacade::startNavigation() {
    std::string mapData = mapSubsystem.getMapData();
    std::string trafficInfo = trafficSubsystem.processTrafficInfo();
    std::string currentLocation = gpsSubsystem.getCurrentLocation();
    std::string voiceCommand = voiceSubsystem.generateVoiceCommand();

    return "������ʼ��\n" + mapData + trafficInfo + currentLocation + voiceCommand;
}