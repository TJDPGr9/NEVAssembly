#include "responsibility.h"

namespace ResponsibilityChain {
    int test() {
        // ����������
        SupplierA supplierA;
        SupplierB supplierB;
        SupplierC supplierC;

        supplierA.setNextSupplier(&supplierB);
        supplierB.setNextSupplier(&supplierC);

        // ģ�⹺��ԭ����
        supplierA.processMaterial("﮵��");
        supplierA.processMaterial("����Ǽ�");
        supplierA.processMaterial("������");
        supplierA.processMaterial("����");

        return 0;
    }
}
