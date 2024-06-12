#include <vector>

using namespace std;

class DisjointUnion {
    private:
        // vectors to store the parent node and the placement in the new array
        vector<int> parent;
        vector<int> place;

    public:
        // constructor initializes the parents and the placement
        DisjointUnion(int size) {
            // resize parent and placement vectors
            parent.resize(size);
            place.resize(size, 0);
            // each node starts as its own parent
            for(int i = 0; i < size; ++i) {
                parent[i] = i;
            }
        }


        // finds the root of the set that is parent to u
        int find(int u) {
            if(u != parent[u]) {

                // Path compression: Set the parent of 'u' to its root (recursive call)
                parent[u] = find(parent[u]);
            }
            // return the root of the newly created set
            return parent[u];
        }

        // unites the sets u and v after testing for cycles
        void union_sets(int u, int v) {
            // find roots of u and v and assign vars
            int root_u = find(u);
            int root_v = find(v);

            if(root_u != root_v) {
                // Unite by place if the root is within the limit
                if(place[root_u] > place[root_v]) {
                    // Attach set with lesser rank to set with greater rank
                    parent[root_v] = root_u;
                } 
                else if(place[root_u] < place[root_v]) {
                    // Attach set with lesser placement to set with greater placement
                    parent[root_u] = root_v;
                } else {
                    // Arbitrarily choose one set as the parent
                    parent[root_v] = root_u;
                    // Increment the placement of the chosen set
                    place[root_u]++;
                }

            }
            
        }
};
