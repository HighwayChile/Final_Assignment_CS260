#include <iostream>
#include "edge.h"
#include "vertex.h"



Vertex::Vertex(string new_name) {
    name = new_name;
    neighbors = new vector<Edge *>();
}

Vertex::~Vertex(){
    for (Edge *edge: *neighbors) {
        delete edge;
    }
    delete neighbors;
}


string Vertex::get_name(){
    return name;
}

vector<Edge *> *Vertex::get_neighbors(){
    return neighbors;
}

// I like this use-case. I got it from Joseph Jess
int Vertex::num_edges_attached(){
    return neighbors->size();
}



// I am going to change how to add neighbors. I think. I don't understand this yet.
void Vertex::add_neighbor(int weight, Vertex *new_vertex){
    Edge *new_edge = new Edge(weight, this, new_vertex);

    neighbors->push_back(new_edge);
}

void Vertex::print_neighbors() {
    for(Edge *edge : *neighbors) {
        cout << " - " << "Name: " << edge->get_destination()->get_name() << ", weight: " << edge->get_weight() << " - ";
    }
}


