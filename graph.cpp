#include <iostream>
#include <vector>
#include <algorithm> // allows use of "sort"

#include "disjoint_union.h"
#include "graph.h"
#include "vertex.h"
#include "edge.h"

using namespace std;

Graph::Graph(){
    num_vertex = 0;
    num_edge = 0;
}

// deconstructor must iterate through array - VERIFY!! - I don't think it works :(
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
    // I was missing the push_back function to push new vector - fixed
    vertices.push_back(new_vertex);
    num_vertex++;
}

void Graph::add_edge(int weight, Vertex *origin, Vertex *destination) {
    Edge *new_edge = new Edge(weight, origin, destination);
    // missed this line here, too. Was reminded by ChatGPT, but remember Joseph Jess' comments during class.
    edges.push_back(new_edge);
    num_edge++;
}


// this is used to get neighbors and to name the edges
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
        // "OR" here should allow for dangling edges. Not sure how it helps/harms
        if(edge->get_origin() == origin || edge->get_destination() == destination) {
            return edge;
        }
    }
    return nullptr;
}

// get private attributes
int Graph::get_num_edge() {
    return num_edge;
}

int Graph::get_num_vertex() {
    return num_vertex;
}

// this iterates a couple times and prints vertices and edges to screen
void Graph::print_graph() {
    cout << "NODES: ";
    for(Vertex *vertex : vertices) {
        cout << vertex->name << ", ";
    }
    cout << endl;
    cout << "EDGES: ";
    for(Edge *edge : edges) {
        cout << edge->edge_name << ", ";
    }
    cout << endl;
    cout << "Edge weights: " << endl;
    for(Edge *edge : edges) {
        cout << edge->edge_name << " weight: " << edge->get_weight() << endl;
    }
    cout << endl;    
}

// Kruskal's Algorithm
// from geeksforgeeks
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/ 
void Graph::min_span_tree() {

    int span_tree_weight = 0;

    //  Step 1... sort
    sort(edges.begin(), edges.end(), [](Edge *a, Edge *b) {return a->get_weight() < b->get_weight();});

    // make disjoint union
    DisjointUnion union_find(num_vertex);

    // vector to store edges of new tree that is the min spanning tree
    vector <Edge *> mst;

    for(Edge *edge : edges) {
        int u = distance(vertices.begin(), find(vertices.begin(), vertices.end(), edge->get_origin()));
        int v = distance(vertices.begin(), find(vertices.begin(), vertices.end(), edge->get_destination()));

        if(union_find.find(u) != union_find.find(v)) {
            union_find.union_sets(u, v);
            mst.push_back(edge);
        }

        // this determines the end of the edge list - disallows dangling edges
        if(mst.size() == num_vertex - 1) {
            break;
        }
    }

    cout << "Minimum Spanning Tree:" << endl;

    for(Edge *edge : mst) {
        cout << edge->get_origin()->get_name() << " - " << edge->get_destination()->get_name() 
        << " with weight " << edge->get_weight() << endl;
        // print the total weight of tree
        span_tree_weight += edge->get_weight();  
    }

    cout << "Total Weight: " << span_tree_weight << endl;
    cout << endl;
}


// This is my attempt at appying Djikstra's Algorithm.
// this is almost directly copied from Geeksforgeeks. I did copy the code, then I modified it.
// It searches for neighboring vertices to find the shortest path(in number of vertices)
// It prints out every single vertex in the graph, then shows how far that vertex is from the 
// source, which is fed into the shortest_path() function as a string.

int Graph::min_distance(vector<int> &dist, vector<bool> &spt_set) {
    int min = INT_MAX, min_index;

    for(int v = 0; v < num_vertex; v++){
        if(!spt_set[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;

        }
    }
    return min_index;
}

void Graph::print_solution(vector<int> &dist) {
    cout << "Vertex \t Distance from source" << endl;
    for(int i = 0; i < num_vertex; i++)
        cout << vertices[i]->get_name() << " \t " << dist[i] << endl;
}

void Graph::shortest_path(string src_name) {
    int src = - 1;

    for(int i = 0; i < num_vertex; i++) {
        if(vertices[i]->get_name() == src_name) {
            src = i;
            break;
        }
    }
    if(src == -1) {
        cout << "Source not found" << endl;
        return;
    }

    vector<int> dist(num_vertex, INT_MAX);
    vector<bool> spt_set(num_vertex, false);
    dist[src] = 0;

    for(int count = 0; count < num_vertex - 1; count++) {
        int u = min_distance(dist, spt_set);
        spt_set[u] = true;

        for(int v = 0; v < num_vertex; v++) {;
            Edge *edge = find_edge(vertices[u], vertices[v]);
            if(!spt_set[v] && edge && dist[u] != INT_MAX && dist[u] + edge->get_weight() < dist[v]) {
                dist[v] = dist[u] + edge->get_weight();
            }
        }
    }
    print_solution(dist);
}





