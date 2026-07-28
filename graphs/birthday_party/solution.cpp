#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> disc, low;
vector<bool> visited;
int timer_;
bool has_bridge;

void find_bridges(int start) {
    stack<tuple<int,int,int>> st;
    st.push({start, -1, 0});
    visited[start] = true;
    disc[start] = low[start] = timer_++;

    while (!st.empty()) {
        auto& [u, parent, idx] = st.top();

        if (idx < (int)adj[u].size()) {
            int v = adj[u][idx];
            idx++; // avança o índice para a próxima iteração

            if (v == parent) continue; // ignora aresta de volta ao pai

            if (visited[v]) {
                // back edge
                low[u] = min(low[u], disc[v]);
            } else {
                // tree edge: "desce" empilhando o filho
                visited[v] = true;
                disc[v] = low[v] = timer_++;
                st.push({v, u, 0});
            }
        } else {
            // terminou de processar todos os vizinhos de u, "sobe" (backtrack)
            st.pop();
            if (!st.empty()) {
                auto& [pu, pparent, pidx] = st.top();
                low[pu] = min(low[pu], low[u]);
                if (low[u] > disc[pu]) {
                    has_bridge = true; // aresta (pu, u) é ponte
                }
            }
        }
    }
}

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        adj.assign(n + 1, {});   // pessoas numeradas de 1 a n
        disc.assign(n + 1, -1);
        low.assign(n + 1, -1);
        visited.assign(n + 1, false);
        timer_ = 0;
        has_bridge = false;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // o grafo deve ser conexo (todo mundo alcança todo mundo),
        // mas por segurança rodamos a partir de todo nó não visitado
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                find_bridges(i);
            }
        }

        cout << (has_bridge ? "Yes" : "No") << "\n";
    }
}