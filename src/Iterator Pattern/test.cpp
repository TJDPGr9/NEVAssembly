#include <iostream>
#include "RailwayBureaus.h"
#include "Iterator.h"
namespace Iterator2 {
    int test() {
        RailwayBureaus network;

        network.addPrimaryBureau("Zhengzhou Putian");
        network.addPrimaryBureau("Wuhan Wujiashan");
        network.addPrimaryBureau("Xi'an Xinzhu");
        network.addPrimaryBureau("Shanghai Minhang");
        network.addPrimaryBureau("Liuzhou");
        network.addPrimaryBureau("Guangzhou");

        network.addSecondaryBureau("Zhengzhou Putian", "Zhongmou");
        network.addSecondaryBureau("Zhengzhou Putian", "CiH");
        network.addSecondaryBureau("Wuhan Wujiashan", "Hanyang");
        network.addSecondaryBureau("Shanghai Minhang", "Huangdu");
        network.addSecondaryBureau("Xi'an Xinzhu", "Baoji East");

        Iterator* iterator = network.createIterator();

        std::cout << "Total number of logistics network bases:" << network.getTotalBureausCount() << std::endl;
        std::cout << "Number of primary bases:" << network.getPrimaryBureausCount() << std::endl;
        std::cout << "Number of secondary bases:" << network.getSecondaryBureausCount() << std::endl;
        std::cout << "Railway bases in logistics networks:" << std::endl;

        while (iterator->hasNext()) {
            std::cout << iterator->next() << std::endl;
        }

        delete iterator;

        return 0;
    }
}
