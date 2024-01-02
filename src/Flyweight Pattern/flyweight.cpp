#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<sstream>
using namespace std;

#define MAX_STORE_NUM 3
#define MAX_TRANSPORT_END_NUM 5
namespace Transport {
	//������
	template <typename ItemType, typename CollectionType>
	class CustomIterator {
	public:
		typedef typename std::vector<ItemType>::iterator IteratorType;
		CustomIterator(CollectionType* collection, bool reverse = false) : collectionPtr(collection) {
			iterator = collectionPtr->begin();
		}
		void First() {
			iterator = collectionPtr->begin();
		}
		void Next() {
			iterator = collectionPtr->next(iterator);
		}
		bool IsDone() {
			return (iterator == collectionPtr->end());
		}
		IteratorType Current() {
			return iterator;
		}
	private:
		CollectionType* collectionPtr;
		IteratorType iterator;
	};
	//�����ֿ���
	class FactoryStore {
	public:
		FactoryStore(const int& i, const int& s = 0) :id(i), storage(s) {}//��ʼ��
		int getId() { //��ȡID
			return id;
		}
		int getStorgae() { //��ȡ���
			return storage;
		}
		void moveStorage(const int& count) { //�Ƴ����
			storage -= count;
		}
	private:
		int id;		//�ֿ���
		int storage;//�ֿ���
	};
	//����·�߽ṹ��
	struct route {
		route(int s = 0, int e = 0) :src(s), end(e) {}
		int src; //��㣺�ֿ���
		int end; //�յ㣺������
		bool operator<(const route& r) const
		{
			return (src < r.src) || (src == r.src && end < r.src);
		}
	};
	//������˾��
	class TransportCompany {
	public:
		TransportCompany(const int& i, const string& s) :id(i), name(s) {}; //��ʼ��
		string getName() { //��ȡ����
			return name;
		}
		int getId() { //��ȡID
			return id;
		}
		int getTrunks(const route& r) { //��ȡ������Ϣ
			return trunks[r];
		}
		void addTrunk(const route& r, const int& n) { //�������
			trunks[r] = n;
		}
	private:
		int id; //��˾���
		string name; //������˾����
		map<route, int> trunks; //����:<����·��,��������>
	};

	//�洢����ıߵ���Ϣ
	struct TransportEdge {
		TransportEdge(const int& d = 0) {
			dest = d;
			link = NULL;
		}
		int dest;
		TransportEdge* link;
	};
	//����������
	class TransportEnd {
	public:
		TransportEnd(const int& i, const string& n, const int& s = 0) :id(i), name(n), storage(s) { a = NULL; };//��ʼ��
		int getId()const { //��ȡID
			return id;
		}
		TransportEdge* getFirstEdge()const { //��ȡͷָ��
			return a;
		}
		string getName() const { //��ȡ��������
			return name;
		}
		void addEdge(const int& d) { //����µı�
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
	private:
		int id; //������
		string name;  // ��������
		int storage; //������
		TransportEdge* a; //�ߵ�ͷָ��
	};
	//��������:����������ͨ״��
	class TransportEndGraph {
	public:
		TransportEndGraph() {};//��ʼ��
		TransportEnd getValue(int id) const {
			for (TransportEnd vertex : vertices) {
				if (vertex.getId() == id) return vertex;
			}
		}
		vector<TransportEnd>::iterator begin() { //����ͼ����ʼ������
			vector<TransportEnd>::iterator tmp = vertices.begin();
			return tmp;
		}
		vector<TransportEnd>::iterator end() {  //����ͼ�Ľ���������
			vector<TransportEnd>::iterator tmp = vertices.end();
			return tmp;
		}
		vector<TransportEnd>::iterator next(vector<TransportEnd>::iterator it) { //��ȡ��ǰ����������һ��λ�õĵ�����
			vector<TransportEnd>::iterator tmp = vertices.begin();
			for (; tmp != vertices.end(); tmp++) {
				if (tmp->getId() == it->getId()) {
					tmp++;
					return tmp;
				}
			}
		}
		int size()const { //���ص�ǰ������
			return vertices.size();
		}
		bool insertVertex(const TransportEnd& vertex) {	//��ͼ�в���һ������
			vertices.push_back(vertex);
			return true;
		}
		bool insertEdge(const int& srcId, const int& endId) {	//��ͼ�в���һ����
			auto it = std::find_if(vertices.begin(), vertices.end(), [srcId](const TransportEnd& vertex) {
				return vertex.getId() == srcId;
				});

			if (it != vertices.end()) {
				it->addEdge(endId);
				return true;
			}
			return false;
		}
		void iterate(const int& id) {  //����ͼ���ӳ�ʼ��id��ʼ����ͼ
			stack<int> st;
			vector<int> flag;
			TransportEdge* ptEdge;
			int tmp = findId(id);

			for (int i = 0; i < vertices.size(); ++i) {
				flag.push_back(0);
			}

			st.push(tmp);
			while (!st.empty()) {
				tmp = st.top();
				cout << vertices.at(tmp).getId() << endl;
				st.pop();
				flag.at(tmp) = 1;
				ptEdge = vertices.at(tmp).getFirstEdge();
				while (ptEdge != NULL) {
					tmp = findId(ptEdge->dest);
					if (flag.at(tmp) == 0) {
						st.push(tmp);
					}
					ptEdge = ptEdge->link;
				}
			}
		}
		CustomIterator<TransportEnd, TransportEndGraph>* CreateIterator() {
			return new CustomIterator<TransportEnd, TransportEndGraph>(this);
		}
	private:
		vector<TransportEnd> vertices; //�洢ͼ���ڽӱ�ṹ
		int findId(const int& id)const { //����id�ҵ���vector�е�λ��
			for (int i = 0; i < vertices.size(); i++) {
				if (vertices.at(i).getId() == id)
					return i;
			}
		}
		friend class TransportEndGraphIterator;
	};

