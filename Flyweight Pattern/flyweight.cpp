#include "flyweight.h"
#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;

namespace Transport {
    //������
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

    //�����ֿ���
    FactoryStore::FactoryStore(const int& i, const int& s) //��ʼ��
        : id(i), storage(s) {}

    int FactoryStore::getId() { //��ȡID
        return id;
    }

    int FactoryStore::getStorgae() { //��ȡ���
        return storage;
    }

    void FactoryStore::moveStorage(const int& count) { //�Ƴ����
        storage -= count;
    }

    //����·��
    route::route(int s, int e)
        : src(s), end(e) {}

    bool route::operator<(const route& r) const {
        return (src < r.src) || (src == r.src && end < r.end);
    }

    //������˾��
    TransportCompany::TransportCompany(const int& i, const std::string& s) //��ʼ��
        : id(i), name(s) {}

    std::string TransportCompany::getName() { //��ȡ����
        return name;
    }

    int TransportCompany::getId() { //��ȡID
        return id;
    }

    int TransportCompany::getTrunks(const route& r) { //��ȡ������Ϣ
        return trunks[r];
    }

    void TransportCompany::addTrunk(const route& r, const int& n) { //�������
        trunks[r] = n;
    }

    //�洢����ıߵ���Ϣ
    TransportEdge::TransportEdge(const int& d)
        : dest(d), link(nullptr) {}

    //����������
    TransportEnd::TransportEnd(const int& i, const std::string& n, const int& s)
        : id(i), name(n), storage(s), a(nullptr) {}

    int TransportEnd::getId() const { //��ȡID
        return id;
    }

    TransportEdge* TransportEnd::getFirstEdge() const { //��ȡͷָ��
        return a;
    }

    std::string TransportEnd::getName() const { //��ȡ��������
        return name;
    }

    void TransportEnd::addEdge(const int& d) { //����µı�
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

    //��������
    TransportEndGraph::TransportEndGraph() {}

    TransportEnd TransportEndGraph::getValue(int id) const {
        for (TransportEnd vertex : vertices) {
            if (vertex.getId() == id) return vertex;
        }
    }

    std::vector<TransportEnd>::iterator TransportEndGraph::begin() { //����ͼ����ʼ������
        return vertices.begin();
    }

    std::vector<TransportEnd>::iterator TransportEndGraph::end() { //����ͼ�Ľ���������
        return vertices.end();
    }

    std::vector<TransportEnd>::iterator TransportEndGraph::next(std::vector<TransportEnd>::iterator it) { //��ȡ��ǰ����������һ��λ�õĵ�����
        std::vector<TransportEnd>::iterator tmp = vertices.begin();
        for (; tmp != vertices.end(); tmp++) {
            if (tmp->getId() == it->getId()) {
                tmp++;
                return tmp;
            }
        }
    }

    int TransportEndGraph::size() const { //���ص�ǰ������
        return vertices.size();
    }

    bool TransportEndGraph::insertVertex(const TransportEnd& vertex) { //��ͼ�в���һ������
        vertices.push_back(vertex);
        return true;
    }

    bool TransportEndGraph::insertEdge(const int& srcId, const int& endId) { //��ͼ�в���һ����
        auto it = std::find_if(vertices.begin(), vertices.end(), [srcId](const TransportEnd& vertex) {
            return vertex.getId() == srcId;
            });

        if (it != vertices.end()) {
            it->addEdge(endId);
            return true;
        }
        return false;
    }

    void TransportEndGraph::iterate(const int& id) {  //����ͼ���ӳ�ʼ��id��ʼ����ͼ
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

    int TransportEndGraph::findId(const int& id) const { //����id�ҵ���vector�е�λ��
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices.at(i).getId() == id)
                return i;
        }
    }

    //���ʽӿ���
    bool Client::inputInt(int& x, const int& limit) {
        int n = 0;
        char c = 0;
        while (1) {
            std::cin >> x;
            std::cin.ignore(65535, '\n');
            if (n > 1) {
                std::cout << "�밴��ʾ��ȷ���룡�����޷�Ӧ�밴�س���������" << std::endl << std::endl;
                c = getchar();
                n = 0;
            }
            if (x < 0 || std::cin.fail()) {
                std::cout << "��������ȷ������������0ȡ��������" << std::endl;
                std::cin.clear();
            }
            else if (x > limit) {
                std::cout << "��������ݺ������ֵ��" << limit << "�����𳬹������ƣ�����0ȡ��������" << std::endl;
            }
            else if (x == 0) {
                return false;
            }
            else if (x > 0 && x <= limit) {
                return true;
            }
            std::cout << "���������룺";
            n++;
        }
    }

    void Client::show_factoryStore(const std::vector<FactoryStore>& fs) {
        std::cout << "���вֿ�" << fs.size() << "��" << std::endl;
        std::cout << "�洢������£�" << std::endl;
        for (FactoryStore i : fs) {
            std::cout << "�ֿ��ţ�" << i.getId() << "   ";
            std::cout << "���������" << i.getStorgae() << "   " << std::endl;
        }
    }

