#include "Iterator.h"

RailwayIterator::RailwayIterator(const std::vector<std::string>& primaries, const std::vector<std::string>& secondaries)
    : primaryBureaus(primaries), secondaryBureaus(secondaries), position(0) {}

bool RailwayIterator::hasNext() {
    return position < primaryBureaus.size() + secondaryBureaus.size();
}

std::string RailwayIterator::next() {
    if (position < primaryBureaus.size()) {
        return "一级基地："  + primaryBureaus[position++];
    }
    else if (position < primaryBureaus.size() + secondaryBureaus.size()) {
        return "二级基地：" + secondaryBureaus[position++ - primaryBureaus.size()];
    }
    return "";
}

void RailwayIterator::reset() {
    position = 0;
}
