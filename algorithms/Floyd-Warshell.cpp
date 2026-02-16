#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

vector<int> build_path(int u, int v, const vector<vector<int>>& next) {
    vector<int> path;
    if (next[u][v] == -1) return path; // пути нет
    int cur = u;
    path.push_back(cur);
    while (cur != v) {
        cur = next[cur][v];
        // защита от бесконечного цикла (на случай отрицательного цикла)
        if (cur == -1) return {};
        path.push_back(cur);
    }
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    // Ввод: n вершин (0..n-1), m рёбер
    cin >> n >> m;

    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    vector<vector<int>> next(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w; // предполагаем 0-based; если 1-based, уменьшите
        dist[u][v] = min(dist[u][v], w); // если несколько рёбер
        next[u][v] = v;
    }

    // Алгоритм Флойда–Уоршелла
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] == INF) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // Проверка отрицательных циклов
    bool hasNegCycle = false;
    for (int v = 0; v < n; ++v) {
        if (dist[v][v] < 0) {
            hasNegCycle = true;
            break;
        }
    }

    if (hasNegCycle) {
        cout << "Graph contains a negative-weight cycle\n";
    } else {
        // пример: вывести матрицу расстояний
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] == INF) cout << "INF ";
                else cout << dist[i][j] << " ";
            }
            cout << '\n';
        }

        // пример восстановления пути u->v
        int u, v;
        if (cin >> u >> v) {
            vector<int> path = build_path(u, v, next);
            if (path.empty()) cout << "No path\n";
            else {
                for (size_t t = 0; t < path.size(); ++t) {
                    if (t) cout << " -> ";
                    cout << path[t];
                }
                cout << '\n';
            }
        }
    }

    return 0;
}
