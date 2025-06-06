#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to add edge to an undirected graph
void add_edge(vector<vector<int>>& adj_list, int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u); // undirected graph
}


// BFS using queue
void bfs(int start, const vector<vector<int>>& adj_list) {
    int n = adj_list.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from node " << start << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : adj_list[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 6; // Number of nodes
    vector<vector<int>> adj_list(n);

    // Add edges
    add_edge(adj_list, 0, 1);
    add_edge(adj_list, 0, 2);
    add_edge(adj_list, 1, 3);
    add_edge(adj_list, 2, 4);
    add_edge(adj_list, 3, 5);
    add_edge(adj_list, 4, 5);

    bfs(0, adj_list);

    return 0;
}
