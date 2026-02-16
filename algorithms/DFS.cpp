#include <bits/stdc++.h>
using namespace std;

void dfs(int v,
         const vector<vector<int>>& adj,
         vector<bool>& visited,
         vector<int>& parent) {
    visited[v] = true;

    for (int to : adj[v]) {
        if (!visited[to]) {
            parent[to] = v;
            dfs(to, adj, visited, parent);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // Для неориентированного графа:
        // adj[v].push_back(u);
    }

    // (необязательно) сортировка для фиксированного порядка обхода
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    // DFS для всех компонент связности
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            parent[v] = 0;   // корень DFS-дерева
            dfs(v, adj, visited, parent);
        }
    }

    // Вывод родителей
    cout << "Vertex : Parent\n";
    for (int v = 1; v <= n; v++) {
        cout << v << " : " << parent[v] << "\n";
    }

    return 0;
}
