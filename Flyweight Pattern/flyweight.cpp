#include "flyweight.h"
#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;

namespace Transport {
    //迭代器
    template <typename ItemType, typename CollectionType>
    CustomIterator<ItemType, CollectionType>::CustomIterator(CollectionType* collection, bool reverse)
        : collectionPtr(collection) {
        iterator = collectionPtr->begin();
    }

    template <typename ItemType, typename CollectionType>
    void CustomIterator<ItemType, CollectionType>::First() {
        iterator = collectionPtr->begin();
    }

    template <typename ItemType, typename CollectionType>
    void CustomIterator<ItemType, CollectionType>::Next() {
        iterator = collectionPtr->next(iterator);
    }

    template <typename ItemType, typename CollectionType>
    bool CustomIterator<ItemType, CollectionType>::IsDone() {
        return (iterator == collectionPtr->end());
    }

    template <typename ItemType, typename CollectionType>
    typename CustomIterator<ItemType, CollectionType>::IteratorType CustomIterator<ItemType, CollectionType>::Current() {
        return iterator;
    }

    //工厂仓库类
    FactoryStore::FactoryStore(const int& i, const int& s) //初始化
        : id(i), storage(s) {}

    int FactoryStore::getId() { //获取ID
        return id;
    }

    int FactoryStore::getStorgae() { //获取库存
        return storage;
    }

    void FactoryStore::moveStorage(const int& count) { //移出库存
        storage -= count;
    }

    //物流路线
    route::route(int s, int e)
        : src(s), end(e) {}

    bool route::operator<(const route& r) const {
        return (src < r.src) || (src == r.src && end < r.end);
    }

    //物流公司类
    TransportCompany::TransportCompany(const int& i, const std::string& s) //初始化
        : id(i), name(s) {}

    std::string TransportCompany::getName() { //获取名称
        return name;
    }

    int TransportCompany::getId() { //获取ID
        return id;
    }

    int TransportCompany::getTrunks(const route& r) { //获取运力信息
        return trunks[r];
    }

    void TransportCompany::addTrunk(const route& r, const int& n) { //添加运力
        trunks[r] = n;
    }

    //存储网表的边的信息
    TransportEdge::TransportEdge(const int& d)
        : dest(d), link(nullptr) {}

    //物流网点类
    TransportEnd::TransportEnd(const int& i, const std::string& n, const int& s)
        : id(i), name(n), storage(s), a(nullptr) {}

    int TransportEnd::getId() const { //获取ID
        return id;
    }

    TransportEdge* TransportEnd::getFirstEdge() const { //获取头指针
        return a;
    }

    std::string TransportEnd::getName() const { //获取网点名称
        return name;
    }

    void TransportEnd::addEdge(const int& d) { //添加新的边
        TransportEdge* current = a;
        TransportEdge* previous = nullptr;

        while (current != nullptr && current->dest != d) {
            previous = current;
            current = current->link;
        }

        if (current == nullptr) {
            current = new TransportEdge(d);
            if (previous != nullptr) {
                previous->link = current;
            }
            else {
                a = current;
            }
            current->dest = d;
        }
    }

    //物流网类
    TransportEndGraph::TransportEndGraph() {}

    TransportEnd TransportEndGraph::getValue(int id) const {
        for (TransportEnd vertex : vertices) {
            if (vertex.getId() == id) return vertex;
        }
    }

    std::vector<TransportEnd>::iterator TransportEndGraph::begin() { //返回图的起始迭代器
        return vertices.begin();
    }

    std::vector<TransportEnd>::iterator TransportEndGraph::end() { //返回图的结束迭代器
        return vertices.end();
    }

    std::vector<TransportEnd>::iterator TransportEndGraph::next(std::vector<TransportEnd>::iterator it) { //获取当前迭代器的下一个位置的迭代器
        std::vector<TransportEnd>::iterator tmp = vertices.begin();
        for (; tmp != vertices.end(); tmp++) {
            if (tmp->getId() == it->getId()) {
                tmp++;
                return tmp;
            }
        }
    }

    int TransportEndGraph::size() const { //返回当前顶点数
        return vertices.size();
    }