    void Client::show_transportCom(const std::vector<TransportCompany>& tC) {
        std::cout << "����������˾" << tC.size() << "�����ֱ�Ϊ��" << std::endl;
        for (TransportCompany i : tC) {
            std::cout << i.getId() << " " << i.getName() << std::endl;
        }
    }

    void Client::show_transportEnd(TransportEndGraph tEG) {
        std::cout << "������������" << tEG.size() << "�����ֱ�Ϊ" << std::endl;
        CustomIterator<TransportEnd, TransportEndGraph>* it = tEG.CreateIterator();
        for (it->First(); !it->IsDone(); it->Next()) {
            TransportEnd currentEnd = *it->Current();
            std::cout  << currentEnd.getId() << " " << currentEnd.getName() << std::endl;
        }
    }

    void Client::trans_storage(vector<FactoryStore>& fs, TransportEndGraph& teg, vector<TransportCompany>& tc) {
        // ѡ��ֿ�ͷ�������
        show_factoryStore(fs);//չʾ�ֿ���Ϣ
        int storeId, storeNum;
        cout << "������Ҫ�����Ĳֿ��ţ�";
        inputInt(storeId, fs.size());
        vector<FactoryStore>::iterator iterStore;
        for (iterStore = fs.begin(); iterStore != fs.end(); iterStore++) { //����Ѱ�Ҳֿ�
            if (iterStore->getId() == storeId) {
                break;
            }
        }
        cout << "�����뷢����������";
        inputInt(storeNum, iterStore->getStorgae());

        // ѡ���ջ�����
        show_transportEnd(teg);//չʾ������Ϣ
        int endId;
        cout << "������Ҫ�ջ��������ţ�";
        inputInt(endId, teg.size());

        // ѡ��������˾
        show_transportCom(tc);//չʾ������˾��Ϣ	
        while (1) {
            int cpyId;
            cout << "������ѡ���������˾��ţ�";
            inputInt(cpyId, tc.size());
            int num = 0;
            vector<TransportCompany>::iterator itc;
            for (itc = tc.begin(); itc != tc.end(); itc++) {	//����Ѱ�Ҷ�Ӧ��˾
                if (itc->getId() == cpyId) { break; }
            }
            num = itc->getTrunks(route(storeId, endId));//�鿴��˾����
            if (num * 1000 < storeNum) {				//��������
                cout << "������˾����" << num << "��������" << "�������㣬����1��������������0����ѡ��" << endl;
                int option;
                if (inputInt(option, 1)) {				//��������
                    itc->addTrunk(route(storeId, endId), storeNum / 100 + 1);
                    cout << "�����ɹ�����!" << endl;
                }
                else { continue; }						//����ѡ��
            }
            break;
        }
        // ����
        iterStore->moveStorage(storeNum);

        cout << "�����ɹ�����!" << endl;
        cout << "���س�������..." << endl;
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
    // ��ʼ���ֿ�
    vector<Transport::FactoryStore> fStores;
    for (int i = 1; i <= MAX_STORE_NUM; i++) {
        Transport::FactoryStore tmp(i, 1000);  //����ʼ��Ϊ1000
        fStores.push_back(tmp);
    }
    // ��ʼ����������
    Transport::TransportEndGraph tsEndGraph;
    vector<string> endNames = { "�Ϻ�", "�人", "����", "�齭��", "���ϵ�" };
    for (int i = 1; i <= MAX_TRANSPORT_END_NUM; i++) {
        string endName = (i <= endNames.size()) ? endNames[i - 1] : "δ��������" + IntToString(i);
        tsEndGraph.insertVertex(Transport::TransportEnd(i, endName));
    }
    tsEndGraph.insertEdge(1, 2);
    tsEndGraph.insertEdge(1, 3);
    tsEndGraph.insertEdge(1, 4);
    tsEndGraph.insertEdge(4, 5);
    // ��ʼ��������˾
    vector<Transport::TransportCompany> tsCompys;
    string tmp = "�й�Զ�����伯�����޹�˾";
    tsCompys.push_back(Transport::TransportCompany(1, tmp));
    tmp = "��Զ�����������޹�˾";
    tsCompys.push_back(Transport::TransportCompany(2, tmp));
    tmp = "�й������������޹�˾";
    tsCompys.push_back(Transport::TransportCompany(3, tmp));
    tmp = "�м������������޹�˾";
    tsCompys.push_back(Transport::TransportCompany(4, tmp));
    tmp = "�й��������˼������޹�˾";
    tsCompys.push_back(Transport::TransportCompany(5, tmp));
    tmp = "�й�Զ�������������޹�˾";
    tsCompys.push_back(Transport::TransportCompany(6, tmp));
    int option;
    while (1)
    {
        system("cls");
        cout << "===============��������===============" << endl;
        cout << "���˵���" << endl;
        cout << "1.����" << endl;
        cout << "0.�˳�" << endl;
        cout << "��ѡ����Ҫ�Ĳ�����";
        Transport::Client::inputInt(option, 1);
        switch (option) {
        case 1:	//����
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
