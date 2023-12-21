#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include"dijkstra.h"
extern int** g_edge_road;
void init_road();
extern int** g_edge_flight;
void init_flights();
extern int** g_edge_sail;
void init_sails();
extern int** g_edge_rail;
void init_rail();
enum TranportationMeans
{
    Road,
    Railway,
    Sail,
    Air
};
int _real_distance(TranportationMeans means, string departure, string destination);
int real_distance(TranportationMeans means, City departure, City destination);
int real_distance(TranportationMeans means, string departure, string destination);
#endif UTILITY_H