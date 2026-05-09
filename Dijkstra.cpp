#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src, int n){
    
    // Step 1: Set all distances to infinity
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;

    // Step 2: Min-heap {distance, node}
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
    pq.push({0, src});

    // Step 3: Process until heap empty
    while(!pq.empty()){
        auto [d, node] = pq.top(); pq.pop();

        // Skip stale entries
        if(d > dist[node]) continue;

        // Step 4: Relax neighbours
        for(auto& [neighbour, wt] : adj[node]){
            if(d + wt < dist[neighbour]){
                dist[neighbour] = d + wt;
                pq.push({d + wt, neighbour});
            }
        }
    }

    return dist;
}

int main(){
    cout << "Enter number of nodes and edges: ";
    int n, e; cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n + 1);

    int u, v, w;
    for(int i = 0; i < e; i++){
        cout << "Enter edge " << i+1 << " (u v w): ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "Enter source node: ";
    int src; cin >> src;

    // Run Dijkstra
    auto dist = dijkstra(adj, src, n);

    // Print results
    cout << "\nShortest distances from node " << src << ":\n";
    for(int i = 1; i <= n; i++){
        if(dist[i] == INT_MAX) cout << "  Node " << i << " : unreachable\n";
        else                   cout << "  Node " << i << " : " << dist[i] << "\n";
    }

    return 0;
}