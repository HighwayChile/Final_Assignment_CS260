#include "edge.h"
#include "vertex.h"
#include <string>

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
    return destination;
}


string create_name(Vertex *origin, Vertex *destination) {

    string edge_name = origin->name + "/" + destination->name;
    // return edge_name;
    cout << "\n THIS IS THE EDGE NAME: " << edge_name << "\n" << endl;
    return edge_name;
}