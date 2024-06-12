#include <iostream>
#include "edge.h"
#include "vertex.h"

using namespace std;

Vertex::Vertex(string new_name) {
    name = new_name;
    neighbors = new vector<Edge *>();
}

// must verify deconstructor works
Vertex::~Vertex(){
    for (Edge *edge : *neighbors) {
        delete edge;
    }
    // delete neighbors;
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

void Vertex::add_neighbor(int weight, Vertex *new_vertex){
    // research "this" more
    Edge *new_edge = new Edge(weight, this, new_vertex);

    neighbors->push_back(new_edge);
}

// this should have been moved to graph.cpp, but ran out of time. included <iostream> to solve
void Vertex::print_neighbors() {
    for(Edge *edge : *neighbors) {
        cout << " \n- " << "Name: " << edge->get_destination()->get_name() << ", weight: " << edge->get_weight() << " - ";
    }
}