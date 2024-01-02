#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<sstream>
using namespace std;

#define MAX_STORE_NUM 3
#define MAX_TRANSPORT_END_NUM 5
namespace Transport {
	//迭代器
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
	//工厂仓库类
	class FactoryStore {
	public:
		FactoryStore(const int& i, const int& s = 0) :id(i), storage(s) {}//初始化
		int getId() { //获取ID
			return id;
		}
		int getStorgae() { //获取库存
			return storage;
		}
		void moveStorage(const int& count) { //移出库存
			storage -= count;
		}
	private:
		int id;		//仓库编号
		int storage;//仓库库存
	};
	//物流路线结构体
	struct route {
		route(int s = 0, int e = 0) :src(s), end(e) {}
		int src; //起点：仓库编号
		int end; //终点：网点编号
		bool operator<(const route& r) const
		{
			return (src < r.src) || (src == r.src && end < r.src);
		}
	};
	//物流公司类
	class TransportCompany {
	public:
		TransportCompany(const int& i, const string& s) :id(i), name(s) {}; //初始化
		string getName() { //获取名称
			return name;
		}
		int getId() { //获取ID
			return id;
		}
		int getTrunks(const route& r) { //获取运力信息
			return trunks[r];
		}
		void addTrunk(const route& r, const int& n) { //添加运力
			trunks[r] = n;
		}
	private:
		int id; //公司编号
		string name; //物流公司名称
		map<route, int> trunks; //车池:<运输路线,货车数量>
	};

	//存储网表的边的信息
	struct TransportEdge {
		TransportEdge(const int& d = 0) {
			dest = d;
			link = NULL;
		}
		int dest;
		TransportEdge* link;
	};
	//物流网点类
	class TransportEnd {
	public:
		TransportEnd(const int& i, const string& n, const int& s = 0) :id(i), name(n), storage(s) { a = NULL; };//初始化
		int getId()const { //获取ID
			return id;
		}
		TransportEdge* getFirstEdge()const { //获取头指针
			return a;
		}
		string getName() const { //获取网点名称
			return name;
		}
		void addEdge(const int& d) { //添加新的边
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
		int id; //网点编号
		string name;  // 网点名称
		int storage; //网点库存
		TransportEdge* a; //边的头指针
	};
	//物流网类:物流网的联通状况
	class TransportEndGraph {
	public:
		TransportEndGraph() {};//初始化
		TransportEnd getValue(int id) const {
			for (TransportEnd vertex : vertices) {
				if (vertex.getId() == id) return vertex;
			}
		}
		vector<TransportEnd>::iterator begin() { //返回图的起始迭代器
			vector<TransportEnd>::iterator tmp = vertices.begin();
			return tmp;
		}
		vector<TransportEnd>::iterator end() {  //返回图的结束迭代器
			vector<TransportEnd>::iterator tmp = vertices.end();
			return tmp;
		}
		vector<TransportEnd>::iterator next(vector<TransportEnd>::iterator it) { //获取当前迭代器的下一个位置的迭代器
			vector<TransportEnd>::iterator tmp = vertices.begin();
			for (; tmp != vertices.end(); tmp++) {
				if (tmp->getId() == it->getId()) {
					tmp++;
					return tmp;
				}
			}
		}
		int size()const { //返回当前顶点数
			return vertices.size();
		}
		bool insertVertex(const TransportEnd& vertex) {	//在图中插入一个顶点
			vertices.push_back(vertex);
			return true;
		}
		bool insertEdge(const int& srcId, const int& endId) {	//在图中插入一条边
			auto it = std::find_if(vertices.begin(), vertices.end(), [srcId](const TransportEnd& vertex) {
				return vertex.getId() == srcId;
				});

			if (it != vertices.end()) {
				it->addEdge(endId);
				return true;
			}
			return false;
		}
		void iterate(const int& id) {  //遍历图，从初始点id开始遍历图
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
		vector<TransportEnd> vertices; //存储图的邻接表结构
		int findId(const int& id)const { //根据id找到再vector中的位置
			for (int i = 0; i < vertices.size(); i++) {
				if (vertices.at(i).getId() == id)
					return i;
			}
		}
		friend class TransportEndGraphIterator;
	};

	//顾问接口类
	class Client {
	public:
		static bool inputInt(int& x, const int& limit = 10) {	//读入int型正整数数据
			//x为需要读入的数据，limit为该数据的最大值（默认为10），若不符合要求则不断重新输入，直到输入正确返回true，或输入0返回false
			int n = 0;
			char c = 0;
			while (1) {
				cin >> x;
				cin.ignore(65535, '\n');
				if (n > 1) {	//判断是否陷入死循环，并给出输入提示
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
			//选择仓库和发货数量
			show_factoryStore(fs);//展示仓库信息
			int storeId, storeNum;
			std::cout << "Enter the warehouse ID to ship from: ";
			inputInt(storeId, fs.size());
			vector<FactoryStore>::iterator iterStore;
			for (iterStore = fs.begin(); iterStore != fs.end(); iterStore++) { //迭代寻找仓库
				if (iterStore->getId() == storeId) {
					break;
				}
			}
			std::cout << "Enter the quantity to be shipped: ";
			inputInt(storeNum, iterStore->getStorgae());

			//选择收货网点
			show_transportEnd(teg);//展示网点信息
			int endId;
			std::cout << "Enter the node ID to receive the shipment: ";
			inputInt(endId, teg.size());

			//选择物流公司
			show_transportCom(tc);//展示物流公司信息	
			while (1) {
				int cpyId;
				cout << "Enter the logistics company ID to choose: ";
				inputInt(cpyId, tc.size());
				int num = 0;
				vector<TransportCompany>::iterator itc;
				for (itc = tc.begin(); itc != tc.end(); itc++) {	//迭代寻找对应公司
					if (itc->getId() == cpyId) { break; }
				}
				num = itc->getTrunks(route(storeId, endId));//查看公司运力
				if (num * 1000 < storeNum) {				//运力不足
					std::cout << "The logistics company has " << num << " vehicles, " << "insufficient capacity. Enter 1 to supplement the capacity, or 0 to choose again" << std::endl;
					int option;
					if (inputInt(option, 1)) {				//补足运力
						itc->addTrunk(route(storeId, endId), storeNum / 100 + 1);
						std::cout << "Capacity successfully supplemented!" << std::endl;
					}
					else { continue; }						//重新选择
				}
				break;
			}
			//发货
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
	// 初始化仓库
	vector<Transport::FactoryStore> fStores;
	for (int i = 1; i <= MAX_STORE_NUM; i++) {
		Transport::FactoryStore tmp(i, 1000);  //库存初始化为1000
		fStores.push_back(tmp);
	}
	// 初始化物流网点
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
	// 初始化物流公司
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