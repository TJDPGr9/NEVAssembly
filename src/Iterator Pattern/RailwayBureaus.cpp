// RailwayBureaus.cpp
#include "RailwayBureaus.h"

void RailwayBureaus::addPrimaryBureau(const std::string& bureau) {
    for (const auto& primary : primaryAndSecondaries) {
        if (primary.first == bureau) {
            return; // 如果一级基地已存在，不再添加
        }
    }
    primaryAndSecondaries.emplace_back(bureau, std::vector<std::string>());
}

void RailwayBureaus::addSecondaryBureau(const std::string& primaryBureau, const std::string& secondaryBureau) {
    for (auto& primary : primaryAndSecondaries) {
        if (primary.first == primaryBureau) {
            primary.second.push_back(secondaryBureau);
            break;
        }
    }
}

Iterator* RailwayBureaus::createIterator() {
    return new RailwayIterator(primaryAndSecondaries);
}

size_t RailwayBureaus::getTotalBureausCount() const {
    size_t totalCount = 0;
    for (const auto& primary : primaryAndSecondaries) {
        totalCount += primary.second.size() + 1; // 一级基地加上对应的二级基地数量
    }
    return totalCount;
}

size_t RailwayBureaus::getPrimaryBureausCount() const {
    return primaryAndSecondaries.size();
}

size_t RailwayBureaus::getSecondaryBureausCount() const {
    size_t totalCount = 0;
    for (const auto& primary : primaryAndSecondaries) {
        totalCount += primary.second.size();
    }
    return totalCount;
}