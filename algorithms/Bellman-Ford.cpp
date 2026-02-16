#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

struct Edge { int u, v; ll w; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        // предполагается 1-based вершины; при желании переводите в 0-based
    }

    int src;
    cin >> src;

    vector<ll> dist(V + 1, INF);
    vector<int> parent(V + 1, -1);
    dist[src] = 0;

    // Основная фаза: V-1 проход
    for (int i = 1; i <= V - 1; ++i) {
        bool changed = false;
        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                changed = true;
            }
        }
        if (!changed) break; // ранняя остановка
    }

    // Проверка на отрицательный цикл
    bool hasNegCycle = false;
    for (auto &e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            hasNegCycle = true;
            break;
        }
    }

    if (hasNegCycle) {
        cout << "Graph contains a negative-weight cycle reachable from source\n";
        return 0;
    }

    // Вывод расстояний и (опционально) восстановление пути
    for (int v = 1; v <= V; ++v) {
        if (dist[v] == INF) {
            cout << "dist[" << v << "] = INF\n";
        } else {
            cout << "dist[" << v << "] = " << dist[v] << '\n';
        }
    }

    // пример: восстанавливаем путь до вершины t, если нужно
    int t; // целевая вершина
    if (cin >> t) {
        if (dist[t] == INF) {
            cout << "No path to " << t << '\n';
        } else {
            vector<int> path;
            int cur = t;
            while (cur != -1) {
                path.push_back(cur);
                cur = parent[cur];
            }
            reverse(path.begin(), path.end());
            cout << "Path to " << t << ": ";
            for (size_t i = 0; i < path.size(); ++i) {
                if (i) cout << " -> ";
                cout << path[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
