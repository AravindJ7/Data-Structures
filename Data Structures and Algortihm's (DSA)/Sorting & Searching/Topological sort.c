#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);

    // Calculate in-degree of each node
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    // Push nodes with in-degree 0 into the queue
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> topoOrder;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    if (topoOrder.size() != V) {
        cout << "Graph has a cycle. Topological sort not possible." << endl;
    } else {
        cout << "Topological Order: ";
        for (int node : topoOrder)
            cout << node << " ";
        cout << endl;
    }
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Example graph edges
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    topologicalSort(V, adj);

    return 0;
}
