#include "Dijkstra.h"
#include <stdio.h>
string cities[10] = {
    "Beijing",
    "Shanghai",
    "Guangzhou",
    "Shenzhen",
    "Tianjin",
    "Chongqing",
    "Nanjing",
    "Wuhan",
    "Chengdu",
    "Xian"
};
int g_nodeNum = 10;//顶点数量
int g_edgeNum = 15;//边的数量



Dijkstra::Dijkstra()
{

}

//析构函数
Dijkstra::~Dijkstra()
{
    delete[] node;                      //释放一维数组node内存
    for (int i = 0; i < MAX_VERNUM; i++)//释放二维数组adjmatrix内存
    {
        delete this->adjmatrix[i];
    }
    delete adjmatrix;
}

//创建图
void Dijkstra::Create_graph(int g_nodeNum,int g_edgeNum,int** g_edge)
{
    vernum = g_nodeNum;                    //初始化顶点数和边数
    node = new Node[MAX_VERNUM];              //保留顶点信息，其中共有MAX_VERNUM条边
    adjmatrix = new int* [MAX_VERNUM];         //数组一维长度为MAX_VERNUM
    for (int i = 0; i < MAX_VERNUM; i++)
    {
        adjmatrix[i] = new int[MAX_VERNUM];   //数组二维长度也为MAX_VERNUM
        for (int k = 0; k < MAX_VERNUM; k++)
        {
            adjmatrix[i][k] = MAX_VALUE;      //邻接矩阵初始化为无穷大
        }
    }

    for (int index = 0; index < g_edgeNum; index++)
    {
        //对邻接矩阵对应上的点赋值
        adjmatrix[g_edge[index][0]][g_edge[index][1]] = g_edge[index][2];
        adjmatrix[g_edge[index][1]][g_edge[index][0]] = g_edge[index][2];
    }

    for (int i = 0; i < this->vernum; i++)    //初始化node数组的编号
    {
        node[i].NodeName = cities[i]+" City";
    }
}
void Dijkstra::Dijkstra_cpt()
{
    for (int s = 0; s < 10; s++) {
        string from = cities[s]+" City";
        int f, i, j, k;
        for (f = 0; f < this->vernum; f++)
        {
            if (from.compare(node[f].NodeName) == 0)
                break;
        }
        for (i = 0; i < this->vernum; i++)//初始化node数组
        {
            node[i].path = from + "-->" + node[i].NodeName;
            node[i].next_Node.clear();
            node[i].next_Node.push_back(node[i].NodeName);
            node[i].value = adjmatrix[f][i];
            node[i].visit = false;
        }
        node[f].value = 0;                //设置起点到起点的路径为0
        node[f].visit = true;

        for (i = 1; i < this->vernum; i++)//计算剩余的顶点的最短路径
        {
            int temp = 0;                 //temp用于保存当前node数组中最小的那个下标
            int min = MAX_VALUE;          //min记录的当前的最小值
            for (j = 0; j < this->vernum; j++)
            {
                if (!node[j].visit && node[j].value < min)
                {
                    min = node[j].value;
                    temp = j;
                }
            }
            node[temp].visit = true;      //把temp对应的顶点加入到已经找到的最短路径的集合中
            for (k = 0; k < this->vernum; k++)
            {
                //起点到T的最短路径 + T到T的邻接顶点P的权值  < 当前记录起点到P的最短路径
                if (!node[k].visit && adjmatrix[temp][k] != MAX_VALUE && (node[temp].value + adjmatrix[temp][k]) < node[k].value)
                {
                    node[k].path = node[temp].path + "-->" + node[k].NodeName;
                    node[k].next_Node = node[temp].next_Node;
                    node[k].next_Node.push_back(node[k].NodeName);
                    node[k].value = node[temp].value + adjmatrix[temp][k];
                }
            }
        }
    }
}
//算法主体
void Dijkstra::Dijkstra_cpt(string from)
{
    int f, i, j, k;
    for (f = 0; f < this->vernum; f++)
    {
        if (from.compare(node[f].NodeName) == 0)
            break;
    }
    for (i = 0; i < this->vernum; i++)//初始化node数组
    {
        node[i].path = from + "-->" + node[i].NodeName;
        node[i].next_Node.clear();
        node[i].next_Node.push_back(node[i].NodeName);
        node[i].value = adjmatrix[f][i];
        node[i].visit = false;
    }
    node[f].value = 0;                //设置起点到起点的路径为0
    node[f].visit = true;

    for (i = 1; i < this->vernum; i++)//计算剩余的顶点的最短路径
    {
        int temp = 0;                 //temp用于保存当前node数组中最小的那个下标
        int min = MAX_VALUE;          //min记录的当前的最小值
        for (j = 0; j < this->vernum; j++)
        {
            if (!node[j].visit && node[j].value < min)
            {
                min = node[j].value;
                temp = j;
            }
        }
        node[temp].visit = true;      //把temp对应的顶点加入到已经找到的最短路径的集合中
        for (k = 0; k < this->vernum; k++)
        {
            //起点到T的最短路径 + T到T的邻接顶点P的权值  < 当前记录起点到P的最短路径
            if (!node[k].visit && adjmatrix[temp][k] != MAX_VALUE && (node[temp].value + adjmatrix[temp][k]) < node[k].value)
            {
                node[k].path = node[temp].path + "-->" + node[k].NodeName;
                node[k].next_Node = node[temp].next_Node;
                node[k].next_Node.push_back(node[k].NodeName);
                node[k].value = node[temp].value + adjmatrix[temp][k];
            }
        }
    }
    //Display_table(from);
}

