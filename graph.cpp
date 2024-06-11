#include <iostream>
#include <vector>

#include "graph.h"
#include "vertex.h"
#include "edge.h"

using namespace std;

Graph::Graph(){
    num_vertex = 0;
    num_edge = 0;
}

// deconstructor must iterate through array
Graph::~Graph() {
    for(Vertex *vertex : vertices) {
        delete vertex;
        // Vertex::~Vertex();
    }
    for(Edge *edge : edges) {
        delete edge;
    }
}

void Graph::add_vertex(string name) {
    Vertex *new_vertex = new Vertex(name);
    // I was missing the push_back function to push new vector
    vertices.push_back(new_vertex);
    num_vertex++;
}

void Graph::add_edge(int weight, Vertex *origin, Vertex *destination) {
    Edge *new_edge = new Edge(weight, origin, destination);
    // missed this line here, too. Was reminded by ChatGPT, but remember Joseph Jess' comments during class.
    edges.push_back(new_edge);
    num_edge++;
}

Vertex *Graph::find_vertex(string name) {
    for(Vertex *vertex : vertices) {
        if(vertex->get_name() == name) {
            return vertex;
        }
    }
    return nullptr;
}


Edge *Graph::find_edge(Vertex *origin, Vertex *destination) {
    for(Edge *edge : edges) {
        if(edge->get_origin() == origin || edge->get_destination() == destination) {
            return edge;
        }
    }
    return nullptr;
}

int Graph::get_num_edge() {
    return num_edge;
}

int Graph::get_num_vertex() {
    return num_vertex;
}

void Graph::print_graph() {
    cout << "NODES: ";
    for(Vertex *vertex : vertices) {
        cout << vertex->name << ", ";
    }
    cout << endl;
    cout << "Edges: ";
    for(Edge *edge : edges) {
        cout << edge->edge_name << ", ";
    }
    cout << endl;
}

// void shortest_path();     // void shortest_path(Djikstra's Algo) 
void Graph::shortest_path() {
    // code goes here
}


// void min_span_tree();     // void min_span_tree(Kruskal's Algo)
// from geeksforgeeks
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/ 
void Graph::min_span_tree() {
    // soon...
    /* 
    1. Sort all EDGES in non-decreasing order of their weight... (increasing, then?)
    2. Pick the smallest edge. check if it forms a cycle with the spanning tree so far. if cycle, discard edge, if none, include 
    3. repeat step 2 until there are (num_vertex-1) edges in the spanning tree.

    */
//    for(Edge *edge : edges) {
//    }

}
