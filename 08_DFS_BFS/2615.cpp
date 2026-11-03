#include <iostream>
using namespace std;

int board[20][20];
int dx[4] = {0, 1, 1, -1};  // 우, 하, 우하, 우상
int dy[4] = {1, 0, 1, 1};

bool inRange(int x, int y) {
    return (x >= 0 && x < 19 && y >= 0 && y < 19);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            cin >> board[i][j];

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j] == 0) continue;

            int color = board[i][j];
            for (int dir = 0; dir < 4; dir++) {
                int cnt = 1;
                int x = i, y = j;

                // 한 방향으로 계속 탐색
                while (true) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (!inRange(nx, ny) || board[nx][ny] != color) break;
                    cnt++;
                    x = nx;
                    y = ny;
                }

                // 반대 방향에 같은 돌이 있는 경우 → 중복 제거
                int px = i - dx[dir];
                int py = j - dy[dir];
                if (inRange(px, py) && board[px][py] == color) continue;

                if (cnt == 5) {
                    cout << color << "\n" << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}
