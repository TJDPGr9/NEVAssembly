#include "RailwayBureaus.h"

void RailwayBureaus::addPrimaryBureau(const std::string& bureau) {
    primaryBureaus.push_back(bureau);
}

void RailwayBureaus::addSecondaryBureau(const std::string& bureau) {
    secondaryBureaus.push_back(bureau);
}

Iterator* RailwayBureaus::createIterator() {
    return new RailwayIterator(primaryBureaus, secondaryBureaus);
}

size_t RailwayBureaus::getTotalBureausCount() const {
    return primaryBureaus.size() + secondaryBureaus.size();
}

size_t RailwayBureaus::getPrimaryBureausCount() const {
    return primaryBureaus.size();
}

size_t RailwayBureaus::getSecondaryBureausCount() const {
    return secondaryBureaus.size();
}

