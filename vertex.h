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
    int id; 
    // int num_edges;  
    // color; //surely this is an openGL setting lol    
    // width;// this line is also something with openGL. Perhaps two structs, one collision.

    std::vector<Edge *> neighbors; 
};  