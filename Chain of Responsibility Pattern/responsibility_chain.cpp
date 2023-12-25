#include "responsibility.h"
#ifdef _WIN32
#include<Windows.h>
#endif
int main() {
#ifdef _WIN32
    SetConsoleCP(936);
    SetConsoleOutputCP(936);
#endif
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
