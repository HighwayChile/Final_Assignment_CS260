#pragma once

#include <vector>
#include <string>

using namespace std;

struct Edge;

// struct with attributes
struct Vertex { 
    string name; 
    vector<Edge *> *neighbors;

    Vertex(string new_name);
    string get_name();
    vector<Edge *> *get_neighbors();
    int num_edges_attached();
    void add_neighbor(int weight, Vertex *new_vertex);
    void print_neighbors();
};  