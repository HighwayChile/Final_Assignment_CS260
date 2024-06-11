// #include <iostream>


// #include "graph.h"
// #include "vertex.h"
// #include "edge.h"

// using namespace std;


#include <iostream>
#include <vector>
#include <limits>

// #include "testor.cpp"
// #include "test_function.cpp"
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

}




int main() {
    // test_function();
    simple_graph_test();
    // return 0;
    cout << endl;
    cout << "Quitting Program..." << endl;
    system("pause");
}