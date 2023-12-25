#include "responsibility.h"


int main() {
    // 创建责任链
    SupplierA supplierA;
    SupplierB supplierB;
    SupplierC supplierC;

    supplierA.setNextSupplier(&supplierB);
    supplierB.setNextSupplier(&supplierC);

    // 模拟购买原材料
    supplierA.processMaterial("锂电池");
    supplierA.processMaterial("车体骨架");
    supplierA.processMaterial("方向盘");
    supplierA.processMaterial("座椅");
    std::cin.get();
    return 0;
}
