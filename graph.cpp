#include <iostream>
#include <vector>


#include "graph.h"
#include "vertex.h"
#include "edge.h"


#include <unordered_map> // for unordered_map
#include <queue> // for priority_queue
#include <functional> // for greater
#include <limits> // for INT_MAX

using namespace std;


    // Pseudo
    /*
    
    new vertex
        Vertex::Vertex(name) - incorrect, should be: Vertex *new_vertex = new Vertex
        num_vertex++

    new edge
        Edge::edge(weight, origin, destination)
        num_edge++

    */


// consider using list initializer: "Graph::Graph() : num_vertex(0), num_edge(0) {}"
// argued with chatGPT about it, that is apparently a more efficient way of initialization.
Graph::Graph(){
    num_vertex = 0;
    num_edge = 0;
}


// deconstructor must iterate through array
Graph::~Graph() {
    for(Vertex *vertex : vertices) {
        delete vertex;
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
    // missed this line here, too. Was reminded by ChatGPT, but remember Joseph Jess' comments.
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


// Edge find_edge(name) // idk how to search for an edge without a name. 
// edges could inherit name from origin and destination names.
// i.e. - Alpha/Bravo could be one edge that goes between nodes 1 and 2.
Edge *Graph::find_edge(Vertex *origin, Vertex *destination) {
    for(Edge *edge : edges) {
        if(edge->get_origin() == origin || edge->get_destination() == destination) {
            return edge;
        }
    }
    return nullptr;
}












// void shortest_path();     // void shortest_path(Djikstra's Algo) 
void Graph::shortest_path() {

}


// void min_span_tree();     // void min_span_tree(Kruskal's Algo) 
void Graph::min_span_tree() {
    // soon...

}
























int Graph::get_num_edge() {
    return num_edge;
}


int Graph::get_num_vertex() {
    return num_vertex;
}

