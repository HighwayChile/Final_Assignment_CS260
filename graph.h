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
        // I asked chat GPT and it said to use "vector<*xxxx>" to store my nodes/edges
        vector<Vertex *> vertices;

        // collection of edges
        vector<Edge *> edges;

    public:
        Graph(); //constructor
        ~Graph(); // deconstructor
        void add_vertex(string name);
        void add_edge(string edge_name, int weight, Vertex *origin, Vertex *destination);
        Vertex *find_vertex(string name);
        Edge *find_edge(Vertex *origin, Vertex *destination); // idk how to search for an edge without a name. 
        // edges could inherit name from origin and destination names.
        // i.e. - Alpha/Bravo could be one edge that goes between nodes 1 and 2.
        // bool is_path_extant(); //is this really needed?
        int get_num_edge();
        int get_num_vertex();
        void shortest_path();     // void shortest_path(Djikstra's Algo)  
        void min_span_tree();     // void min_span_tree(Kruskal's Algo) 

        int test_function();
};