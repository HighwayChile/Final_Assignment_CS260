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
        // "OR" here should allow for dangling edges. Not sure how it helps/harms
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
    cout << "Edge weights: " << endl;
    for(Edge *edge : edges) {
        // cout << edge->edge_name << " weight: " << edge->get_weight() << ", ";
        cout << edge->edge_name << " weight: " << edge->get_weight() << endl;

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

   /*
   KRUSKAL'S EXAMPLE GEEKS4GEEKS

    void kruskals_mst() 
    { 
        // Sort all edges 
        sort(edgelist.begin(), edgelist.end()); 
  
        // Initialize the DSU 
        DSU s(V); 
        int ans = 0; 
        cout << "Following are the edges in the "
                "constructed MST"
             << endl; 
        for (auto edge : edgelist) { 
            int w = edge[0]; 
            int x = edge[1]; 
            int y = edge[2]; 
  
            // Take this edge in MST if it does 
            // not forms a cycle 
            if (s.find(x) != s.find(y)) { 
                s.unite(x, y); 
                ans += w; 
                cout << x << " -- " << y << " == " << w 
                     << endl; 
            } 
        } 
        cout << "Minimum Cost Spanning Tree: " << ans; 
    } 
   
   */

    int span_tree_weight = 0;



    std::cout << "min_span_tree (Kruskal's) has been reached. Congrats. Now make it work." << std::endl;
    //  Step 1... sort
    sort(edges.begin(), edges.end(), [](Edge *a, Edge *b) {return a->get_weight() < b->get_weight();});
    // sort(edges.begin(), edges.end());

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


    // Now print it
    cout << "Minimum Spanning Tree:" << endl;

    for(Edge *edge : mst) {
        cout << edge->get_origin()->get_name() << " - " << edge->get_destination()->get_name() 
        << " with weight " << edge->get_weight() << endl;
    }



    // now print the total weight of tree
    for(Edge *edge : mst) {
        span_tree_weight += edge->get_weight();  
    }
    cout << "Total Weight: " << span_tree_weight << endl;
}
