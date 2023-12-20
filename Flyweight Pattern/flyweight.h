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
    // ������
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

    // �����ֿ���
    class FactoryStore {
    public:
        FactoryStore(const int& i, const int& s = 0);
        int getId();
        int getStorgae();
        void moveStorage(const int& count);

    private:
        int id;        // �ֿ���
        int storage;    // �ֿ���
    };

    // ����·�߽ṹ��
    struct route {
        route(int s = 0, int e = 0);
        int src; // ��㣺�ֿ���
        int end; // �յ㣺������
        bool operator<(const route& r) const;
    };

    // ������˾��
    class TransportCompany {
    public:
        TransportCompany(const int& i, const std::string& s);
        std::string getName();
        int getId();
        int getTrunks(const route& r);
        void addTrunk(const route& r, const int& n);

    private:
        int id; // ��˾���
        std::string name; // ������˾����
        std::map<route, int> trunks; // ����:<����·��,��������>
    };

    // �洢����ıߵ���Ϣ
    struct TransportEdge {
        TransportEdge(const int& d = 0);
        int dest;
        TransportEdge* link;
    };

    // ����������
    class TransportEnd {
    public:
        TransportEnd(const int& i, const std::string& n, const int& s = 0);
        int getId()const;
        TransportEdge* getFirstEdge()const;
        std::string getName() const;
        void addEdge(const int& d);

    private:
        int id; // ������
        std::string name;  // ��������
        int storage; // ������
        TransportEdge* a; // �ߵ�ͷָ��
    };

    // ��������:����������ͨ״��
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
        std::vector<TransportEnd> vertices; // �洢ͼ���ڽӱ�ṹ
        int findId(const int& id)const;
        friend class TransportEndGraphIterator;
    };

    // ���ʽӿ���
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
