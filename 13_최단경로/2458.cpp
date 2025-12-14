#include <iostream>
using namespace std;

bool adj[501][501];

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = true;
    }

    // 플로이드 워셜
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (adj[i][k] && adj[k][j])
                {
                    adj[i][j] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= N; j++)
        {
            if (adj[i][j] || adj[j][i])
                cnt++;
        }
        if (cnt == N - 1)
            ans++;
    }

    cout << ans;
    return 0;
}
