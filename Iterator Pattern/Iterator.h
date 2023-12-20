#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include <string>

class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual std::string next() = 0;
    virtual ~Iterator() {}
};

class RailwayIterator : public Iterator {
private:
    std::vector<std::string> primaryBureaus;
    std::vector<std::string> secondaryBureaus;
    size_t position;

public:
    RailwayIterator(const std::vector<std::string>& primaries, const std::vector<std::string>& secondaries);
    bool hasNext() override;
    std::string next() override;
    void reset(); // 重置迭代器
};

#endif
