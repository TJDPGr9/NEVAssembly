#include "MediatorPattern.h"

int main() {

    // ��������н��ߣ����Ӷ��ֳ�������֮��
    ConcreteMediator guaziMediator("Guazi");
    ConcreteMediator autohomeMediator("Autohome");
  
    // ����֮����ϵ���ҹ����̣���˹����ε��
    ConcreteColleague teslaSupplier(&autohomeMediator, "Tesla");
    ConcreteColleague nioSupplier(&autohomeMediator, "NIO");
    autohomeMediator.addColleague(&teslaSupplier);
    autohomeMediator.addColleague(&nioSupplier);

    // ���Ӷ��ֳ���ϵ���ҹ����̣�С�����������ǵ�
    ConcreteColleague xiaopengSupplier(&guaziMediator, "Xiaopeng");
    ConcreteColleague bydSupplier(&guaziMediator, "BYD");
    guaziMediator.addColleague(&xiaopengSupplier);
    guaziMediator.addColleague(&bydSupplier);

    std::cout << "Purchasing Components from Tesla through Autohome:" << std::endl;
    autohomeMediator.sendMessage("Tesla", "Need Components from Tesla.");

    std::cout << "\nPurchasing Components from NIO through Autohome:" << std::endl;
    autohomeMediator.sendMessage("NIO", "Need Components from NIO.");

    std::cout << "\nPurchasing Components from Xiaopeng through Guazi:" << std::endl;
    guaziMediator.sendMessage("Xiaopeng", "Need Components from Xiaopeng.");

    std::cout << "\nPurchasing Components from BYD through Guazi:" << std::endl;
    guaziMediator.sendMessage("BYD", "Need Components from BYD.");

    return 0;
}
