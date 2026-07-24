#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int dfs(int node, vector<bool>& visited) {
    visited[node] = true;
    int vacas_alcançadas = 1; // Conta a própria vaca atual

    for (int vizinho : adj[node]) {
        if (!visited[vizinho]) {
            vacas_alcançadas += dfs(vizinho, visited);
        }
    }

    return vacas_alcançadas;
}

int main() {
    int N;
    cin >> N;   

    vector<vector<int>> vacas(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        cin >> vacas[i][0] >> vacas[i][1] >> vacas[i][2];
    }

    adj.resize(N);

    // Construção do grafo sem usar float/sqrt
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue; 

            int dx = vacas[i][0] - vacas[j][0];
            int dy = vacas[i][1] - vacas[j][1];
            int p1 = vacas[i][2];

            if (dx * dx + dy * dy <= p1 * p1) {
                adj[i].push_back(j);
            }
        }
    }

    int max_vacas = 0;

    for (int i = 0; i < N; i++) {
        vector<bool> visited(N, false); 
        int alcancadas = dfs(i, visited);
        max_vacas = max(max_vacas, alcancadas);
    }

    cout << max_vacas << "\n";

    return 0;
}