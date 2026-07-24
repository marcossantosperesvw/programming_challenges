#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<pair<int, int>>& moo_position, pair<int, int>& min_pos, pair<int, int>& max_pos){
    min_pos.first = min(min_pos.first, moo_position[node].first);
    min_pos.second = min(min_pos.second, moo_position[node].second);
    max_pos.first = max(max_pos.first, moo_position[node].first);
    max_pos.second = max(max_pos.second, moo_position[node].second);
    
    visited[node] = true;
    for(int neighbor : adj[node]){
        if(!visited[neighbor]){
            dfs(neighbor, adj, visited, moo_position, min_pos, max_pos);
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> moo_position;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        moo_position.push_back({x, y});
    }

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    

    
    
    vector<bool> visited(n, false);
    int perimeter = INT_MAX;
    for(int i = 0; i < n; i++){
        if (!visited[i]) {
            pair<int , int> min_pos = {INT_MAX, INT_MAX};
            pair<int , int> max_pos = {INT_MIN, INT_MIN};
            dfs(i, adj, visited, moo_position, min_pos, max_pos);
            perimeter = min(perimeter, 2 * (max_pos.first - min_pos.first + max_pos.second - min_pos.second));
        }
    }



    cout << perimeter << endl;




    return 0;
    
}   