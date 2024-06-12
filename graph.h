#pragma once

#include <string>
#include <vector>

#include "vertex.h"

using namespace std;

class Graph {
    private:
        // graph size
        int num_vertex; 
        int num_edge; 

        // collection of nodes
        vector<Vertex *> vertices;
        // collection of edges
        vector<Edge *> edges;

    public:
        Graph();
        ~Graph();
        void add_vertex(string name);
        void add_edge(int weight, Vertex *origin, Vertex *destination);

        Vertex *find_vertex(string name);
        Edge *find_edge(Vertex *origin, Vertex *destination); 

        int get_num_edge();
        int get_num_vertex();
        
        void shortest_path(string src_name);    // void shortest_path(Djikstra's Algo)  
        void min_span_tree();                   // void min_span_tree(Kruskal's Algo)

        int min_distance(vector<int> &dist, vector<bool> &spt_set);
        void print_solution(vector<int> &dist);

        void print_graph();
};