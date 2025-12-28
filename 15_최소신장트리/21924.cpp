#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

vector<int> parent;

int findParent(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = findParent(parent[x]);
}

bool unite(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false;

    if (parent[a] > parent[b]) swap(a, b);
    parent[a] += parent[b];
    parent[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    long long totalCost = 0;

    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        totalCost += edges[i].w;
    }

    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b) {
             return a.w < b.w;
         });

    parent.assign(N + 1, -1);

    long long mstCost = 0;
    int used = 0;

    for (auto &e : edges) {
        if (unite(e.u, e.v)) {
            mstCost += e.w;
            used++;
        }
    }

    // 모든 도시 연결 불가능
    if (used != N - 1) {
        cout << -1 << '\n';
        return 0;
    }

    cout << totalCost - mstCost << '\n';
    return 0;
}
