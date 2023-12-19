#include <iostream>

#include "strategy.h"

int main() {
    // 创建权重表
    WeightTable weights{
        {   TransportationMode::Road, 
            {
                {Factor::Distance, 8},
                {Factor::TransportTime, 7},
                {Factor::Cost, 8},
                {Factor::Safety, 7},
                {Factor::QuantityAndScale, 7},
            }
        },
        {   TransportationMode::Railway, 
            {
                {Factor::Distance, 7},
                {Factor::TransportTime, 6},
                {Factor::Cost, 7},
                {Factor::Safety, 8},
                {Factor::QuantityAndScale, 8},
            }
        },
        {   TransportationMode::Sea, 
            {
                {Factor::Distance, 9},
                {Factor::TransportTime, 5},
                {Factor::Cost, 9},
                {Factor::Safety, 6},
                {Factor::QuantityAndScale, 9},
            }
        },
        {   TransportationMode::Air, 
            {
                {Factor::Distance, 8},
                {Factor::TransportTime, 9},
                {Factor::Cost, 6},
                {Factor::Safety, 9},
                {Factor::QuantityAndScale, 6},
            }
        },
    };

    // 创建策略上下文
    TransportationContext context;

    // 设置不同的策略
    RoadTransportationStrategy roadStrategy;
    RailwayTransportationStrategy railwayStrategy;
    SeaTransportationStrategy seaStrategy;
    AirTransportationStrategy airStrategy;

    context.setStrategy(&roadStrategy);
    int roadScore = context.executeStrategy(weights);

    context.setStrategy(&railwayStrategy);
    int railwayScore = context.executeStrategy(weights);

    context.setStrategy(&seaStrategy);
    int seaScore = context.executeStrategy(weights);

    context.setStrategy(&airStrategy);
    int airScore = context.executeStrategy(weights);

    // 比较得分，输出最佳运输方式
    int maxScore = std::max({ roadScore, railwayScore, seaScore, airScore });
    if (maxScore == roadScore) {
        std::cout << "推荐使用公路运输方式。\n";
    }
    else if (maxScore == railwayScore) {
        std::cout << "推荐使用铁路运输方式。\n";
    }
    else if (maxScore == seaScore) {
        std::cout << "推荐使用海运方式。\n";
    }
    else {
        std::cout << "推荐使用航空运输方式。\n";
    }

    return 0;
}
