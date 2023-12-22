// Iterator.cpp
#include "Iterator.h"

RailwayIterator::RailwayIterator(const std::vector<std::pair<std::string, std::vector<std::string>>>& primarySecondaries)
    : primaryAndSecondaries(primarySecondaries), primaryIndex(0), secondaryIndex(0) {}

bool RailwayIterator::hasNext() {
    return primaryIndex < primaryAndSecondaries.size() ||
        (primaryIndex == primaryAndSecondaries.size() &&
            secondaryIndex < primaryAndSecondaries[primaryIndex - 1].second.size());
}

std::string RailwayIterator::next() {
    if (primaryIndex < primaryAndSecondaries.size()) {
        if (secondaryIndex < primaryAndSecondaries[primaryIndex].second.size()) {
            return "一级基地：" + primaryAndSecondaries[primaryIndex].first + "，二级基地：" +
                primaryAndSecondaries[primaryIndex].second[secondaryIndex++];
        }
        else {
            std::string output = "一级基地：" + primaryAndSecondaries[primaryIndex].first;
            primaryIndex++;
            secondaryIndex = 0;
            return output;
        }
    }
    return "";
}

void RailwayIterator::reset() {
    primaryIndex = 0;
    secondaryIndex = 0;
}