    bool TransportEndGraph::insertVertex(const TransportEnd& vertex) { //在图中插入一个顶点
        vertices.push_back(vertex);
        return true;
    }

    bool TransportEndGraph::insertEdge(const int& srcId, const int& endId) { //在图中插入一条边
        auto it = std::find_if(vertices.begin(), vertices.end(), [srcId](const TransportEnd& vertex) {
            return vertex.getId() == srcId;
            });

        if (it != vertices.end()) {
            it->addEdge(endId);
            return true;
        }
        return false;
    }

    void TransportEndGraph::iterate(const int& id) {  //遍历图，从初始点id开始遍历图
        std::stack<int> st;
        std::vector<int> flag;
        TransportEdge* ptEdge;
        int tmp = findId(id);

        for (int i = 0; i < vertices.size(); ++i) {
            flag.push_back(0);
        }

        st.push(tmp);
        while (!st.empty()) {
            tmp = st.top();
            std::cout << vertices.at(tmp).getId() << std::endl;
            st.pop();
            flag.at(tmp) = 1;
            ptEdge = vertices.at(tmp).getFirstEdge();
            while (ptEdge != nullptr) {
                tmp = findId(ptEdge->dest);
                if (flag.at(tmp) == 0) {
                    st.push(tmp);
                }
                ptEdge = ptEdge->link;
            }
        }
    }

    CustomIterator<TransportEnd, TransportEndGraph>* TransportEndGraph::CreateIterator() {
        return new CustomIterator<TransportEnd, TransportEndGraph>(this);
    }

    int TransportEndGraph::findId(const int& id) const { //根据id找到再vector中的位置
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices.at(i).getId() == id)
                return i;
        }
    }

    //顾问接口类
    bool Client::inputInt(int& x, const int& limit) {
        int n = 0;
        char c = 0;
        while (1) {
            std::cin >> x;
            std::cin.ignore(65535, '\n');
            if (n > 1) {
                std::cout << "请按提示正确输入！（若无反应请按回车键继续）" << std::endl << std::endl;
                c = getchar();
                n = 0;
            }
            if (x < 0 || std::cin.fail()) {
                std::cout << "请输入正确的正整数（按0取消操作）" << std::endl;
                std::cin.clear();
            }
            else if (x > limit) {
                std::cout << "输入的数据合理最大值是" << limit << "，请勿超过该限制！（按0取消操作）" << std::endl;
            }
            else if (x == 0) {
                return false;
            }
            else if (x > 0 && x <= limit) {
                return true;
            }
            std::cout << "请重新输入：";
            n++;
        }
    }

    void Client::show_factoryStore(const std::vector<FactoryStore>& fs) {
        std::cout << "现有仓库" << fs.size() << "个" << std::endl;
        std::cout << "存储情况如下：" << std::endl;
        for (FactoryStore i : fs) {
            std::cout << "仓库编号：" << i.getId() << "   ";
            std::cout << "库存容量：" << i.getStorgae() << "   " << std::endl;
        }
    }

    void Client::show_transportCom(const std::vector<TransportCompany>& tC) {
        std::cout << "现有物流公司" << tC.size() << "个，分别为：" << std::endl;
        for (TransportCompany i : tC) {
            std::cout << i.getId() << " " << i.getName() << std::endl;
        }
    }

    void Client::show_transportEnd(TransportEndGraph tEG) {
        std::cout << "现有物流网点" << tEG.size() << "个，分别为" << std::endl;
        CustomIterator<TransportEnd, TransportEndGraph>* it = tEG.CreateIterator();
        for (it->First(); !it->IsDone(); it->Next()) {
            TransportEnd currentEnd = *it->Current();
            std::cout  << currentEnd.getId() << " " << currentEnd.getName() << std::endl;
        }
    }

    void Client::trans_storage(vector<FactoryStore>& fs, TransportEndGraph& teg, vector<TransportCompany>& tc) {
        // 选择仓库和发货数量
        show_factoryStore(fs);//展示仓库信息
        int storeId, storeNum;
        cout << "请输入要发货的仓库编号：";
        inputInt(storeId, fs.size());
        vector<FactoryStore>::iterator iterStore;
        for (iterStore = fs.begin(); iterStore != fs.end(); iterStore++) { //迭代寻找仓库
            if (iterStore->getId() == storeId) {
                break;
            }
        }
        cout << "请输入发货的数量：";
        inputInt(storeNum, iterStore->getStorgae());

        // 选择收货网点
        show_transportEnd(teg);//展示网点信息
        int endId;
        cout << "请输入要收货的网点编号：";
        inputInt(endId, teg.size());

        // 选择物流公司
        show_transportCom(tc);//展示物流公司信息	
        while (1) {
            int cpyId;
            cout << "请输入选择的物流公司编号：";
            inputInt(cpyId, tc.size());
            int num = 0;
            vector<TransportCompany>::iterator itc;
            for (itc = tc.begin(); itc != tc.end(); itc++) {	//迭代寻找对应公司
                if (itc->getId() == cpyId) { break; }
            }
            num = itc->getTrunks(route(storeId, endId));//查看公司运力
            if (num * 1000 < storeNum) {				//运力不足
                cout << "物流公司共有" << num << "辆车船，" << "运力不足，输入1补足运力，输入0重新选择" << endl;
                int option;
                if (inputInt(option, 1)) {				//补足运力
                    itc->addTrunk(route(storeId, endId), storeNum / 100 + 1);
                    cout << "运力成功补足!" << endl;
                }
                else { continue; }						//重新选择
            }
            break;
        }
        // 发货
        iterStore->moveStorage(storeNum);

        cout << "发货成功！！!" << endl;
        cout << "按回车键继续..." << endl;
        while (getchar() != '\n') {}
        return;
    }
}  // namespace Transport

