#pragma once

#include <vector>
#include <string>
#include <sstream>

#include "edge.h"

using namespace std;

struct Edge;

struct Vertex { 
    string name; 
    // Research vector more
    vector<Edge *> *neighbors;

    Vertex(string new_name);
    ~Vertex();
    string get_name();
    vector<Edge *> *get_neighbors();
    int num_edges_attached();
    void add_neighbor(int weight, Vertex *new_vertex);
    void print_neighbors();
 
};  