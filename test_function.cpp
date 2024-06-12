#include "vertex.cpp"
#include "edge.cpp"
#include "graph.cpp"

using namespace std;

// Test graphs are exactly the same as test_functions, but are called by driver.cpp

int simple_graph_test() {
    cout << "Create Simple Graph" << endl;
    cout << "-------------------------" << endl;
    cout << endl;

    cout << "Creating Graph... " << endl;
    Graph simple_graph;
    cout << endl;

    cout << "Adding nodes A, B, and C... " << endl;
    simple_graph.add_vertex("A");
    simple_graph.add_vertex("B");
    simple_graph.add_vertex("C");
    cout << endl;

    simple_graph.print_graph();
    cout << endl;   

    cout << "Adding unnamed edges... " << endl;
    simple_graph.add_edge(3, simple_graph.find_vertex("A"), simple_graph.find_vertex("B"));
    simple_graph.add_edge(6, simple_graph.find_vertex("B"), simple_graph.find_vertex("C"));
    simple_graph.add_edge(1, simple_graph.find_vertex("C"), simple_graph.find_vertex("A"));
    cout << endl;

    simple_graph.print_graph();
    cout << endl;
    cout << endl;
    cout << endl;
    simple_graph.~Graph();

    return 1;
}

int bin_tree_test() {
    cout << "Create Binary Tree" << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    cout << "Creating tree... " << endl;
    Graph simple_tree;
    cout << endl;

    cout << "Adding nodes A, B, C, D, E, F, G, H and I... " << endl;
    cout << endl;
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
    cout << endl;

    cout << "Adding unnamed edges... " << endl;
    simple_tree.add_edge(5, simple_tree.find_vertex("A"), simple_tree.find_vertex("B"));
    simple_tree.add_edge(4, simple_tree.find_vertex("A"), simple_tree.find_vertex("C"));
    simple_tree.add_edge(2, simple_tree.find_vertex("B"), simple_tree.find_vertex("D"));
    simple_tree.add_edge(2, simple_tree.find_vertex("B"), simple_tree.find_vertex("E"));
    simple_tree.add_edge(2, simple_tree.find_vertex("C"), simple_tree.find_vertex("F"));
    simple_tree.add_edge(2, simple_tree.find_vertex("C"), simple_tree.find_vertex("G"));
    simple_tree.add_edge(2, simple_tree.find_vertex("G"), simple_tree.find_vertex("H"));
    simple_tree.add_edge(2, simple_tree.find_vertex("G"), simple_tree.find_vertex("I"));
    cout << endl;

    simple_tree.print_graph();
    cout << endl;

    simple_tree.~Graph();

    return 1;
}

int simple_span_tree_test() {
    /* EXAMPLE
                4
         2  B ------ D  2
          / | '\  2  | \          
        A  2|   '\   |3  F
          \ |     '\ | /
         4  C------- E  2
                3
    */

    cout << "Create Simple Spanning Tree" << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    cout << "Creating spanning tree... " << endl;
    Graph simple_tree;
    cout << endl;

    cout << "Adding nodes A, B, C, D, E and F... " << endl;
    cout << endl;

    simple_tree.add_vertex("A");
    simple_tree.add_vertex("B");
    simple_tree.add_vertex("C");
    simple_tree.add_vertex("D");
    simple_tree.add_vertex("E");
    simple_tree.add_vertex("F"); 

    cout << "Printing Graph..." << endl;
    simple_tree.print_graph();
    cout << endl;

    cout << "Adding edges... " << endl;
    simple_tree.add_edge(2, simple_tree.find_vertex("A"), simple_tree.find_vertex("B"));
    simple_tree.add_edge(4, simple_tree.find_vertex("A"), simple_tree.find_vertex("C"));
    simple_tree.add_edge(2, simple_tree.find_vertex("B"), simple_tree.find_vertex("C"));
    simple_tree.add_edge(4, simple_tree.find_vertex("B"), simple_tree.find_vertex("D"));
    simple_tree.add_edge(2, simple_tree.find_vertex("B"), simple_tree.find_vertex("E"));
    simple_tree.add_edge(3, simple_tree.find_vertex("C"), simple_tree.find_vertex("E"));
    simple_tree.add_edge(3, simple_tree.find_vertex("D"), simple_tree.find_vertex("E"));
    simple_tree.add_edge(2, simple_tree.find_vertex("D"), simple_tree.find_vertex("F"));
    simple_tree.add_edge(2, simple_tree.find_vertex("E"), simple_tree.find_vertex("F"));
    cout << endl;

    simple_tree.print_graph();
    cout << endl;

    cout << "Number of vertices: " << simple_tree.get_num_vertex() << endl;
    cout << "Number of edges: " << simple_tree.get_num_edge() << endl;
    cout << endl;

    cout << "(simple tree)" << endl;
    simple_tree.min_span_tree();

    simple_tree.shortest_path("A");
    simple_tree.shortest_path("B");
    simple_tree.shortest_path("C");
    simple_tree.shortest_path("D");
    simple_tree.shortest_path("E");
    simple_tree.shortest_path("F");

    return 1;
}

