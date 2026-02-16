#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    // Ввод: n (кол-во вершин), m (кол-во рёбер)
    // Затем m строк: u v w  (ориентированное ребро u -> v с весом w)
    // Для неориентированного графа добавляйте оба направления.
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int,ll>>> adj(n + 1); // 1-based
    for (int i = 0; i < m; ++i) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // Для неориентированного:
        // adj[v].push_back({u, w});
    }

    int src;
    cin >> src;

    vector<ll> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    dist[src] = 0;

    // min-heap: pairs (dist, vertex)
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue; // устаревшая запись

        for (auto &e : adj[u]) {
            int v = e.first;
            ll w = e.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Вывод расстояний
    for (int v = 1; v <= n; ++v) {
        if (dist[v] == INF) cout << "INF";
        else cout << dist[v];
        if (v < n) cout << ' ';
    }
    cout << '\n';

    // Пример восстановления пути до целевой вершины t (если вводится)
    int t;
    if (cin >> t) {
        if (dist[t] == INF) {
            cout << "No path to " << t << '\n';
        } else {
            vector<int> path;
            for (int cur = t; cur != -1; cur = parent[cur]) path.push_back(cur);
            reverse(path.begin(), path.end());
            for (size_t i = 0; i < path.size(); ++i) {
                if (i) cout << " -> ";
                cout << path[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
