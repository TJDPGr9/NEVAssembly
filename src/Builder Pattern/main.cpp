#include <iostream>
#include <stdexcept>
#include"Director.h"
#include"CarBuilder.h"
int main() {
    // 创建具体构造者
    CarBuilder carBuilder;

    // 创建指导者
    Director director(&carBuilder);

    // 构建汽车
    director.construct();

    // 获取构建结果
    Car car = carBuilder.getResult();

    // 显示汽车详情
    car.display();

    return 0;
}