int complex_span_tree_test() {

    cout << "Create Complex Spanning Tree" << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    cout << "Creating spanning tree... " << endl;
    Graph complex_tree;
    cout << endl;

    cout << "Adding nodes 1, 2, 3, 4, 5, 6, 7, 8 and 9... " << endl;
    cout << endl;
    
    complex_tree.add_vertex("1");
    complex_tree.add_vertex("2");
    complex_tree.add_vertex("3");
    complex_tree.add_vertex("4");
    complex_tree.add_vertex("5");
    complex_tree.add_vertex("6");
    complex_tree.add_vertex("7");
    complex_tree.add_vertex("8");
    complex_tree.add_vertex("9");    

    cout << "Printing Graph..." << endl;
    complex_tree.print_graph();
    cout << endl;

    cout << "Adding edges... " << endl;
    complex_tree.add_edge(10, complex_tree.find_vertex("1"), complex_tree.find_vertex("2"));
    complex_tree.add_edge(9, complex_tree.find_vertex("1"), complex_tree.find_vertex("3"));
    complex_tree.add_edge(6, complex_tree.find_vertex("1"), complex_tree.find_vertex("4"));
    complex_tree.add_edge(12, complex_tree.find_vertex("1"), complex_tree.find_vertex("5"));

    complex_tree.add_edge(8, complex_tree.find_vertex("2"), complex_tree.find_vertex("5"));

    complex_tree.add_edge(7, complex_tree.find_vertex("3"), complex_tree.find_vertex("4"));
    complex_tree.add_edge(5, complex_tree.find_vertex("3"), complex_tree.find_vertex("6"));

    complex_tree.add_edge(8, complex_tree.find_vertex("4"), complex_tree.find_vertex("5"));
    complex_tree.add_edge(8, complex_tree.find_vertex("4"), complex_tree.find_vertex("6"));
    complex_tree.add_edge(7, complex_tree.find_vertex("4"), complex_tree.find_vertex("7"));

    complex_tree.add_edge(4, complex_tree.find_vertex("5"), complex_tree.find_vertex("7"));
    complex_tree.add_edge(13, complex_tree.find_vertex("5"), complex_tree.find_vertex("9"));

    complex_tree.add_edge(14, complex_tree.find_vertex("6"), complex_tree.find_vertex("7"));
    complex_tree.add_edge(6, complex_tree.find_vertex("6"), complex_tree.find_vertex("8"));

    complex_tree.add_edge(8, complex_tree.find_vertex("7"), complex_tree.find_vertex("8"));
    complex_tree.add_edge(8, complex_tree.find_vertex("7"), complex_tree.find_vertex("9"));

    complex_tree.add_edge(10, complex_tree.find_vertex("8"), complex_tree.find_vertex("9"));
    cout << endl;

    complex_tree.print_graph();
    cout << endl;

    cout << "Number of vertices: " << complex_tree.get_num_vertex() << endl;
    cout << "Number of edges: " << complex_tree.get_num_edge() << endl;
    cout << endl;

    cout << "(complex tree)" << endl;
    complex_tree.min_span_tree();
    cout << endl;

    complex_tree.shortest_path("1");
    // complex_tree.shortest_path("2");
    // complex_tree.shortest_path("3");
    // complex_tree.shortest_path("4");
    // complex_tree.shortest_path("5");
    // complex_tree.shortest_path("6");
    // complex_tree.shortest_path("7");
    // complex_tree.shortest_path("8");

    return 1;
}




int main() {
    simple_graph_test();
    bin_tree_test();
    simple_span_tree_test();
    complex_span_tree_test();
    // return 0;
    cout << endl;
    cout << "Quitting Program..." << endl;
    system("pause");
}