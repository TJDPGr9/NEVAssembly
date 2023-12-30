#include <iostream>
#include <string>

// ��������
class Supplier {
public:
    virtual void processMaterial(const std::string& material) = 0;
    virtual ~Supplier() {}
};

// ���崦����A
class SupplierA : public Supplier {
public:
    void processMaterial(const std::string& material) override {
        if (material == "﮵��") {
            std::cout << "��Ӧ��A������﮵��" << std::endl;
        }
        else if (nextSupplier != nullptr) {
            nextSupplier->processMaterial(material);
        }
        else {
            std::cout << "û�й�Ӧ���ܹ��������" << material << std::endl;
        }
    }

    void setNextSupplier(Supplier* supplier) {
        nextSupplier = supplier;
    }

private:
    Supplier* nextSupplier = nullptr;
};

// ���崦����B
class SupplierB : public Supplier {
public:
    void processMaterial(const std::string& material) override {
        if (material == "����Ǽ�") {
            std::cout << "��Ӧ��B�����˳���Ǽ�" << std::endl;
        }
        else if (nextSupplier != nullptr) {
            nextSupplier->processMaterial(material);
        }
        else {
            std::cout << "û�й�Ӧ���ܹ��������" << material << std::endl;
        }
    }

    void setNextSupplier(Supplier* supplier) {
        nextSupplier = supplier;
    }

private:
    Supplier* nextSupplier = nullptr;
};

// ���崦����C
class SupplierC : public Supplier {
public:
    void processMaterial(const std::string& material) override {
        if (material == "������") {
            std::cout << "��Ӧ��C�����˷�����" << std::endl;
        }
        else if (nextSupplier != nullptr) {
            nextSupplier->processMaterial(material);
        }
        else {
            std::cout << "û�й�Ӧ���ܹ��������" << material << std::endl;
        }
    }

    void setNextSupplier(Supplier* supplier) {
        nextSupplier = supplier;
    }

private:
    Supplier* nextSupplier = nullptr;
};
