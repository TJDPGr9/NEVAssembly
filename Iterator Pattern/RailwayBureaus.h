#ifndef RAILWAY_BUREAUS_H
#define RAILWAY_BUREAUS_H

#include <vector>
#include <string>
#include "Iterator.h"

class RailwayBureaus {
private:
    std::vector<std::string> primaryBureaus; // 一级基地
    std::vector<std::string> secondaryBureaus; // 二级基地

public:
    void addPrimaryBureau(const std::string& bureau);
    void addSecondaryBureau(const std::string& bureau);

    Iterator* createIterator() ;

    size_t getTotalBureausCount() const; // 获取所有基地数量
    size_t getPrimaryBureausCount() const; // 获取一级基地数量
    size_t getSecondaryBureausCount() const; // 获取二级基地数量

   
};

#endif
