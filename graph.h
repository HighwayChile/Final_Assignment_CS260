#pragma once

#include <string>
#include <vector>

#include "vertex.h"

using namespace std;

class Graph {
    private:
        int num_vertex;  // size of vertices
        int num_edge;    // size of edges

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
        // could add find_edge_string to make searching easier/programming more difficult

        int get_num_edge();
        int get_num_vertex();
        
        void shortest_path();     // void shortest_path(Djikstra's Algo)  
        void min_span_tree();     // void min_span_tree(Kruskal's Algo) 

        void print_graph();

};