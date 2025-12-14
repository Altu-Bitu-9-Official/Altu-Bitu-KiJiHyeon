#include <iostream>
#include <vector>
using namespace std;

bool board[101][101];

// 우, 상, 좌, 하
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> dir;
        dir.push_back(d);

        // 세대 확장
        for (int i = 0; i < g; i++)
        {
            for (int j = dir.size() - 1; j >= 0; j--)
            {
                dir.push_back((dir[j] + 1) % 4);
            }
        }

        // 시작점 표시
        board[y][x] = true;

        // 방향 따라 이동
        for (int k : dir)
        {
            x += dx[k];
            y += dy[k];
            board[y][x] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] &&
                board[i + 1][j] &&
                board[i][j + 1] &&
                board[i + 1][j + 1])
            {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}
