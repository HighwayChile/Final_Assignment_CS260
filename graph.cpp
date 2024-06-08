#include <iostream>


#include "graph.h"
#include "vertex.h"
#include "edge.h"




    
    // Pseudo
    /*
    
    for every new vertex
        Vertex::Vertex(name)
        num_vertex++

    for every new edge
        Edge::edge(weight, origin, destination)
        num_edge++

    */



// Graph(); //constructor
// consider using list initializer: "Graph::Graph() : num_vertex(0), num_edge(0) {}"
// argued with chatGPT about it, that is apparently a more efficient way of initialization.
Graph::Graph(){
    num_vertex = 0;
    num_edge = 0;
}



// ~Graph(); // deconstructor must iterate through array
Graph::~Graph() {
    for(Vertex *vertex : vertices) {
        delete vertex;
    }
    for(Edge *edge : edges) {
        delete edge;
    }
}


void add_vertex(string name);
void add_edge(int weight, Vertex *origin, Vertex *destination);
Vertex find_vertex(string name);
// Edge find_edge(name) // idk how to search for an edge without a name. 
// edges could inherit name from origin and destination names.
// i.e. - Alpha/Bravo could be one edge that goes between nodes 1 and 2.
bool is_path_extant();
void shortest_path();     // void shortest_path(Djikstra's Algo)  
void min_span_tree();     // void min_span_tree(Kruskal's Algo) 