
#include <iostream>
#include <vector>
#include <limits>

#include "vertex.cpp"
#include "edge.cpp"
#include "graph.cpp"
#include "vertex.h"
#include "edge.h"
#include "graph.h"

using namespace std;


void simple_graph_test() {
    cout << "Create Simple Graph" << endl;
    cout << "Creating Graph... " << endl;
    Graph simple_graph;

    cout << "Adding nodes A, B, and C... " << endl;
    simple_graph.add_vertex("A");
    simple_graph.add_vertex("B");
    simple_graph.add_vertex("C");

    simple_graph.print_graph();


    cout << "Adding unnamed edges... " << endl;
    simple_graph.add_edge(3, simple_graph.find_vertex("A"), simple_graph.find_vertex("B"));
    simple_graph.add_edge(6, simple_graph.find_vertex("B"), simple_graph.find_vertex("C"));
    simple_graph.add_edge(1, simple_graph.find_vertex("C"), simple_graph.find_vertex("A"));
    simple_graph.find_edge(simple_graph.find_vertex("A"), simple_graph.find_vertex("B"));

    simple_graph.print_graph();

    simple_graph.~Graph();

}


void bin_tree_test() {
    cout << "Create Binary Tree" << endl;
    cout << "Creating tree... " << endl;
    Graph simple_tree;

    cout << "Adding nodes A, B, C, D, E, F, G, H and I... " << endl;
    simple_tree.add_vertex("A");
    simple_tree.add_vertex("B");
    simple_tree.add_vertex("C");
    simple_tree.add_vertex("D");
    simple_tree.add_vertex("E");
    simple_tree.add_vertex("F");
    simple_tree.add_vertex("G");
    simple_tree.add_vertex("H");
    simple_tree.add_vertex("I");    

    simple_tree.print_graph();


    cout << "Adding unnamed edges... " << endl;
    simple_tree.add_edge(5, simple_tree.find_vertex("A"), simple_tree.find_vertex("B"));
    simple_tree.add_edge(4, simple_tree.find_vertex("A"), simple_tree.find_vertex("C"));
    simple_tree.add_edge(2, simple_tree.find_vertex("B"), simple_tree.find_vertex("D"));
    simple_tree.add_edge(2, simple_tree.find_vertex("B"), simple_tree.find_vertex("E"));
    simple_tree.add_edge(2, simple_tree.find_vertex("C"), simple_tree.find_vertex("F"));
    simple_tree.add_edge(2, simple_tree.find_vertex("C"), simple_tree.find_vertex("G"));
    simple_tree.add_edge(2, simple_tree.find_vertex("G"), simple_tree.find_vertex("H"));
    simple_tree.find_edge(simple_tree.find_vertex("G"), simple_tree.find_vertex("I"));

    simple_tree.print_graph();

    simple_tree.~Graph();
}






int main() {
    // test_function();
    simple_graph_test();
    bin_tree_test();
    // return 0;
    cout << endl;
    cout << "Quitting Program..." << endl;
    system("pause");
}