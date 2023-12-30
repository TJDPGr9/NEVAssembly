#include <iostream>
#include <vector>
#include <memory>

// 抽象产品类 - 新能源汽车
class ElectricCar {
public:
    virtual void charge() const = 0;
    virtual ~ElectricCar() = default;
};

// 具体产品类 - 特斯拉
class Tesla : public ElectricCar {
public:
    void charge() const override {
        std::cout << "特斯拉汽车正在充电。。。" << std::endl;
    }
};

// 对象池类
class CarPool {
public:
    // 获取汽车对象
    std::shared_ptr<ElectricCar> getCar() {
        if (pool_.empty()) {
            // 如果池中没有对象，创建一个新对象
            return std::make_shared<Tesla>();
        } else {
            // 如果池中有对象，从池中取出并返回
            auto car = pool_.back();
            pool_.pop_back();
            return car;
        }
    }

    // 归还汽车对象到池中
    void returnCar(std::shared_ptr<ElectricCar> car) {
        pool_.push_back(car);
    }

private:
    std::vector<std::shared_ptr<ElectricCar>> pool_;
};

int main() {
    // 创建汽车池
    CarPool carPool;

    // 从池中获取汽车对象
    std::shared_ptr<ElectricCar> car1 = carPool.getCar();
    car1->charge();

    // 再次从池中获取汽车对象
    std::shared_ptr<ElectricCar> car2 = carPool.getCar();
    car2->charge();

    // 归还汽车对象到池中
    carPool.returnCar(car1);
    carPool.returnCar(car2);

    // 再次从池中获取汽车对象，此时应该是复用之前的对象
    std::shared_ptr<ElectricCar> car3 = carPool.getCar();
    car3->charge();

    return 0;
}