	//���ʽӿ���
	class Client {
	public:
		static bool inputInt(int& x, const int& limit = 10) {	//����int������������
			//xΪ��Ҫ��������ݣ�limitΪ�����ݵ����ֵ��Ĭ��Ϊ10������������Ҫ���򲻶��������룬ֱ��������ȷ����true��������0����false
			int n = 0;
			char c = 0;
			while (1) {
				cin >> x;
				cin.ignore(65535, '\n');
				if (n > 1) {	//�ж��Ƿ�������ѭ����������������ʾ
					cout << "Please enter as prompted! (If there is no response, press Enter to continue)" << endl << endl;
					c = getchar();
					n = 0;
				}
				if (x < 0 || std::cin.fail()) {
					std::cout << "Please enter a correct positive integer (press 0 to cancel)" << std::endl;
					std::cin.clear();
				}
				else if (x > limit) {
					std::cout << "The reasonable maximum value for input is " << limit << ". Please do not exceed this limit! (Press 0 to cancel)" << std::endl;
				}
				else if (x == 0) {
					return false;
				}
				else if (x > 0 && x <= limit) {
					return true;
				}
				std::cout << "Please enter again: ";
				n++;
			}
		}
		static void show_factoryStore(const std::vector<FactoryStore>& fs) {
			std::cout << "Existing warehouses: " << fs.size() << std::endl;
			std::cout << "Storage situation is as follows:" << std::endl;
			for (FactoryStore i : fs) {
				std::cout << "Warehouse ID: " << i.getId() << "   ";
				std::cout << "Inventory capacity: " << i.getStorgae() << "   " << std::endl;
			}
		}

		static void show_transportCom(const std::vector<TransportCompany>& tC) {
			std::cout << "Existing logistics companies: " << tC.size() << ", as follows:" << std::endl;
			for (TransportCompany i : tC) { std::cout << i.getId() << " " << i.getName() << std::endl; }
		}

		static void show_transportEnd(TransportEndGraph tEG) {
			std::cout << "Existing logistics nodes: " << tEG.size() << ", as follows" << std::endl;
			CustomIterator<TransportEnd, TransportEndGraph>* it = tEG.CreateIterator();
			for (it->First(); !it->IsDone(); it->Next()) {
				TransportEnd currentEnd = *it->Current();
				std::cout << "ID: " << currentEnd.getId() << "  " << currentEnd.getName() << std::endl;
			}
		}

