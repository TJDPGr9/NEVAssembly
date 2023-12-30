#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#define MAX_VERNUM 20//最大顶点数
#define MAX_VALUE 99999//最大权值
using namespace std;
#define BEIJING 0
#define SHANGHAI 1
#define GUANGZHOU 2
#define SHENZHEN 3
#define TIANJIN 4
#define CHONGQING 5
#define NANJING 6
#define WUHAN 7
#define CHENGDU 8
#define XI_AN 9
extern string cities[10];
enum City
{
    Beijing,
    Shanghai,
    Guangzhou,
    Shenzhen,
    Tianjin,
    Chongqing,
    Nanjing,
    Wuhan,
    Chengdu,
    Xian,
};

// 汽车网络





//顶点
struct Node
{
    string path;           //路径
    string NodeName;       //节点名字
    vector<string> next_Node;//从起点开始到终点所经过的节点，不包括起点
    int value;             //路径权值
    bool visit;            //是否访问过
    Node()
    {
        visit = false;
        value = 0;
        NodeName = "";
        next_Node.clear();
        path = "";
    }
};

class Dijkstra
{
public:
    Dijkstra();
    ~Dijkstra();

    void Create_graph(int g_nodeNum, int g_edgeNum, int** g_edge);                    //创建图
    void Dijkstra_cpt(string from);         //迪斯拉算法求最短路径
    void Dijkstra_cpt();
    int Distance(string from, string to);
    void Display_table(string from);        //输出路由表
    void Modify_edge(string from, string to, int value);                        //修改边
    void Add_node(string nodename);                      //添加顶点
    void Del_node(string r1);                      //删除顶点
private:
    int vernum;                             //图的顶点个数
    int** adjmatrix;                        //邻接矩阵
    Node* node;                             //记录各个顶点最短路径的信息
};

#endif // DIJKSTRA_H

