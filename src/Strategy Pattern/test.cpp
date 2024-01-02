#include <iostream>
#include <unordered_map>
#include<string>
#include "strategy.h"
namespace Strategy {
    int test() {
        // ´´½¨È¨ÖØ±í
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

        // ´´½¨²ßÂÔÉÏÏÂÎÄ
        TransportationContext context;

        // »ñÈ¡ÓÃ»§ÊäÈë
        std::unordered_map<Factor, int> userInput;
        string src, dst;
        cout << "We can help you decide the best way to transport goods among these cities:" << endl;
        cout << "Beijing\nShanghai\nGuangzhou\nShenzhen\nWuhan\nNanjing\nChongqing\nXian\nChengdu\nTianjin" << endl;
        cout << "Please input the daparture:" << endl;
        cin >> src;
        cout << "Please input the arrival:" << endl;
        
        cin>> dst;
        userInput[Factor::Distance] = 0;
        userInput[Factor::TransportTime] = getUserInput("Duration:");
        userInput[Factor::Cost] = getUserInput("Cost:");
        userInput[Factor::Safety] = getUserInput("Security:");
        userInput[Factor::QuantityAndScale] = getUserInput("Scale:");

        // ÉèÖÃ²»Í¬µÄÔËÊä·½Ê½²ßÂÔ
        RoadTransportationStrategy roadStrategy(weights.at(TransportationMode::Road));
        RailwayTransportationStrategy railwayStrategy(weights.at(TransportationMode::Railway));
        SeaTransportationStrategy seaStrategy(weights.at(TransportationMode::Sea));
        AirTransportationStrategy airStrategy(weights.at(TransportationMode::Air));

        context.setStrategy(&roadStrategy);
        int roadScore = context.executeStrategy(src, dst, userInput);

        context.setStrategy(&railwayStrategy);
        int railwayScore = context.executeStrategy(src, dst, userInput);

        context.setStrategy(&seaStrategy);
        int seaScore = context.executeStrategy(src, dst, userInput);

        context.setStrategy(&airStrategy);
        int airScore = context.executeStrategy(src, dst, userInput);
        // Êä³ö×î¼ÑÔËÊä·½Ê½
        int maxScore = std::max({ roadScore, railwayScore, seaScore, airScore });
        if (maxScore == roadScore) {
            std::cout << "Recommend tranportation via road\n";
        }
        else if (maxScore == railwayScore) {
            std::cout << "Recommend tranportation via railway\n";
        }
        else if (maxScore == seaScore) {
            std::cout << "Recommend tranportation by ship\n";
        }
        else {
            std::cout << "Recommend tranportation by air\n";
        }

        return 0;
    }
}
