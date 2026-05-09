#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist, int n){

    // Try every node k as intermediate between i and j
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    int n, e;
    cout << "Enter nodes and edges: " << endl;
    cin >> n >> e;

    // Initialize dist matrix with INF
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // Distance to self = 0
    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;

    int u, v, w;
    for(int i = 0; i < e; i++){
        cout << "Enter edge " << i+1 << " (u v w): " << endl;
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w; // remove for directed graph
    }

    floydWarshall(dist, n);

    // Check negative cycle
    for(int i = 1; i <= n; i++){
        if(dist[i][i] < 0){
            cout << "Negative cycle detected!" << endl;
            return 0;
        }
    }

    // Print result matrix
    cout << "\nAll pairs shortest distances:" << endl;
    cout << "     ";
    for(int i = 1; i <= n; i++)
        cout << "  " << i << "  ";
    cout << endl;

    for(int i = 1; i <= n; i++){
        cout << "  " << i << "  ";
        for(int j = 1; j <= n; j++){
            if(dist[i][j] == INF) cout << " INF ";
            else                  cout << "  " << dist[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}