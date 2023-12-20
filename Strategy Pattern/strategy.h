#pragma once

#include <unordered_map>
#include <vector>
#include <algorithm>

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
    virtual int calculateScore(const std::unordered_map<Factor, int>& factors) const = 0;
};

// ��������Ȩ�صĲ��Խӿ�
class WeightedTransportationStrategy : public TransportationStrategy {
protected:
    std::unordered_map<Factor, int> factorWeights;

public:
    WeightedTransportationStrategy(const std::unordered_map<Factor, int>& weights)
        : factorWeights(weights) {}

    int calculateScore(const std::unordered_map<Factor, int>& factors) const override {
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

    int calculateScore(const std::unordered_map<Factor, int>& factors) const override {
        return WeightedTransportationStrategy::calculateScore(factors);
    }
};

// ��·�������
class RailwayTransportationStrategy : public WeightedTransportationStrategy {
public:
    RailwayTransportationStrategy(const std::unordered_map<Factor, int>& weights)
        : WeightedTransportationStrategy(weights) {}

    int calculateScore(const std::unordered_map<Factor, int>& factors) const override {
        return WeightedTransportationStrategy::calculateScore(factors);
    }
};

// �����������
class SeaTransportationStrategy : public WeightedTransportationStrategy {
public:
    SeaTransportationStrategy(const std::unordered_map<Factor, int>& weights)
        : WeightedTransportationStrategy(weights) {}

    int calculateScore(const std::unordered_map<Factor, int>& factors) const override {
        return WeightedTransportationStrategy::calculateScore(factors);
    }
};

// �����������
class AirTransportationStrategy : public WeightedTransportationStrategy {
public:
    AirTransportationStrategy(const std::unordered_map<Factor, int>& weights)
        : WeightedTransportationStrategy(weights) {}

    int calculateScore(const std::unordered_map<Factor, int>& factors) const override {
        return WeightedTransportationStrategy::calculateScore(factors);
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

    int executeStrategy(const std::unordered_map<Factor, int>& factors) const {
        return strategy->calculateScore(factors);
    }
};

// ��ȡ�û�����
int getUserInput(const std::string& factorName) {
    int userInput;
    std::cout << "������" << factorName << "��ֵ: ";
    std::cin >> userInput;
    return userInput;
}
