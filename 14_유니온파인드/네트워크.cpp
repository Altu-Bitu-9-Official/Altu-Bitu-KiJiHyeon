#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

// Find (경로 압축)
int findParent(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = findParent(parent[x]);
}

// Union (size 기준)
void unite(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a == b) return;

    // a 집합이 더 작으면 swap
    if (parent[a] > parent[b]) swap(a, b);

    parent[a] += parent[b];
    parent[b] = a;
}

int solution(int n, vector<vector<int>> computers) {
    parent.assign(n, -1);

    // 연결 정보로 union
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (computers[i][j] == 1) {
                unite(i, j);
            }
        }
    }

    // 루트 개수 = 네트워크 개수
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] < 0) answer++;
    }

    return answer;
}

// 테스트용 main
int main() {
    int n1 = 3;
    vector<vector<int>> c1 = {{1,1,0},{1,1,0},{0,0,1}};
    cout << solution(n1, c1) << '\n'; // 2

    int n2 = 3;
    vector<vector<int>> c2 = {{1,1,0},{1,1,1},{0,1,1}};
    cout << solution(n2, c2) << '\n'; // 1
}
