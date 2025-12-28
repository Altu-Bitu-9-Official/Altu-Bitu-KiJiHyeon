#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // 경로 압축
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        if (find(u) == find(v)) {
            cout << i << '\n';
            return 0;
        }
        unite(u, v);
    }

    cout << 0 << '\n';
    return 0;
}
