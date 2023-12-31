#include <iostream>
#include "RailwayBureaus.h"
#include "Iterator.h"
int main() {
    RailwayBureaus network;

    network.addPrimaryBureau("郑州圃田");
    network.addPrimaryBureau("武汉吴家山");
    network.addPrimaryBureau("西安新筑");
    network.addPrimaryBureau("上海闵行");
    network.addPrimaryBureau("柳州");
    network.addPrimaryBureau("广州");

    network.addSecondaryBureau("郑州圃田", "中牟");
    network.addSecondaryBureau("郑州圃田", "长治");
    network.addSecondaryBureau("武汉吴家山", "汉阳");
    network.addSecondaryBureau("上海闵行", "黄渡");
    network.addSecondaryBureau("西安新筑", "宝鸡东");

    Iterator* iterator = network.createIterator();

    std::cout << "物流网络的基地总数：" << network.getTotalBureausCount() << std::endl;
    std::cout << "一级基地数量：" << network.getPrimaryBureausCount() << std::endl;
    std::cout << "二级基地数量：" << network.getSecondaryBureausCount() << std::endl;
    std::cout << "物流网络中的铁路基地：" << std::endl;

    while (iterator->hasNext()) {
        std::cout << iterator->next() << std::endl;
    }

    delete iterator;
    std::cin.get();
    return 0;
}
