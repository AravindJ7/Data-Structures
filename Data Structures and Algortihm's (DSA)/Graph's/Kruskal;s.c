#include <iostream>
#include <algorithm>
using namespace std;

const int V = 5;  // Number of vertices
const int E = 7;  // Number of edges

// Each edge: {u, v, weight}
int edges[E][3] = {
    {0, 1, 2},
    {0, 3, 6},
    {1, 2, 3},
    {1, 3, 8},
    {1, 4, 5},
    {2, 4, 7},
    {3, 4, 9}
};

// Union-Find parent array
int parent[V];

// FIND: get the root of the node
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // Path compression
}

// UNION: connect two components
void unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

void kruskal() {
    // Step 1: Sort all edges by weight
    sort(edges, edges + E, [](int a[], int b[]) {
        return a[2] < b[2]; // Sort by weight
    });

    // Step 2: Make each node its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int mst_weight = 0;
    cout << "Edges in MST:\n";

    // Step 3: Pick edges one by one
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        // If including this edge doesn't cause a cycle
        if (find(u) != find(v)) {
            cout << u << " - " << v << " (weight = " << w << ")\n";
            mst_weight += w;
            unionSets(u, v); // Join the components
        }
    }

    cout << "Total weight of MST = " << mst_weight << endl;
}

int main() {
    kruskal();
    return 0;
}
