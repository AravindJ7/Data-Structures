#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Add edge to undirected graph
void add_edge(vector<vector<int>>& adj_list, int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

// DFS using stack and for-each loop
void dfs(int start, vector<vector<int>>& adj_list, vector<bool>& visited) {
    stack<int> s;
    s.push(start);

    cout << "DFS Traversal: ";

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            // Traverse neighbors using for-each loop
            for (int neighbor : adj_list[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }

    cout << endl;
}

int main() {
    int n = 5;
    vector<vector<int>> adj_list(n);
    vector<bool> visited(n, false);

    // Add edges
    add_edge(adj_list, 0, 1);
    add_edge(adj_list, 0, 2);
    add_edge(adj_list, 1, 3);
    add_edge(adj_list, 2, 4);

    dfs(0, adj_list, visited);

    return 0;
}
