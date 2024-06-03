#pragma once

#include "vertex.h"

// had to declare Vertex type
struct Vertex;

struct Edge {
    private:
        int weight;
        Vertex *origin;
        Vertex *destination;

    public:
        Edge(int new_weight, Vertex *new_origin, Vertex *new_destination);
        // DON'T FORGET DECONSTRUCTORS!
        int get_weight();
        Vertex *get_origin();
        Vertex *get_destination();

        // likewise copy/pasta'd
        // std::string to_string();

};


