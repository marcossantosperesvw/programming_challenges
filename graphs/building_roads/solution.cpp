#include <bits/stdc++.h>
using namespace std;


void dfs(int current_node, vector<bool>& visited, vector<vector<int>>& adj) {
    if (visited[current_node]) { return; }
	visited[current_node] = true;
    
	for (int neighbor : adj[current_node]) { dfs(neighbor, visited, adj); }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--,b--;


        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool> visited = vector<bool>(n,false);
    vector<int> leaders;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) { 
            leaders.push_back(i);
            dfs(i, visited, adj);
        
        }
	}

    int k = (int)leaders.size() -1;
    cout << k << endl;


    for(int i = 0; i < k; i++){
        cout << leaders[i] + 1 << " " << leaders[i+1] + 1<< endl;

    }

    return 0;

    

    
}