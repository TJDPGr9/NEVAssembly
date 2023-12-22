// Iterator.h
#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>
#include <vector>

class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual std::string next() = 0;
    virtual ~Iterator() {}
};

class RailwayIterator : public Iterator {
private:
    std::vector<std::pair<std::string, std::vector<std::string>>> primaryAndSecondaries;
    size_t primaryIndex;
    size_t secondaryIndex;

public:
    RailwayIterator(const std::vector<std::pair<std::string, std::vector<std::string>>>& primarySecondaries);
    bool hasNext() override;
    std::string next() override;
    void reset(); // 重置迭代器
};

#endif