#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct Fish {
    int r, c, dist;
};

int N;
int board[20][20];
bool visited[20][20];

int dr[4] = {-1, 0, 0, 1}; // 위, 왼, 오른, 아래
int dc[4] = {0, -1, 1, 0};

int main() {
    cin >> N;

    int sr, sc;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                sr = i;
                sc = j;
                board[i][j] = 0;
            }
        }
    }

    int sharkSize = 2;
    int eatCnt = 0;
    int answer = 0;

    while (true) {
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;
        vector<Fish> candidates;

        q.push({sr, sc});
        visited[sr][sc] = true;

        int dist = 0;

        while (!q.empty()) {
            int qs = q.size();
            while (qs--) {
                auto [r, c] = q.front(); q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                    if (visited[nr][nc]) continue;
                    if (board[nr][nc] > sharkSize) continue;

                    visited[nr][nc] = true;
                    q.push({nr, nc});

                    if (board[nr][nc] > 0 && board[nr][nc] < sharkSize) {
                        candidates.push_back({nr, nc, dist + 1});
                    }
                }
            }
            if (!candidates.empty()) break;
            dist++;
        }

        if (candidates.empty()) break;

        sort(candidates.begin(), candidates.end(), [](Fish &a, Fish &b) {
            if (a.dist != b.dist) return a.dist < b.dist;
            if (a.r != b.r) return a.r < b.r;
            return a.c < b.c;
        });

        Fish target = candidates[0];

        answer += target.dist;
        sr = target.r;
        sc = target.c;
        board[sr][sc] = 0;

        eatCnt++;
        if (eatCnt == sharkSize) {
            sharkSize++;
            eatCnt = 0;
        }
    }

    cout << answer << '\n';
    return 0;
}
