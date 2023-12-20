#pragma once
#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <sstream>

#define MAX_STORE_NUM 3
#define MAX_TRANSPORT_END_NUM 5

namespace Transport {
    // 迭代器
    template <typename ItemType, typename CollectionType>
    class CustomIterator {
    public:
        typedef typename std::vector<ItemType>::iterator IteratorType;
        CustomIterator(CollectionType* collection, bool reverse = false);
        void First();
        void Next();
        bool IsDone();
        IteratorType Current();

    private:
        CollectionType* collectionPtr;
        IteratorType iterator;
    };

    // 工厂仓库类
    class FactoryStore {
    public:
        FactoryStore(const int& i, const int& s = 0);
        int getId();
        int getStorgae();
        void moveStorage(const int& count);

    private:
        int id;        // 仓库编号
        int storage;    // 仓库库存
    };

    // 物流路线结构体
    struct route {
        route(int s = 0, int e = 0);
        int src; // 起点：仓库编号
        int end; // 终点：网点编号
        bool operator<(const route& r) const;
    };

    // 物流公司类
    class TransportCompany {
    public:
        TransportCompany(const int& i, const std::string& s);
        std::string getName();
        int getId();
        int getTrunks(const route& r);
        void addTrunk(const route& r, const int& n);

    private:
        int id; // 公司编号
        std::string name; // 物流公司名称
        std::map<route, int> trunks; // 车池:<运输路线,货车数量>
    };

    // 存储网表的边的信息
    struct TransportEdge {
        TransportEdge(const int& d = 0);
        int dest;
        TransportEdge* link;
    };

    // 物流网点类
    class TransportEnd {
    public:
        TransportEnd(const int& i, const std::string& n, const int& s = 0);
        int getId()const;
        TransportEdge* getFirstEdge()const;
        std::string getName() const;
        void addEdge(const int& d);

    private:
        int id; // 网点编号
        std::string name;  // 网点名称
        int storage; // 网点库存
        TransportEdge* a; // 边的头指针
    };

    // 物流网类:物流网的联通状况
    class TransportEndGraph {
    public:
        TransportEndGraph();
        TransportEnd getValue(int id) const;
        std::vector<TransportEnd>::iterator begin();
        std::vector<TransportEnd>::iterator end();
        std::vector<TransportEnd>::iterator next(std::vector<TransportEnd>::iterator it);
        int size()const;
        bool insertVertex(const TransportEnd& vertex);
        bool insertEdge(const int& srcId, const int& endId);
        void iterate(const int& id);
        CustomIterator<TransportEnd, TransportEndGraph>* CreateIterator();

    private:
        std::vector<TransportEnd> vertices; // 存储图的邻接表结构
        int findId(const int& id)const;
        friend class TransportEndGraphIterator;
    };

    // 顾问接口类
    class Client {
    public:
        static bool inputInt(int& x, const int& limit = 10);
        static void show_factoryStore(const std::vector<FactoryStore>& fs);
        static void show_transportCom(const std::vector<TransportCompany>& tC);
        static void show_transportEnd(TransportEndGraph tEG);
        static void trans_storage(std::vector<FactoryStore>& fs, TransportEndGraph& teg, std::vector<TransportCompany>& tc);
    };

    //std::string IntToString(int num);
}

#endif // TRANSPORT_H
