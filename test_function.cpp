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

void test_function() {
    // create nodes
    // Totally random graph
    Vertex vertex1("vertex1");
    Vertex vertex2("vertex2");
    Vertex vertex3("vertex3");
    Vertex vertex4("vertex4");
    Vertex vertex5("vertex5");
    Vertex vertex6("vertex6");
    Vertex vertex7("vertex7");
    Vertex vertex8("vertex8");


    // create edges
    Edge edge1(1, &vertex1, &vertex2);
    Edge edge2(4, &vertex2, &vertex3);
    Edge edge3(5, &vertex3, &vertex1);
    Edge edge4(5, &vertex3, nullptr);

    // create vertices
    vertex1.add_neighbor(3, &vertex2);
    vertex1.add_neighbor(3, &vertex3);

    cout << "NEW edge1.create_name: " << edge1.create_name(&vertex1, &vertex2) << endl;;

    cout << "edge1 get_origin:  ----- " << edge1.get_origin()->name << endl;
    cout << "edge1 get_destination: - " << edge1.get_destination()->name << endl;
    cout << "edge1 get_weight: ------ " << edge1.get_weight() << endl;
    cout << endl;

    cout << "NEW edge2.create_name: " << edge2.create_name(&vertex2, &vertex3) << endl;;
    cout << "edge2 get_origin: ------ " << edge2.get_origin()->name << endl;
    cout << "edge2 get_destination: - " << edge2.get_destination()->name << endl;
    cout << "edge2 get_weight: ------ " << edge2.get_weight() << endl;
    cout << endl;

    cout << "vertex1.get_name(): ----------- " << vertex1.get_name() << endl;
    cout << "vertex1.get_neighbors(): ------ " << vertex1.get_neighbors() << endl;
    cout << "vertex1 print_neighbors: ------ ";
    vertex1.print_neighbors();
    cout << "\nvertex1.num_edges_attached(): - " << vertex1.num_edges_attached() << endl;
    cout << endl;

    cout << "vertex2.num_edges_attached(): - " << vertex2.num_edges_attached() << endl;
    // cout << "add neighbor: " << vertex2.add_neighbor(15, &vertex4) << endl;
    cout << "vertex2.get_neighbors(): ------ " << vertex2.get_neighbors() << endl;
    cout << endl;

    cout << "vertex2 add neighbor(vertex4, weght=15): --- " << endl;
    vertex2.add_neighbor(15, &vertex4);
    cout << "vertex2 add neighbor (vertex5, weight=7): -- " << endl;
    vertex2.add_neighbor(7, &vertex5);    


    cout << "vertex2.num_edges_attached(): --- " << vertex2.num_edges_attached() << endl;
    cout << "vertex2.get_neighbors(): -------- " << vertex2.get_neighbors() << endl;
    cout << "vertex2.print_neighbors(): ------ ";
    vertex2.print_neighbors();
    cout << endl;
    
    // vertex1.~Vertex();
    // vertex2.~Vertex();
    // vertex3.~Vertex();
    // vertex4.~Vertex();
    // vertex5.~Vertex();
    // vertex6.~Vertex();
    // vertex7.~Vertex();
    // vertex8.~Vertex();

    // edge1.~Edge();
    // edge2.~Edge();
    // edge3.~Edge();
    // edge4.~Edge();


    cout << "\n" << endl;
    cout << "MAKING GRAPH - 3 VERTICES" << endl;


    Graph graph;

    graph.add_vertex("A");
    graph.add_vertex("B");
    graph.add_vertex("C");

    Vertex *vertexA = graph.find_vertex("A");
    Vertex *vertexB = graph.find_vertex("B");
    Vertex *vertexC = graph.find_vertex("C");

    if (vertexA && vertexB && vertexC) {
        graph.add_edge("A/B", 10, vertexA, vertexB);
        graph.add_edge("B/C", 20, vertexB, vertexC);
        graph.add_edge("C/A" , 30, vertexC, vertexA);
    }

    cout << "Number of vertices: " << graph.get_num_vertex() << endl;
    cout << "Number of edges: " << graph.get_num_edge() << endl;
    // cout << "A's neighbors: " << vertexA.get_neighbors()->name << endl;
    cout << "A's neighbors: ";
    cout << "Name edge twixt A and B (expect A/B): " << endl;
    // print neighbors working
    cout << "print vertexA->name: " << vertexA->name << endl;
    cout << "edge_name: -blank-" << endl;
    // graph.print_neighbors(vertexA);
    cout << "vertexA print_neighbors" ; 
    vertexA->print_neighbors();



    cout << endl;
    cout << "Quitting Program..." << endl;
    system("pause");
}


int main() {
    test_function();

    return 0;
}