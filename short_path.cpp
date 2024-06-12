#include <iostream>
#include <limits.h>
#include <limits>

#include "graph.cpp"
#include "vertex.h"
#include "edge.h"
#include "graph.h"

using namespace std;


using Graph = vector<vector<int>>;

int min_distance(int dist[], bool spt_set[], int num_vertex) {
    int min = INT_MAX, min_index;

    for(int v = 0; v < num_vertex; v++)
        if(spt_set[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}


void print_solution(int dist[], int num_vertex) {
    cout << "Vertex \t Distance from source" << endl;
    for(int i = 0; i < num_vertex; i++)
        cout << i << "\t\t\t\t" << dist[i] << endl;
}


// void shortest_path(int graph[][V], int src) {
void shortest_path(const Graph &graph, int src) {
    int num_vertex = graph.size();

    int *dist = new int[num_vertex];
    bool *spt_set = new bool[num_vertex];

    for(int i = 0; i < num_vertex; i++) 
    dist[i] = INT_MAX, spt_set[i] = false;

    dist[src] = 0;

    for(int count = 0; count < num_vertex - 1; count++) {
        int u = min_distance(dist, spt_set, num_vertex);
        spt_set[u] = true;

        for(int v = 0; v < num_vertex; v++)
            if(!spt_set[v] && graph[u][v] && dist[u] != INT_MAX 
            && dist[u] + graph[u][v] < dist[v])
            dist[v] = dist[u] +graph[u][v];
    }
    print_solution(dist, num_vertex);
}




// // SHORTERST PATH
// // // https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/#
// int min_distance(int dist[], bool spt_set[], int num_vertex) {
//     int min = INT_MAX, min_index;

//     for(int v = 0; v < num_vertex; v++)
//         if(spt_set[v] == false && dist[v] <= min)
//             min = dist[v], min_index = v;

//     return min_index;
// }


// void print_solution(int dist[], int num_vertex) {
//     cout << "Vertex \t Distance from source" << endl;
//     for(int i = 0; i < num_vertex; i++)
//         cout << i << "\t\t\t\t" << dist[i] << endl;
// }


// // void shortest_path(int graph[][V], int src) {
// void Graph::shortest_path(const Graph &graph, int src) {
//     int num_vertex = graph.size();

//     int *dist = new int[num_vertex];
//     bool *spt_set = new bool[num_vertex];

//     for(int i = 0; i < num_vertex; i++) 
//     dist[i] = INT_MAX, spt_set[i] = false;

//     dist[src] = 0;

//     for(int count = 0; count < num_vertex - 1; count++) {
//         int u = min_distance(dist, spt_set, num_vertex);
//         spt_set[u] = true;

//         for(int v = 0; v < num_vertex; v++)
//             if(!spt_set[v] && graph[u][v] && dist[u] != INT_MAX 
//             && dist[u] + graph[u][v] < dist[v])
//             dist[v] = dist[u] +graph[u][v];
//     }
//     print_solution(dist, num_vertex);
// }