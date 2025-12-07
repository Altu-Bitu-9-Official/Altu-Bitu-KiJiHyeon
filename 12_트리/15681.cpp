#include <iostream>
#include <vector>
using namespace std;

static const int MAX = 100000 + 1;

vector<int> graph[MAX];
int subtreeSize[MAX];
bool visited[MAX];

int n, r, q;

/* u를 루트로 하는 서브트리의 크기를 계산 */
int dfs(int u)
{
    visited[u] = true;
    int cnt = 1; // 자기 자신 1개 포함

    for (int nxt : graph[u])
    {
        if (!visited[nxt])
        {
            cnt += dfs(nxt); // 자식 서브트리 크기 더한다
        }
    }

    subtreeSize[u] = cnt;
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(r);

    while (q--)
    {
        int x;
        cin >> x;
        cout << subtreeSize[x] << "\n";
    }

    return 0;
}
