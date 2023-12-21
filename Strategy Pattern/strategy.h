#pragma once

#include <unordered_map>
#include <vector>
#include <algorithm>
#include"dijkstra.h"
#include"utility.h"
// �������䷽ʽö��
enum class TransportationMode {
    Road,
    Railway,
    Sea,
    Air,
    Multimodal,
};

// ��������ö��
enum class Factor {
    Distance,
    TransportTime,
    Cost,
    Safety,
    QuantityAndScale,
};

// ����ÿ�����䷽ʽ��Ȩ�ر�
using WeightTable = std::unordered_map<TransportationMode, std::unordered_map<Factor, int>>;

// ������Խӿ�
class TransportationStrategy {
public:
    virtual int calculateScore(string departure, string arrival, const std::unordered_map<Factor, int>& factors)const = 0;
};

// ��������Ȩ�صĲ��Խӿ�
class WeightedTransportationStrategy : public TransportationStrategy {
protected:
    std::unordered_map<Factor, int> factorWeights;

public:
    WeightedTransportationStrategy(const std::unordered_map<Factor, int>& weights)
        : factorWeights(weights) {}

    int utility(int dist, const std::unordered_map<Factor, int>& factors) const{
        return factors.at(Factor::Distance) * factorWeights.at(Factor::Distance) +
            factors.at(Factor::TransportTime) * factorWeights.at(Factor::TransportTime) +
            factors.at(Factor::Cost) * factorWeights.at(Factor::Cost) +
            factors.at(Factor::Safety) * factorWeights.at(Factor::Safety) +
            factors.at(Factor::QuantityAndScale) * factorWeights.at(Factor::QuantityAndScale);
    }
};

// ��·�������
class RoadTransportationStrategy : public WeightedTransportationStrategy {
public:
    RoadTransportationStrategy(const std::unordered_map<Factor, int>& weights)
        : WeightedTransportationStrategy(weights) {}

    int calculateScore(string departure, string arrival, const std::unordered_map<Factor, int>& factors) const override {
        int dist = real_distance(TranportationMeans::Road, departure, arrival);
        return WeightedTransportationStrategy::utility(dist, factors);
    }
};

// ��·�������
class RailwayTransportationStrategy : public WeightedTransportationStrategy {
public:
    RailwayTransportationStrategy(const std::unordered_map<Factor, int>& weights)
        : WeightedTransportationStrategy(weights) {}

    int calculateScore(string departure, string arrival, const std::unordered_map<Factor, int>& factors) const override {
        int dist = real_distance(TranportationMeans::Railway, departure, arrival);
        return WeightedTransportationStrategy::utility(dist, factors);
    }
};

// �����������
class SeaTransportationStrategy : public WeightedTransportationStrategy {
public:
    SeaTransportationStrategy(const std::unordered_map<Factor, int>& weights)
        : WeightedTransportationStrategy(weights) {}

    int calculateScore(string departure, string arrival, const std::unordered_map<Factor, int>& factors) const override {
        int dist=real_distance(TranportationMeans::Sail, departure, arrival);
        return WeightedTransportationStrategy::utility(dist, factors);
    }
};

// �����������
class AirTransportationStrategy : public WeightedTransportationStrategy {
public:
    AirTransportationStrategy(const std::unordered_map<Factor, int>& weights)
        : WeightedTransportationStrategy(weights) {}

    int calculateScore(string departure, string arrival, const std::unordered_map<Factor, int>& factors) const override {
        int dist = real_distance(TranportationMeans::Air, departure, arrival);
        return WeightedTransportationStrategy::utility(dist,factors);
    }
};

// ����������
class TransportationContext {
private:
    TransportationStrategy* strategy;

public:
    void setStrategy(TransportationStrategy* newStrategy) {
        strategy = newStrategy;
    }

    int executeStrategy(string departure, string arrival, const std::unordered_map<Factor, int>& factors) const {
        return strategy->calculateScore(departure, arrival, factors);
    }
};

// ��ȡ�û�����
int getUserInput(const std::string& factorName) {
    int userInput=-1;
    std::cout << "Please input the score of " << factorName<<"(100/100):";
    std::cin >> userInput;
    while (userInput < 0 || userInput>100) {
        std::cout << "Please input the score of " << factorName << "(100/100) again\nnote the range of the value:";
        std::cin >> userInput;
        std::cin.clear();
    }
    
    return userInput;
}
