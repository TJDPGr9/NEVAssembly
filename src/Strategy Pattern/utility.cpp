#include <iostream>
#include"dijkstra.h"
#include"utility.h"
int** g_edge_road;
void init_road() {
    g_edge_road = new int* [15];
    for (int i = 0; i < 15; i++) {
        g_edge_road[i] = new int[3];
    }
    int backup[][3] = {//边的集合
        //起点，终点，权值
        {BEIJING, TIANJIN, 135},
        {TIANJIN, NANJING, 889},
        {NANJING, SHANGHAI, 302},
        {NANJING, WUHAN,540},
        {WUHAN, CHONGQING, 869},
        {CHENGDU, CHONGQING, 302},
        {CHENGDU, XI_AN, 742},
        {CHONGQING, XI_AN, 697},
        {GUANGZHOU,CHONGQING,1287},
        {SHENZHEN,GUANGZHOU,136},
        {WUHAN,GUANGZHOU,972},
        {SHANGHAI,SHENZHEN,1423},
        {BEIJING,WUHAN,1169},
        {BEIJING,XI_AN,1077},
        {XI_AN,WUHAN,738}
    };
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 3; j++) {
            g_edge_road[i][j] = backup[i][j];
        }
    }
}
int** g_edge_flight ;

void init_flights()
{
    g_edge_flight = new int* [41];
    for (int i = 0; i < 41; i++) {
        g_edge_flight[i] = new int[3] {0};
    }
    int backup[][3] = {
        { BEIJING, SHANGHAI, 1318 },
    {BEIJING, GUANGZHOU, 1874},
        {BEIJING, SHENZHEN, 1941},
        {BEIJING, CHONGQING, 1450},
        {BEIJING, NANJING, 899},
        {BEIJING, WUHAN, 1052},
        {BEIJING, CHENGDU, 1510},
        {BEIJING, XI_AN, 1120},
        {SHANGHAI, GUANGZHOU, 1213},
        {SHANGHAI, SHENZHEN, 1210},
        {SHANGHAI, TIANJIN, 1081},
        {SHANGHAI, CHONGQING, 1450},
        {SHANGHAI, WUHAN, 686},
        {SHANGHAI,CHENGDU,1600},
        {SHANGHAI,XI_AN,1200},
        {GUANGZHOU, NANJING, 1357},
        {GUANGZHOU, WUHAN, 837},
        {GUANGZHOU, CHENGDU, 1238},
        {GUANGZHOU, XI_AN, 1316},
        {GUANGZHOU, TIANJIN, 1817},
        {GUANGZHOU, CHONGQING, 978},
        {SHENZHEN, TIANJIN, 2200},
        {SHENZHEN, WUHAN, 1000},
        {SHENZHEN, CHENGDU, 1500},
        {SHENZHEN, XI_AN, 1600},
        {SHENZHEN, CHONGQING, 1500},
        {SHENZHEN, NANJING, 1200},
        {WUHAN,NANJING,500},
        {WUHAN,TIANJIN,1000},
        {WUHAN,CHONGQING,758},
        {WUHAN,XI_AN,654},
        {WUHAN,CHENGDU,980},
        {NANJING,CHENGDU,1600},
        {NANJING,TIANJIN,1000},
        {NANJING,CHONGQING,1500},
        {NANJING,XI_AN,1100},
        {TIANJIN, CHONGQING, 1443},
        {TIANJIN, CHENGDU, 1519},
        {TIANJIN, XI_AN, 921},
        {CHONGQING,XI_AN,578},
        {CHENGDU,XI_AN,603}
    };
    for (int i = 0; i < 41; i++) {
        for (int j = 0; j < 3; j++) {
            g_edge_flight[i][j] = backup[i][j];
        }
    }
}
int** g_edge_sail;
void init_sails() {
    g_edge_sail= new int* [6];
    for (int i = 0; i < 6; i++) {
        g_edge_sail[i] = new int[3];
    }
    int backup[][3] = {
        {TIANJIN, SHANGHAI, 1261},//681
        { SHANGHAI,SHENZHEN,1210 },
        { GUANGZHOU,SHENZHEN,136 },
        { SHANGHAI,NANJING,300 },
        { NANJING,WUHAN,500 },
        { WUHAN,CHONGQING,758 }
    };
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            g_edge_sail[i][j] = backup[i][j];
        }
    }
}
int** g_edge_rail;


void init_rail() {
    g_edge_rail = new int* [15];
    for (int i = 0; i < 15; i++) {
        g_edge_rail[i] = new int[3];
    }
    int backup[][3] = {//边的集合
        //起点，终点，权值
        {BEIJING, TIANJIN, 120},
        {TIANJIN, NANJING, 893},
        {NANJING, SHANGHAI, 301},
        {NANJING, WUHAN,539},
        {WUHAN, CHONGQING, 820},
        {CHENGDU, CHONGQING, 266},
        {CHENGDU, XI_AN, 658},
        {CHONGQING, XI_AN, 790},
        {GUANGZHOU,CHONGQING,1200},
        {SHENZHEN,GUANGZHOU,140},
        {WUHAN,GUANGZHOU,1068},
        {SHANGHAI,SHENZHEN,1680},
        {BEIJING,WUHAN,1229},
        {BEIJING,XI_AN,1216},
        {XI_AN,WUHAN,657}
    };
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 3; j++) {
            g_edge_rail[i][j] = backup[i][j];
        }
    }
    
    
}
int real_distance(TranportationMeans means, City departure, City destination) {
   return  _real_distance(means, cities[departure], cities[destination]);
}
int real_distance(TranportationMeans means, string departure, string destination) {
    return _real_distance(means, departure, destination);
}
int _real_distance(TranportationMeans means, string departure, string destination) {
    Dijkstra* digraph = new Dijkstra();
    switch (means) {
    case Air:
        init_flights();
        digraph->Create_graph(10, 41, g_edge_flight);
        break;
    case Railway:
        init_rail();
        digraph->Create_graph(10, 15, g_edge_rail);
        break;
    case Sail:
        init_sails();
        digraph->Create_graph(10, 6, g_edge_sail);
        break;
    case Road:
        init_road();
        digraph->Create_graph(10, 15, g_edge_road);
        break;
    }
    string mean[] = { "road","railway","marine","air" };
    digraph->Dijkstra_cpt(departure+ " City");
    int dis = digraph->Distance(departure + " City", destination + " City");
    if (dis == 99999) {
        cout << "There are no " << mean[means] << " route from " << departure << " to " << destination << endl;
    }
    else if (means == TranportationMeans::Sail) {
        cout << "The distance by "<< mean[means] <<"between " << departure << " and " << destination << " is " << dis / 1.852 << " n miles" << endl;
    }
    else {
        cout << "The distance by " << mean[means]<< "between  departure "<<departure<< " and " << destination << " is " << dis << "km" << endl;
    }
    switch (means) {
    case Air:
        for (int i = 0; i < 41; i++) {
            delete[] g_edge_flight[i];
        }
        break;
    case Railway:
        for (int i = 0; i < 15; i++) {
            delete[] g_edge_rail[i];
        }
        break;
    case Sail:
        for (int i = 0; i < 6; i++) {
            delete[] g_edge_sail[i];
        }
        break;
    case Road:
        for (int i = 0; i < 15; i++) {
            delete[] g_edge_road[i];
        }
        break;
    }
    
    return dis;
}
