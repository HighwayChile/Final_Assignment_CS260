#include "edge.h"
#include "vertex.h"

using namespace std;

Edge::Edge(int new_weight, Vertex *new_origin, Vertex *new_destination) {
    weight = new_weight;
    origin = new_origin;
    destination = new_destination;
}

Edge::~Edge(){
    delete destination;
    delete origin;
    delete &weight;
}

int Edge::get_weight(){
    return weight;
}


Vertex *Edge::get_origin(){
    return origin;
}


Vertex *Edge::get_destination(){
    // cout << "*Edge::get_destination(): " << destination << endl;
    return destination;
}
