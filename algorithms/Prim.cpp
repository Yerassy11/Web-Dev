#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG_INF = -1; // маркер отсутствия ребра

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    // Ввод: n вершин (1..n), m рёбер
    cin >> n >> m;

    // adjacency list: for each vertex store (neighbor, weight)
    vector<vector<pair<int,ll>>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        // предполагаем неориентированный граф
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Prim с приоритетной очередью (min-heap)
    vector<char> used(n + 1, 0);            // visited / included in MST
    vector<ll> minEdge(n + 1, (1LL<<60));  // минимальный вес ребра, соединяющего вершину с MST
    vector<int> parent(n + 1, -1);         // родитель вершины в MST

    // (weight, vertex)
    using pli = pair<ll,int>;
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    // стартуем с вершины 1 (можно выбрать любую)
    minEdge[1] = 0;
    pq.push({0, 1});

    ll totalWeight = 0;
    vector<pair<int,int>> mstEdges; // список ребер MST (u,v), в котором parent[v] = u

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();

        if (used[v]) continue;       // уже включена в MST
        used[v] = 1;
        totalWeight += w;

        if (parent[v] != -1) {
            mstEdges.push_back({parent[v], v});
        }

        // Рассматриваем все соседние рёбра
        for (auto &e : adj[v]) {
            int to = e.first;
            ll wt = e.second;
            if (!used[to] && wt < minEdge[to]) {
                minEdge[to] = wt;
                parent[to] = v;
                pq.push({wt, to});
            }
        }
    }

    // Проверка связности: если какая-то вершина не использована — MST не существует
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            cout << "Graph is not connected, MST does not exist\n";
            return 0;
        }
    }

    // Вывод результата
    cout << "Total MST weight: " << totalWeight << "\n";
    cout << "Edges in MST (" << mstEdges.size() << "):\n";
    for (auto &e : mstEdges) {
        cout << e.first << " " << e.second << "\n";
    }

    return 0;
}
