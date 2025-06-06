#include <iostream>
using namespace std;

const int V = 5;  // Number of vertices
const int E = 7;  // Number of edges

// List of all edges: (u, v, weight)
int edges[E][3] = {
    {0, 1, 2},
    {0, 3, 6},
    {1, 2, 3},
    {1, 3, 8},
    {1, 4, 5},
    {2, 4, 7},
    {3, 4, 9}
};

// For keeping track of which vertices are in MST
bool visited[V] = {false};

void prim() {
    int mst_weight = 0;

    visited[0] = true; // Start from vertex 0

    cout << "Edges in MST:\n";

    // We need V - 1 edges in MST
    for (int count = 0; count < V - 1; count++) {
        int minEdgeWeight = 1e9;
        int u = -1, v = -1;

        // Loop through all edges
        for (int i = 0; i < E; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];

            // Check if one vertex is visited and the other is not
            if ((visited[a] && !visited[b]) || (!visited[a] && visited[b])) {
                if (w < minEdgeWeight) {
                    minEdgeWeight = w;
                    u = a;
                    v = b;
                }
            }
        }

        // Add the selected edge to MST
        visited[u] = visited[v] = true;
        cout << u << " - " << v << " (weight = " << minEdgeWeight << ")\n";
        mst_weight += minEdgeWeight;
    }

    cout << "Total weight of MST = " << mst_weight << endl;
}

int main() {
    prim();
    return 0;
}
