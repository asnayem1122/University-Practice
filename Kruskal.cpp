#include <bits/stdc++.h>
using namespace std;

// DSU — Disjoint Set Union
vector<int> parent, rank_;

void init(int n){
    parent.resize(n + 1);
    rank_.resize(n + 1, 0);
    for(int i = 1; i <= n; i++)
        parent[i] = i;  // each node is its own parent
}

int find(int x){
    if(parent[x] != x)
        parent[x] = find(parent[x]);  // path compression
    return parent[x];
}

bool unite(int x, int y){
    int px = find(x), py = find(y);
    if(px == py) return false;  // same set = cycle, skip

    // union by rank
    if(rank_[px] < rank_[py]) swap(px, py);
    parent[py] = px;
    if(rank_[px] == rank_[py]) rank_[px]++;
    return true;
}

int kruskal(int n, vector<tuple<int,int,int>>& edges){

    // Step 1: Sort all edges by weight (ascending)
    sort(edges.begin(), edges.end());

    init(n);

    int totalWeight = 0;
    vector<tuple<int,int,int>> mstEdges;

    // Step 2: Pick smallest edge that doesn't form a cycle
    for(auto& [w, u, v] : edges){
        if(unite(u, v)){          // no cycle → add to MST
            totalWeight += w;
            mstEdges.push_back({w, u, v});
        }
        if((int)mstEdges.size() == n - 1) break;  // MST done
    }

    // Print MST edges
    cout << "\nMST Edges:" << endl;
    for(auto& [w, u, v] : mstEdges)
        cout << "  " << u << " -- " << v << "  (wt: " << w << ")" << endl;

    return totalWeight;
}

int main(){
    int n, e;
    cout << "Enter nodes and edges: " << endl;
    cin >> n >> e;

    vector<tuple<int,int,int>> edges;  // {weight, u, v}

    int u, v, w;
    for(int i = 0; i < e; i++){
        cout << "Enter edge " << i+1 << " (u v w): " << endl;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});  // weight first → sorts by weight
    }

    int total = kruskal(n, edges);
    cout << "\nTotal MST weight: " << total << endl;

    return 0;
}