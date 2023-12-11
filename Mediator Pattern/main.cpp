#include "MediatorPattern.h"

int main() {

    // 添加两个中介者：瓜子二手车、汽车之家
    ConcreteMediator guaziMediator("Guazi");
    ConcreteMediator autohomeMediator("Autohome");
  
    // 汽车之家联系两家供货商：特斯拉、蔚来
    ConcreteColleague teslaSupplier(&autohomeMediator, "Tesla");
    ConcreteColleague nioSupplier(&autohomeMediator, "NIO");
    autohomeMediator.addColleague(&teslaSupplier);
    autohomeMediator.addColleague(&nioSupplier);

    // 瓜子二手车联系两家供货商：小鹏汽车、比亚迪
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
