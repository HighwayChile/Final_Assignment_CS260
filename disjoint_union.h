#include <vector>

using namespace std;

class DisjointUnion {
    private:
        vector<int> parent;
        vector<int> rank;

    public:
        DisjointUnion(int size) {
            parent.resize(size);
            rank.resize(size, 0);
            for(int i = 0; i < size; ++i) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if(u != parent[u]) {
                parent[u] = find(parent[u]); // Chat GPT tells me this is path compression
            }
            return parent[u];
        }

        void union_sets(int u, int v) {
            int root_u = find(u);
            int root_v = find(v);

            if(root_u != root_v) {
                // Unite by rank
                if(rank[root_u] > rank[root_v]) {
                    parent[root_v] = root_u;
                } 
                else if(rank[root_u] < rank[root_v]) {
                    parent[root_u] = root_v;
                } else {
                    parent[root_v] = root_u;
                    rank[root_u]++;
                }

            }
            
        }
};
