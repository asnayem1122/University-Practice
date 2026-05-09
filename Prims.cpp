#include <bits/stdc++.h>
using namespace std;

int prims(vector<vector<pair<int,int>>>& adj, int n){

    // Step 1: Track visited and minimum edge weight to reach each node
    vector<bool> inMST(n + 1, false);
    vector<int> key(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);

    // Min-heap {weight, node}
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    // Step 2: Start from node 1
    key[1] = 0;
    pq.push({0, 1});

    int totalWeight = 0;
    vector<pair<int,int>> mstEdges;

    // Step 3: Process until heap empty
    while(!pq.empty()){
        auto [w, node] = pq.top(); pq.pop();

        // Skip if already in MST
        if(inMST[node]) continue;
        inMST[node] = true;
        totalWeight += w;

        if(parent[node] != -1)
            mstEdges.push_back({parent[node], node});

        // Step 4: Update neighbours
        for(auto& [neighbour, weight] : adj[node]){
            if(!inMST[neighbour] && weight < key[neighbour]){
                key[neighbour] = weight;
                parent[neighbour] = node;
                pq.push({weight, neighbour});
            }
        }
    }

    // Print MST edges
    cout << "\nMST Edges:" << endl;
    for(auto& [u, v] : mstEdges)
        cout << "  " << u << " -- " << v << "  (wt: " << key[v] << ")" << endl;

    return totalWeight;
}

int main(){
    int n, e;
    cout << "Enter nodes and edges: " << endl;
    cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n + 1);

    int u, v, w;
    for(int i = 0; i < e; i++){
        cout << "Enter edge " << i+1 << " (u v w): " << endl;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int total = prims(adj, n);
    cout << "\nTotal MST weight: " << total << endl;

    return 0;
}