		static void trans_storage(vector<FactoryStore>& fs, TransportEndGraph& teg, vector<TransportCompany>& tc) {
			//ѡ��ֿ�ͷ�������
			show_factoryStore(fs);//չʾ�ֿ���Ϣ
			int storeId, storeNum;
			std::cout << "Enter the warehouse ID to ship from: ";
			inputInt(storeId, fs.size());
			vector<FactoryStore>::iterator iterStore;
			for (iterStore = fs.begin(); iterStore != fs.end(); iterStore++) { //����Ѱ�Ҳֿ�
				if (iterStore->getId() == storeId) {
					break;
				}
			}
			std::cout << "Enter the quantity to be shipped: ";
			inputInt(storeNum, iterStore->getStorgae());

			//ѡ���ջ�����
			show_transportEnd(teg);//չʾ������Ϣ
			int endId;
			std::cout << "Enter the node ID to receive the shipment: ";
			inputInt(endId, teg.size());

			//ѡ��������˾
			show_transportCom(tc);//չʾ������˾��Ϣ	
			while (1) {
				int cpyId;
				cout << "Enter the logistics company ID to choose: ";
				inputInt(cpyId, tc.size());
				int num = 0;
				vector<TransportCompany>::iterator itc;
				for (itc = tc.begin(); itc != tc.end(); itc++) {	//����Ѱ�Ҷ�Ӧ��˾
					if (itc->getId() == cpyId) { break; }
				}
				num = itc->getTrunks(route(storeId, endId));//�鿴��˾����
				if (num * 1000 < storeNum) {				//��������
					std::cout << "The logistics company has " << num << " vehicles, " << "insufficient capacity. Enter 1 to supplement the capacity, or 0 to choose again" << std::endl;
					int option;
					if (inputInt(option, 1)) {				//��������
						itc->addTrunk(route(storeId, endId), storeNum / 100 + 1);
						std::cout << "Capacity successfully supplemented!" << std::endl;
					}
					else { continue; }						//����ѡ��
				}
				break;
			}
			//����
			iterStore->moveStorage(storeNum);

			std::cout << "Shipment successful!!!" << std::endl;
			std::cout << "Press Enter to continue..." << std::endl;
			while (getchar() != '\n') {}
			return;
		}
	};
}

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
	vector<string> endNames = { "Shanghai", "Wuhan", "Chongqing", "Pearl River Estuary", "Hainan Island" };
	for (int i = 1; i <= MAX_TRANSPORT_END_NUM; i++) {
		string endName = (i <= endNames.size()) ? endNames[i - 1] : "Unnamed End" + IntToString(i);
		tsEndGraph.insertVertex(Transport::TransportEnd(i, endName));
	}
	tsEndGraph.insertEdge(1, 2);
	tsEndGraph.insertEdge(1, 3);
	tsEndGraph.insertEdge(1, 4);
	tsEndGraph.insertEdge(4, 5);
	// ��ʼ��������˾
	vector<Transport::TransportCompany> tsCompys;
	string tmp = "China COSCO Shipping Corporation Limited";
	tsCompys.push_back(Transport::TransportCompany(1, tmp));
	tmp = "COSCO Auto Logistics Co., Ltd.";
	tsCompys.push_back(Transport::TransportCompany(2, tmp));
	tmp = "China Ocean Shipping (Group) Company";
	tsCompys.push_back(Transport::TransportCompany(3, tmp));
	tmp = "CIMC Vehicles (Group) Co., Ltd.";
	tsCompys.push_back(Transport::TransportCompany(4, tmp));
	tmp = "China Changjiu Logistics Group Co., Ltd.";
	tsCompys.push_back(Transport::TransportCompany(5, tmp));
	tmp = "China COSCO Shipping Auto Transport Co., Ltd.";
	tsCompys.push_back(Transport::TransportCompany(6, tmp));
	int option;
	while (1)
	{
		system("cls");
		cout << "===============Logistics Transportation===============" << endl;
		cout << "Main Menu:" << endl;
		cout << "1. Ship Goods" << endl;
		cout << "0. Exit" << endl;
		cout << "Please select the desired operation: ";
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