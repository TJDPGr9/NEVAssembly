#include <iostream>

#include "strategy.h"

int main() {
    // ����Ȩ�ر�
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

    // ��������������
    TransportationContext context;

    // ���ò�ͬ�Ĳ���
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

    // �Ƚϵ÷֣����������䷽ʽ
    int maxScore = std::max({ roadScore, railwayScore, seaScore, airScore });
    if (maxScore == roadScore) {
        std::cout << "�Ƽ�ʹ�ù�·���䷽ʽ��\n";
    }
    else if (maxScore == railwayScore) {
        std::cout << "�Ƽ�ʹ����·���䷽ʽ��\n";
    }
    else if (maxScore == seaScore) {
        std::cout << "�Ƽ�ʹ�ú��˷�ʽ��\n";
    }
    else {
        std::cout << "�Ƽ�ʹ�ú������䷽ʽ��\n";
    }

    return 0;
}
