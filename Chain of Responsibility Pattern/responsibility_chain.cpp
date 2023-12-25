#include "responsibility.h"


int main() {
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
    std::cin.get();
    return 0;
}
