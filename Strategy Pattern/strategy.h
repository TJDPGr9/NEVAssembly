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

// �������䷽ʽȨ�ر�
using WeightTable = std::unordered_map<TransportationMode, std::unordered_map<Factor, int>>;

// ������Խӿ�
class TransportationStrategy {
public:
    virtual int calculateScore(const WeightTable& weights) const = 0;
    int calculateFactorScore(const std::unordered_map<Factor, int>& factors) const {
        return factors.at(Factor::Distance) +
            factors.at(Factor::TransportTime) +
            factors.at(Factor::Cost) +
            factors.at(Factor::Safety) +
            factors.at(Factor::QuantityAndScale);
    }
};

// ��·�������
class RoadTransportationStrategy : public TransportationStrategy {
public:
    int calculateScore(const WeightTable& weights) const override {
        return calculateFactorScore(weights.at(TransportationMode::Road));
    }
};

// ��·�������
class RailwayTransportationStrategy : public TransportationStrategy {
public:
    int calculateScore(const WeightTable& weights) const override {
        return calculateFactorScore(weights.at(TransportationMode::Railway));
    }
};

// �����������
class SeaTransportationStrategy : public TransportationStrategy {
public:
    int calculateScore(const WeightTable& weights) const override {
        return calculateFactorScore(weights.at(TransportationMode::Sea));
    }
};

// �����������
class AirTransportationStrategy : public TransportationStrategy {
public:
    int calculateScore(const WeightTable& weights) const override {
        return calculateFactorScore(weights.at(TransportationMode::Air));
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

    int executeStrategy(const WeightTable& weights) {
        return strategy->calculateScore(weights);
    }
};