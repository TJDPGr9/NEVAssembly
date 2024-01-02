#include "responsibility.h"

namespace ResponsibilityChain {
    int test() {
        // 创建责任链
        SupplierA supplierA;
        SupplierB supplierB;
        SupplierC supplierC;

        supplierA.setNextSupplier(&supplierB);
        supplierB.setNextSupplier(&supplierC);

        // 模拟购买原材料
        supplierA.processMaterial("Lithium-ion battery");
        supplierA.processMaterial("Vehicle chassis");
        supplierA.processMaterial("Steering wheel");
        supplierA.processMaterial("Car seat");

        return 0;
    }
}
