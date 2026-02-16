#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rankv; // rank (высота) или размер — для объединения по рангу/размеру

    DSU(int n) : parent(n+1), rankv(n+1, 0) {
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    // find с path compression
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    // unite: возвращает true, если два множества были разъединены и объединились
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    // Ввод: n (вершин), m (рёбер)
    // Затем m строк: u v w (1-based вершины)
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // Сортируем рёбра по весу (возрастание)
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){
        return a.w < b.w;
    });

    DSU dsu(n);
    long long mst_weight = 0;
    vector<Edge> mst_edges;
    mst_edges.reserve(n-1);

    for (const auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_weight += e.w;
            mst_edges.push_back(e);
            if ((int)mst_edges.size() == n - 1) break; // можно завершить рано
        }
    }

    if ((int)mst_edges.size() != n - 1) {
        cout << "MST не существует: граф несвязен\n";
    } else {
        cout  << mst_weight << "\n";
        
    }

    return 0;
}

