#include <iostream>
using namespace std;

const int V = 5;           // Number of vertices
const int INF = 1e9;       // Representing infinity

// Adjacency matrix representation of the graph
int graph[V][V] = {
    {0, 10, 0, 5, 0},   // Edges from node 0
    {0, 0, 1, 2, 0},    // Edges from node 1
    {0, 0, 0, 0, 4},    // Edges from node 2
    {0, 3, 9, 0, 2},    // Edges from node 3
    {7, 0, 6, 0, 0}     // Edges from node 4
};

void dijkstra(int start) {
    int dist[V];        // dist[i] will hold the shortest distance from start to i
    bool visited[V];    // visited[i] is true if node i is already visited

    // Step 1: Initialize all distances as INF and visited as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[start] = 0;  // Distance to source is 0

    // Step 2: Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = -1;

        // Find the unvisited node with the smallest distance
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true; // Mark this node as visited

        // Step 3: Update distances of neighbors
        for (int v = 0; v < V; v++) {
            // If there's an edge from u to v and v is unvisited
            if (graph[u][v] && !visited[v]) {
                // If the path through u is shorter than current path to v
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Step 4: Print the shortest distances
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << " = " << dist[i] << " mins" << endl;
    }
}

int main() {
    dijkstra(0); // Starting from node 0 (Home)
    return 0;
}
