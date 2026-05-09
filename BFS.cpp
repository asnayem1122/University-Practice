#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>& adj, int src, int n){

    // Step 1: Track visited nodes
    vector<bool> visited(n + 1, false);
    vector<int> order;

    // Step 2: Start from source
    queue<int> q;
    visited[src] = true;
    q.push(src);

    // Step 3: Process until queue empty
    while(!q.empty()){
        int node = q.front(); q.pop();
        order.push_back(node);

        // Step 4: Visit all unvisited neighbours
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    return order;
}

int main(){
    int n, e;
    cout << "Enter nodes and edges: ";
    cin >> n >> e;

    // Build adjacency list (1-indexed)
    vector<vector<int>> adj(n + 1);

    int u, v;
    for(int i = 0; i < e; i++){
        cout << "Enter edge " << i+1 << " (u v): ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Enter source node: ";
    int src; cin >> src;

    // Run BFS
    auto order = bfs(adj, src, n);

    // Print result
    cout << "\nBFS traversal from node " << src << ":" << endl;
    for(int node : order)
        cout << "  Node " << node << endl;

    return 0;
}