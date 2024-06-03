#pragma once

#include <vector>
#include <string>
#include <sstream>


#include "edge.h"

using namespace std;

struct Edge;

struct Vertex { 
    string name; 
    // char name; 
    // int id; 
    // int num_edges;  
    // color; //surely this is an openGL setting lol    
    // width;// this line is also something with openGL. Perhaps two structs, one collision.

    std::vector<Edge *> *neighbors; 
    // DON'T FORGET DECONSTRUCTORS!
    Vertex(string new_name); // constructor (forgot this at fiorst lol. But I realized without any outside help apart from the compiler!)
    string get_name();
    vector<Edge *> *get_neighbors();
    int num_edges_attached();
    void add_neighbor(int weight, Vertex *new_vertex);

    // string Vertex::get_name();
    // std::vector<Edge *> *get_neighbors();
    
};  