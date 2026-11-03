#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    double cost;
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

    vector<pair<int,int>> pos(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    parent.assign(N + 1, -1);

    // 이미 연결된 통로
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    vector<Edge> edges;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            double dx = pos[i].first - pos[j].first;
            double dy = pos[i].second - pos[j].second;
            double dist = sqrt(dx*dx + dy*dy);
            edges.push_back({i, j, dist});
        }
    }

    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a.cost < b.cost;
    });

    double answer = 0.0;
    for (auto &e : edges) {
        if (unite(e.u, e.v)) {
            answer += e.cost;
        }
    }

    cout << fixed << setprecision(2) << answer << '\n';
    return 0;
}
