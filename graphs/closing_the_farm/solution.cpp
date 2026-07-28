#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj, const vector<bool>& is_closed, vector<bool>& visited) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!is_closed[neighbor] && !visited[neighbor]) {
            dfs(neighbor, adj, is_closed, visited);
        }
    }
}

int main() {

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<int>> adj(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> closing_order(N);
    for(int i = 0; i < N; i++) {
        cin >> closing_order[i];
        closing_order[i]--; 
    }

    vector<bool> is_closed(N, false);
    int nodes_remaining = N;

    for(int i = 0; i < N; i++) {
        vector<bool> visited(N, false);
        
        int start_node = closing_order.back(); 

        dfs(start_node, adj, is_closed, visited);

        int visited_count = 0;
        for(int j = 0; j < N; j++) {
            if(!is_closed[j] && visited[j]) {
                visited_count++;
            }
        }

        if(visited_count == nodes_remaining) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        is_closed[closing_order[i]] = true;
        nodes_remaining--;
    }

    return 0;
}