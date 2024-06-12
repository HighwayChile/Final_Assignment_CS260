#pragma once

#include "vertex.h"

using namespace std;

struct Vertex;

struct Edge {
    private:
    // private attributes
        int weight;
        Vertex *origin;
        Vertex *destination;

    public:
    // function defclarations
        string edge_name;
        Edge(int new_weight, Vertex *new_origin, Vertex *new_destination);

        int get_weight();
        Vertex *get_origin();
        Vertex *get_destination();
};

