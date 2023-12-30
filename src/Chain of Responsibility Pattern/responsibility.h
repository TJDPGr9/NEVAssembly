#include <iostream>
#include <string>

// 抽象处理者
class Supplier {
public:
    virtual void processMaterial(const std::string& material) = 0;
    virtual ~Supplier() {}
};

// 具体处理者A
class SupplierA : public Supplier {
public:
    void processMaterial(const std::string& material) override {
        if (material == "锂电池") {
            std::cout << "供应商A处理了锂电池" << std::endl;
        }
        else if (nextSupplier != nullptr) {
            nextSupplier->processMaterial(material);
        }
        else {
            std::cout << "没有供应商能够处理材料" << material << std::endl;
        }
    }

    void setNextSupplier(Supplier* supplier) {
        nextSupplier = supplier;
    }

private:
    Supplier* nextSupplier = nullptr;
};

// 具体处理者B
class SupplierB : public Supplier {
public:
    void processMaterial(const std::string& material) override {
        if (material == "车体骨架") {
            std::cout << "供应商B处理了车体骨架" << std::endl;
        }
        else if (nextSupplier != nullptr) {
            nextSupplier->processMaterial(material);
        }
        else {
            std::cout << "没有供应商能够处理材料" << material << std::endl;
        }
    }

    void setNextSupplier(Supplier* supplier) {
        nextSupplier = supplier;
    }

private:
    Supplier* nextSupplier = nullptr;
};

// 具体处理者C
class SupplierC : public Supplier {
public:
    void processMaterial(const std::string& material) override {
        if (material == "方向盘") {
            std::cout << "供应商C处理了方向盘" << std::endl;
        }
        else if (nextSupplier != nullptr) {
            nextSupplier->processMaterial(material);
        }
        else {
            std::cout << "没有供应商能够处理材料" << material << std::endl;
        }
    }

    void setNextSupplier(Supplier* supplier) {
        nextSupplier = supplier;
    }

private:
    Supplier* nextSupplier = nullptr;
};
