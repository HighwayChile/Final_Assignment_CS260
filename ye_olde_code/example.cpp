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













int Graph::min_distance(vector<int> &dist, vector<bool> &spt_set) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < num_vertex; v++) {
        if (!spt_set[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void Graph::print_solution(vector<int> &dist) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < num_vertex; i++)
        cout << vertices[i]->get_name() << " \t " << dist[i] << endl;
}

void Graph::shortest_path(string src_name) {
    int src = -1;
    for (int i = 0; i < num_vertex; i++) {
        if (vertices[i]->get_name() == src_name) {
            src = i;
            break;
        }
    }
    if (src == -1) {
        cout << "Source vertex not found" << endl;
        return;
    }

    vector<int> dist(num_vertex, INT_MAX);
    vector<bool> spt_set(num_vertex, false);
    dist[src] = 0;

    for (int count = 0; count < num_vertex - 1; count++) {
        int u = min_distance(dist, spt_set);
        spt_set[u] = true;

        for (int v = 0; v < num_vertex; v++) {
            Edge *edge = find_edge(vertices[u], vertices[v]);
            if (!spt_set[v] && edge && dist[u] != INT_MAX && dist[u] + edge->get_weight() < dist[v]) {
                dist[v] = dist[u] + edge->get_weight();
            }
        }
    }
    print_solution(dist);
}