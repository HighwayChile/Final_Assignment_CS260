#pragma once

#include <vector>
#include <string>
#include <sstream>


#include "edge.h"

using namespace std;

struct Edge;

struct Vertex { 
    string name; 
    // I have never used "vector" and I am still not 100% sure what it is doing. I understand vector mathematics.
    vector<Edge *> *neighbors;


    // DON'T FORGET DECONSTRUCTORS!
    Vertex(string new_name); // constructor (forgot this at first lol. But I realized without any outside help apart from the compiler!)
    ~Vertex();
    string get_name();
    vector<Edge *> *get_neighbors();
    int num_edges_attached();
    void add_neighbor(int weight, Vertex *new_vertex);
    void print_neighbors_to_screen();

    
};  