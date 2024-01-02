#include <iostream>
#include <string>

// Abstract handler
class Supplier {
public:
    virtual void processMaterial(const std::string& material) = 0;
    virtual ~Supplier() {}
};

// Concrete handler A
class SupplierA : public Supplier {
public:
    void processMaterial(const std::string& material) override {
        if (material == "Lithium-ion battery") {
            std::cout << "Supplier A processed the lithium-ion battery." << std::endl;
        }
        else if (nextSupplier != nullptr) {
            nextSupplier->processMaterial(material);
        }
        else {
            std::cout << "No supplier was able to process the material." << material << std::endl;
        }
    }

    void setNextSupplier(Supplier* supplier) {
        nextSupplier = supplier;
    }

private:
    Supplier* nextSupplier = nullptr;
};

// Concrete handler B
class SupplierB : public Supplier {
public:
    void processMaterial(const std::string& material) override {
        if (material == "Vehicle chassis") {
            std::cout << "Supplier B processed the vehicle chassis." << std::endl;
        }
        else if (nextSupplier != nullptr) {
            nextSupplier->processMaterial(material);
        }
        else {
            std::cout << "No supplier was able to process the material." << material << std::endl;
        }
    }

    void setNextSupplier(Supplier* supplier) {
        nextSupplier = supplier;
    }

private:
    Supplier* nextSupplier = nullptr;
};

// Concrete handler C
class SupplierC : public Supplier {
public:
    void processMaterial(const std::string& material) override {
        if (material == "Steering wheel") {
            std::cout << "Supplier C processed the steering wheel." << std::endl;
        }
        else if (nextSupplier != nullptr) {
            nextSupplier->processMaterial(material);
        }
        else {
            std::cout << "No supplier was able to process the material." << material << std::endl;
        }
    }

    void setNextSupplier(Supplier* supplier) {
        nextSupplier = supplier;
    }

private:
    Supplier* nextSupplier = nullptr;
};
