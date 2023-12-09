#pragma once
#include"Builder.h"
class Director {
private:
    Builder* builder;

public:
    Director(Builder* builder) : builder(builder) {}

    void construct();
};
