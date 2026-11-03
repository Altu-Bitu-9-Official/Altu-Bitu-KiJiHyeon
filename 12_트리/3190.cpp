#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n, k, l;
int board[101][101];

int dx[4] = {0, 1, 0, -1}; // 동, 남, 서, 북
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1; // 사과
    }

    cin >> l;
    vector<pair<int, char>> cmd(l);
    for (int i = 0; i < l; i++)
    {
        cin >> cmd[i].first >> cmd[i].second;
    }

    deque<pair<int, int>> snake;
    snake.push_back({1, 1});
    board[1][1] = 2; // 뱀

    int time = 0;
    int dir = 0; // 0:동,1:남,2:서,3:북
    int idx = 0; // direction command index

    while (true)
    {
        time++;

        int hx = snake.front().first;
        int hy = snake.front().second;

        int nx = hx + dx[dir];
        int ny = hy + dy[dir];

        // 벽 또는 몸과 부딪힘
        if (nx < 1 || nx > n || ny < 1 || ny > n)
            break;
        if (board[nx][ny] == 2)
            break;

        // 이동
        if (board[nx][ny] == 1)
        {
            // 사과가 있을 경우: 머리만 늘어난다.
            snake.push_front({nx, ny});
            board[nx][ny] = 2;
        }
        else
        {
            // 빈 칸: 머리 늘리고 꼬리 줄임
            snake.push_front({nx, ny});
            board[nx][ny] = 2;

            auto tail = snake.back();
            snake.pop_back();
            board[tail.first][tail.second] = 0;
        }

        // 방향 전환 처리
        if (idx < l && time == cmd[idx].first)
        {
            if (cmd[idx].second == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
            idx++;
        }
    }

    cout << time << "\n";
    return 0;
}
