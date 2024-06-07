#include <iostream>
#include <vector>
#include <limits>

#include "vertex.cpp"
#include "edge.cpp"
#include "vertex.h"
#include "edge.h"


using namespace std;


// Edge::Edge(int new_weight, int new_id, Vertex *new_origin, Vertex *new_destination) {
    // Constructor! Can be added to edge.cpp?
// Edge::Edge(int new_weight, Vertex *new_origin, Vertex *new_destination) {
//     weight = new_weight;
//     origin = new_origin;
//     destination = new_destination;
// }

// Edge::~Edge(){
//     delete[] destination;
//     delete[] origin;
//     // delete[] weight;
// }

// int Edge::get_weight(){
//     return weight;
// }


// Vertex *Edge::get_origin(){
//     return origin;
// }


// Vertex *Edge::get_destination(){
//     // cout << "*Edge::get_destination(): " << destination << endl;
//     return destination;
// }

// Vertex::Vertex(string new_name) {
//     name = new_name;
//     neighbors = new vector<Edge *>();
// }

// Vertex::~Vertex(){
//     for (Edge *edge: *neighbors) {
//         delete edge;
//     }
//     delete neighbors;
// }


// string Vertex::get_name(){
//     return name;
// }

// vector<Edge *> *Vertex::get_neighbors(){
//     return neighbors;
// }

// // I like this use-case. I got it from Joseph Jess
// int Vertex::num_edges_attached(){
//     return neighbors->size();
// }



// // I am going to change how to add neighbors. I think. I don't understand this yet.
// void Vertex::add_neighbor(int weight, Vertex *new_vertex){
//     Edge *new_edge = new Edge(weight, this, new_vertex);

//     neighbors->push_back(new_edge);
// }

// void Vertex::print_neighbors_to_screen() {
//     for(Edge *edge : *neighbors) {
//         cout << "Name: " << edge->get_destination()->get_name() << ", weight: " << edge->get_weight() << endl;
//     }
//     cout << endl;
// }



// the following snippet was copy/pasta I want to do something else, I think
// string Edge::to_string(){
//     return "(" + origin->get_name() + ", " + destination->get_name() + ", " + std::to_string(weight) + ")";
// }




int main() {
    // create nodes

    Vertex vertex1("vertex1");
    Vertex vertex2("vertex2");
    Vertex vertex3("vertex3");
    Vertex vertex4("vertex4");
    Vertex vertex5("vertex5");
    Vertex vertex6("vertex6");
    Vertex vertex7("vertex7");
    Vertex vertex8("vertex8");

    // vertex1.add_neighbor(3, edge1);
    // test line
    // cout << "A.name: " << A.name << endl;
    // cout << "A.id: " << A.id << endl;

    // create edges
    Edge edge1(1, &vertex1, &vertex2);
    Edge edge2(4, &vertex2, &vertex3);
    Edge edge3(5, &vertex3, &vertex1);
    Edge edge4(5, &vertex3, nullptr);

    // create vertices
    vertex1.add_neighbor(3, &vertex2);
    vertex1.add_neighbor(3, &vertex3);

    cout << "edge1.get_origin(): " << edge1.get_origin()->name << endl;
    cout << "edge1.get_destination(): " << edge1.get_destination()->name << endl;
    cout << "edge1.get_weight(): " << edge1.get_weight() << endl;

    cout << "edge2.get_origin(): " << edge2.get_origin()->name << endl;
    cout << "edge2.get_destination(): " << edge2.get_destination()->name << endl;
    cout << "edge2.get_weight(): " << edge2.get_weight() << endl;

    cout << "vertex1.get_name(): " << vertex1.get_name() << endl;
    cout << "vertex1.get_neighbors(): " << vertex1.get_neighbors() << endl;
    cout << "vertex1.num_edges_attached(): " << vertex1.num_edges_attached() << endl;

    cout << "vertex2.num_edges_attached(): " << vertex2.num_edges_attached() << endl;
    // cout << "add neighbor: " << vertex2.add_neighbor(15, &vertex4) << endl;
    cout << "vertex2.get_neighbors(): " << vertex2.get_neighbors() << endl;
    cout << "vertex2 add neighbor(vertex4, weght=15): " << endl;
    vertex2.add_neighbor(15, &vertex4);
    cout << "vertex2 add neighbor (vertex5, weight=7): " << endl;
    vertex2.add_neighbor(7, &vertex5);    


    cout << "vertex2.num_edges_attached(): " << vertex2.num_edges_attached() << endl;
    cout << "vertex2.get_neighbors(): " << vertex2.get_neighbors() << endl;
    // hook up the edges to the nodes


    cout << endl;
    system("pause");
    
    return 0;
}
