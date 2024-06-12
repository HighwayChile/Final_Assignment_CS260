#include "edge.h"
#include "vertex.h"

using namespace std;

// creating an edge creates a name
Edge::Edge(int new_weight, Vertex *new_origin, Vertex *new_destination) {
    weight = new_weight;
    origin = new_origin;
    destination = new_destination;
    // Edge inherits name from the vertices
    edge_name = origin->name + "/" + destination->name;
}

// Need fix this deconstructor - delete pointers?
Edge::~Edge(){
    // delete destination;
    // delete origin;
}

// these are methods to fetch the private attributes
int Edge::get_weight(){
    return weight;
}

Vertex *Edge::get_origin(){
    return origin;
}

Vertex *Edge::get_destination(){
    return destination;
}