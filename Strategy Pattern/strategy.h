#pragma once

#include <unordered_map>
#include <vector>
#include <algorithm>

// 定义运输方式枚举
enum class TransportationMode {
    Road,
    Railway,
    Sea,
    Air,
    Multimodal,
};

// 定义因素枚举
enum class Factor {
    Distance,
    TransportTime,
    Cost,
    Safety,
    QuantityAndScale,
};

// 定义运输方式权重表
using WeightTable = std::unordered_map<TransportationMode, std::unordered_map<Factor, int>>;

// 定义策略接口
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

// 公路运输策略
class RoadTransportationStrategy : public TransportationStrategy {
public:
    int calculateScore(const WeightTable& weights) const override {
        return calculateFactorScore(weights.at(TransportationMode::Road));
    }
};

// 铁路运输策略
class RailwayTransportationStrategy : public TransportationStrategy {
public:
    int calculateScore(const WeightTable& weights) const override {
        return calculateFactorScore(weights.at(TransportationMode::Railway));
    }
};

// 海运运输策略
class SeaTransportationStrategy : public TransportationStrategy {
public:
    int calculateScore(const WeightTable& weights) const override {
        return calculateFactorScore(weights.at(TransportationMode::Sea));
    }
};

// 航空运输策略
class AirTransportationStrategy : public TransportationStrategy {
public:
    int calculateScore(const WeightTable& weights) const override {
        return calculateFactorScore(weights.at(TransportationMode::Air));
    }
};

// 策略上下文
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