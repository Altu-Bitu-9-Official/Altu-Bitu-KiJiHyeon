#include <bits/stdc++.h>
using namespace std;

int N, M;
int r, c, d;
int board[51][51];
bool cleaned[51][51];

// 북(0), 동(1), 남(2), 서(3)
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    int cnt = 0;

    while (true) {
        // 1. 현재 칸 청소
        if (!cleaned[r][c]) {
            cleaned[r][c] = true;
            cnt++;
        }

        // 2. 왼쪽 방향부터 4방향 확인
        bool moved = false;
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4; // 왼쪽 회전
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (board[nr][nc] == 0 && !cleaned[nr][nc]) {
                // 전진
                r = nr;
                c = nc;
                moved = true;
                break;
            }
        }

        if (moved) continue;

        // 3. 네 방향 모두 청소 불가 → 뒤로 후진
        int back_dir = (d + 2) % 4;
        int br = r + dr[back_dir];
        int bc = c + dc[back_dir];

        if (board[br][bc] == 1) break; // 뒤가 벽 → 종료

        r = br;
        c = bc;
    }

    cout << cnt << "\n";
    return 0;
}
