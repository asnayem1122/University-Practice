#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order, int node){

    // Step 1: Mark current node visited
    visited[node] = true;
    order.push_back(node);

    // Step 2: Recurse on unvisited neighbours
    for(int neighbour : adj[node]){
        if(!visited[neighbour]){
            dfs(adj, visited, order, neighbour);
        }
    }
}

int main(){
    int n, e;
    cout << "Enter nodes and edges: " << endl;
    cin >> n >> e;

    vector<vector<int>> adj(n + 1);

    int u, v;
    for(int i = 0; i < e; i++){
        cout << "Enter edge " << i+1 << " (u v): " << endl;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Enter source node: " << endl;
    int src; cin >> src;

    vector<bool> visited(n + 1, false);
    vector<int> order;

    dfs(adj, visited, order, src);

    cout << "\nDFS traversal from node " << src << ":" << endl;
    for(int node : order)
        cout << "  Node " << node << endl;

    return 0;
}