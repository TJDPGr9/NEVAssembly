#include <iostream>
#include "RailwayBureaus.h"
#include "Iterator.h"

int main() {
    // 创建铁路基地对象
    RailwayBureaus network;

    // 添加一级基地
    network.addPrimaryBureau("郑州圃田");
    network.addPrimaryBureau("武汉吴家山");
    network.addPrimaryBureau("西安新筑");
    network.addPrimaryBureau("上海闵行");
    network.addPrimaryBureau("柳州");
    network.addPrimaryBureau("广州");

    // 添加二级基地
    network.addSecondaryBureau("黄渡");

    // 获取物流网络基地数量
    size_t totalBureaus = network.getTotalBureausCount();
    size_t primaryBureaus = network.getPrimaryBureausCount();
    size_t secondaryBureaus = network.getSecondaryBureausCount();

    // 输出物流网络基地数量
    std::cout << "物流网络的基地总数：" << totalBureaus << std::endl;
    std::cout << "一级基地数量：" << primaryBureaus << std::endl;
    std::cout << "二级基地数量：" << secondaryBureaus << std::endl;

    // 使用迭代器遍历铁路基地集合
    Iterator* iterator = network.createIterator();
    std::cout << "物流网络中的铁路基地：" << std::endl;

    while (iterator->hasNext()) {
        std::cout << iterator->next() << std::endl;
    }

    delete iterator;

    return 0;
}
