#include <iostream>
#include <vector>

#include "vertex.h"
#include "edge.h"


using namespace std;


// Edge::Edge(int new_weight, int new_id, Vertex *new_origin, Vertex *new_destination) {
    // Constructor! Can be added to edge.cpp?
Edge::Edge(int new_weight, Vertex *new_origin, Vertex *new_destination) {
    weight = new_weight;
    origin = new_origin;
    destination = new_destination;
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

Vertex::Vertex(string new_name) {
    name = new_name;
    neighbors = new vector<Edge *>();
}

string Vertex::get_name(){
    return name;
}

vector<Edge *> *Vertex::get_neighbors(){
    return neighbors;
}

// I like this use-case. I commandeered it from Joseph Jess
int Vertex::num_edges_attached(){
    return neighbors->size();
}



// I am going to change how to add neighbors. I think. I don't understand this yet.
void Vertex::add_neighbor(int weight, Vertex *new_vertex){
    Edge *new_edge = new Edge(weight, this, new_vertex);

    neighbors->push_back(new_edge);
}



// the following snippet was copy/pasta I want to do something else, I think
// string Edge::to_string(){
//     return "(" + origin->get_name() + ", " + destination->get_name() + ", " + std::to_string(weight) + ")";
// }



// string Vertex::get_name(){
//     return name;
// }

// std::vector<Edge *> *Vertex::get_neighbors(){
//     return &neighbors;
// }



int main() {
    // create nodes

    Vertex vertex1("vertex1");
    Vertex vertex2("vertex2");
    Vertex vertex3("vertex3");

    vertex1.add_neighbor();
    // test line
    // cout << "A.name: " << A.name << endl;
    // cout << "A.id: " << A.id << endl;

    // create edges
    Edge edge1(1, &vertex1, &vertex2);
    Edge edge2(4, &vertex2, &vertex3);
    Edge edge3(5, &vertex3, &vertex1);

    cout << "edge1.get_origin(): " << edge1.get_origin() << endl;
    cout << "edge1.get_destination(): " << edge1.get_destination() << endl;
    cout << "edge1.get_weight(): " << edge1.get_weight() << endl;

    cout << "edge2.get_origin(): " << edge2.get_origin() << endl;
    cout << "edge2.get_destination(): " << edge2.get_destination() << endl;
    cout << "edge2.get_weight(): " << edge2.get_weight() << endl;

    cout << "vertex1.get_name(): " << vertex1.get_name() << endl;
    cout << "vertex1.get_neighbors(): " << vertex1.get_neighbors() << endl;
    cout << "vertex1.num_edges_attached(): " << vertex1.num_edges_attached() << endl;
    // cout << "add neighbor: " << vertex1.add_neighbor(2, *vertex2->name) << endl;
    cout << "vertex1.num_edges_attached(): " << vertex1.num_edges_attached() << endl;
    // test line
    // cout << "AB(weight, id, origin->name, destination->name): " 
    // << "(" << AB.weight << ", "<< AB.id << ", " << AB.origin->name 
    // << ", " << AB.destination->name << ")" << endl;



    // hook up the edges to the nodes


    cout << endl;
    system("pause");
    
    return 0;
}
