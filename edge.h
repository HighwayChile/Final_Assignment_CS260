#pragma once

// #include <iostream>
// #include <string>
#include "vertex.h"

using namespace std;
// had to declare Vertex type
struct Vertex;

struct Edge {
    private:
        int weight;
        Vertex *origin;
        Vertex *destination;

    public:
        string edge_name;
        Edge(int new_weight, Vertex *new_origin, Vertex *new_destination);
        ~Edge();

        int get_weight();
        Vertex *get_origin();
        Vertex *get_destination();
};

