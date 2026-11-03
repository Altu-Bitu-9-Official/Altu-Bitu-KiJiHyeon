#include <bits/stdc++.h>
using namespace std;

// 0~9의 7세그먼트 비트마스크
int seg[10] = {
    0b1110111, // 0
    0b0010010, // 1
    0b1011101, // 2
    0b1011011, // 3
    0b0111010, // 4
    0b1101011, // 5
    0b1101111, // 6
    0b1010010, // 7
    0b1111111, // 8
    0b1111011  // 9
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, P, X;
    cin >> N >> K >> P >> X;

    // 숫자 a -> b 바꾸는 비용 미리 계산
    int cost[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cost[i][j] = __builtin_popcount(seg[i] ^ seg[j]);
        }
    }

    // 현재 층 X를 K자리 문자열로
    string cur = to_string(X);
    while ((int)cur.size() < K) cur = "0" + cur;

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        if (i == X) continue;

        string target = to_string(i);
        while ((int)target.size() < K) target = "0" + target;

        int diff = 0;
        for (int d = 0; d < K; d++) {
            int a = cur[d] - '0';
            int b = target[d] - '0';
            diff += cost[a][b];
            if (diff > P) break;
        }

        if (diff <= P) answer++;
    }

    cout << answer << '\n';
    return 0;
}
