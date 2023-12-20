#include <iostream>
#include <unordered_map>

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

    // ��ȡ�û�����
    std::unordered_map<Factor, int> userInput;
    userInput[Factor::Distance] = getUserInput("����");
    userInput[Factor::TransportTime] = getUserInput("����ʱ��");
    userInput[Factor::Cost] = getUserInput("�ɱ�");
    userInput[Factor::Safety] = getUserInput("��ȫ��");
    userInput[Factor::QuantityAndScale] = getUserInput("�����͹�ģ");

    // ���ò�ͬ�����䷽ʽ����
    RoadTransportationStrategy roadStrategy(weights.at(TransportationMode::Road));
    RailwayTransportationStrategy railwayStrategy(weights.at(TransportationMode::Railway));
    SeaTransportationStrategy seaStrategy(weights.at(TransportationMode::Sea));
    AirTransportationStrategy airStrategy(weights.at(TransportationMode::Air));

    context.setStrategy(&roadStrategy);
    int roadScore = context.executeStrategy(userInput);

    context.setStrategy(&railwayStrategy);
    int railwayScore = context.executeStrategy(userInput);

    context.setStrategy(&seaStrategy);
    int seaScore = context.executeStrategy(userInput);

    context.setStrategy(&airStrategy);
    int airScore = context.executeStrategy(userInput);

    // ���������䷽ʽ
    int maxScore = std::max({ roadScore, railwayScore, seaScore, airScore });
    if (maxScore == roadScore) {
        std::cout << "�Ƽ�ʹ�ù�·���䷽ʽ\n";
    }
    else if (maxScore == railwayScore) {
        std::cout << "�Ƽ�ʹ����·���䷽ʽ\n";
    }
    else if (maxScore == seaScore) {
        std::cout << "�Ƽ�ʹ�ú��˷�ʽ\n";
    }
    else {
        std::cout << "�Ƽ�ʹ�ú������䷽ʽ\n";
    }

    return 0;
}
