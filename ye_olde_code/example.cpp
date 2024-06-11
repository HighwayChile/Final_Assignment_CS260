// THIS ONE WORKS

void Graph::min_span_tree_02() {
    std::cout << "min_span_tree (Kruskal's) has been reached. Congrats. Now make it work." << std::endl;

    // Sort all edges in non-decreasing order of their weight
    std::sort(edges.begin(), edges.end(), [](Edge *a, Edge *b) {
        return a->get_weight() < b->get_weight();
    });

    // Create a union-find data structure to manage the sets of vertices
    DisjointUnion uf(num_vertex);

    std::vector<Edge*> mst;  // This will store the edges of the MST

    for (Edge *edge : edges) {
        int u = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), edge->get_origin()));
        int v = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), edge->get_destination()));

        if (uf.find(u) != uf.find(v)) {
            uf.union_sets(u, v);
            mst.push_back(edge);
        }

        if (mst.size() == num_vertex - 1) {
            break;
        }
    }

    // Print the MST
    std::cout << "Minimum Spanning Tree:" << std::endl;
    for (Edge *edge : mst) {
        std::cout << edge->get_origin()->get_name() << " - " << edge->get_destination()->get_name()
                  << " with weight " << edge->get_weight() << std::endl;
    }
}