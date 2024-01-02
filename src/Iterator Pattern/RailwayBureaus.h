// RailwayBureaus.h
#ifndef RAILWAY_BUREAUS_H
#define RAILWAY_BUREAUS_H

#include <string>
#include <vector>
#include "Iterator.h"

class RailwayBureaus {
private:
    std::vector<std::pair<std::string, std::vector<std::string>>> primaryAndSecondaries; 

public:
    void addPrimaryBureau(const std::string& bureau);
    void addSecondaryBureau(const std::string& primaryBureau, const std::string& secondaryBureau);

    Iterator* createIterator();

    size_t getTotalBureausCount() const;
    size_t getPrimaryBureausCount() const;
    size_t getSecondaryBureausCount() const;
};

#endif