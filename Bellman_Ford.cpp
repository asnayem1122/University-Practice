#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, int src, vector<tuple<int,int,int>>& edges){

    // Step 1: Set all distances to infinity
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;

    // Step 2: Relax all edges n-1 times
    for(int i = 0; i < n - 1; i++){
        for(auto& [u, v, w] : edges){
            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Step 3: Check for negative cycle
    for(auto& [u, v, w] : edges){
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            cout << "Negative cycle detected!" << endl;
            return {};
        }
    }

    return dist;
}

int main(){
    int n, e;
    cout << "Enter nodes and edges: " << endl;
    cin >> n >> e;

    vector<tuple<int,int,int>> edges;

    int u, v, w;
    for(int i = 0; i < e; i++){
        cout << "Enter edge " << i+1 << " (u v w): " << endl;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});  // directed — one way only
    }

    cout << "Enter source node: " << endl;
    int src; cin >> src;

    auto dist = bellmanFord(n, src, edges);

    if(!dist.empty()){
        cout << "\nShortest distances from node " << src << ":" << endl;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) cout << "  Node " << i << " : unreachable" << endl;
            else                   cout << "  Node " << i << " : " << dist[i] << endl;
        }
    }

    return 0;
}