std::string IntToString(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
}

int main()
{
    // 初始化仓库
    vector<Transport::FactoryStore> fStores;
    for (int i = 1; i <= MAX_STORE_NUM; i++) {
        Transport::FactoryStore tmp(i, 1000);  //库存初始化为1000
        fStores.push_back(tmp);
    }
    // 初始化物流网点
    Transport::TransportEndGraph tsEndGraph;
    vector<string> endNames = { "上海", "武汉", "重庆", "珠江口", "海南岛" };
    for (int i = 1; i <= MAX_TRANSPORT_END_NUM; i++) {
        string endName = (i <= endNames.size()) ? endNames[i - 1] : "未命名网点" + IntToString(i);
        tsEndGraph.insertVertex(Transport::TransportEnd(i, endName));
    }
    tsEndGraph.insertEdge(1, 2);
    tsEndGraph.insertEdge(1, 3);
    tsEndGraph.insertEdge(1, 4);
    tsEndGraph.insertEdge(4, 5);
    // 初始化物流公司
    vector<Transport::TransportCompany> tsCompys;
    string tmp = "中国远洋运输集团有限公司";
    tsCompys.push_back(Transport::TransportCompany(1, tmp));
    tmp = "中远汽车物流有限公司";
    tsCompys.push_back(Transport::TransportCompany(2, tmp));
    tmp = "中国海外运输有限公司";
    tsCompys.push_back(Transport::TransportCompany(3, tmp));
    tmp = "中集车辆运输有限公司";
    tsCompys.push_back(Transport::TransportCompany(4, tmp));
    tmp = "中国长航汽运集团有限公司";
    tsCompys.push_back(Transport::TransportCompany(5, tmp));
    tmp = "中国远洋汽车运输有限公司";
    tsCompys.push_back(Transport::TransportCompany(6, tmp));
    int option;
    while (1)
    {
        system("cls");
        cout << "===============物流运输===============" << endl;
        cout << "主菜单：" << endl;
        cout << "1.发货" << endl;
        cout << "0.退出" << endl;
        cout << "请选择需要的操作：";
        Transport::Client::inputInt(option, 1);
        switch (option) {
        case 1:	//发货
            Transport::Client::trans_storage(fStores, tsEndGraph, tsCompys);
            break;
        case 0:
            exit(0);
            break;
        default:
            break;
        }
    }
}
