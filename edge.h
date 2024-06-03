#pragma once

#include "vertex.h"

// had to declare Vertex type
struct Vertex;

struct Edge {
    int weight;
    int id;
    // int num_vertex;
    Vertex *origin;
    Vertex *destination;
};