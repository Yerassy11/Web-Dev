#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int u : graph[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    // Пример графа
    vector<vector<int>> graph = {
        {1, 2},    // 0 -> 1, 2
        {0, 3},    // 1 -> 0, 3
        {0, 4},    // 2 -> 0, 4
        {1},       // 3 -> 1
        {2}        // 4 -> 2
    };

    bfs(0,graph); // старт из вершины 0
}