//输出路由表
void Dijkstra::Display_table(string from)
{
    int i;
    bool flag = false;
    for (i = 0; i < this->vernum; i++)
    {
        if (from.compare(node[i].NodeName) == 0)
            flag = true;
    }
    if (flag == false)
        printf("can not found node\n");
    else
    {
        printf("start:%s\n", from.c_str());
        for (i = 0; i < this->vernum; i++)
        {
            clog << "dest:" << node[i].NodeName << "  ";
            printf("next:%s,value:%d\n", node[i].next_Node.at(0).c_str(), node[i].value);
        }
    }
    clog << endl;
}
int Dijkstra::Distance(string from,string to)
{
    int i,j;

    for (i = 0; i < this->vernum; i++)
    {
        if (from.compare(node[i].NodeName) == 0) {
            break;
        }
    }
    for (j = 0; j < this->vernum; j++)
    {
        if (to.compare(node[j].NodeName) == 0) {
            break;
        }
    }
    if(i==this->vernum||j==this->vernum)
        printf("can not found node\n");
    else
    {
        printf("start:%s\n", from.c_str());
        cout << "dest:" << node[j].NodeName << "  ";
        printf("next:%s,value:%d\n", node[j].next_Node.at(0).c_str(), node[j].value);
    }
    cout << endl;
    return node[j].value;
}
//添加边
void Dijkstra::Modify_edge(string from, string to, int value)
{
    int f, t;
    for (f = 0; f < this->vernum; f++)    //找到起点对应的数组坐标
    {
        if (from.compare(node[f].NodeName) == 0)
            break;
    }
    for (t = 0; t < this->vernum; t++)    //找到终点对应的数组坐标
    {
        if (to.compare(node[t].NodeName) == 0)
            break;
    }
    adjmatrix[f][t] = value;              //对邻接矩阵对应上的点赋值
}

//添加顶点
void Dijkstra::Add_node(string nodename)
{
    node[vernum].NodeName = nodename;
    this->vernum++;
}

//删除顶点
void Dijkstra::Del_node(string r1)
{
    int r2, i, j, count = 0;
    for (r2 = 0; r2 < this->vernum; r2++)
    {
        if (r1.compare(node[r2].NodeName) == 0)
            break;
    }
    for (i = 0; i < this->vernum; i++)  //统计与删除的顶点相关的边数
    {
        if (adjmatrix[r2][i] != MAX_VALUE)
            count++;
    }

    for (i = 0; i < this->vernum; i++)    //调整邻接矩阵
    {
        for (j = 0; j < this->vernum; j++)//将邻接矩阵向内紧缩
        {
            if (i > r2 && j > r2)        //调整右下角部分
                adjmatrix[i - 1][j - 1] = adjmatrix[i][j];
            else if (i > r2)             //调整右上角部分
                adjmatrix[i - 1][j] = adjmatrix[i][j];
            else if (j > r2)             //调整左下角部分
                adjmatrix[i][j - 1] = adjmatrix[i][j];
        }
    }
    for (i = 0; i < this->vernum; i++)
    {
        adjmatrix[this->vernum][i] = MAX_VALUE;
        adjmatrix[i][this->vernum] = MAX_VALUE;
    }

    for (i = r2; i < this->vernum - 1; i++)//调整顶点数组值
        node[i] = node[i + 1];
    this->vernum--;
}

