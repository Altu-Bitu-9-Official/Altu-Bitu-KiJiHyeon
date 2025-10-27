#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    vector<bool> eaten(N, false); // 햄버거를 이미 먹었는지 표시
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] == 'P') { // 사람이면
            // 왼쪽부터 K칸까지 탐색
            for (int j = i - K; j <= i + K; j++) {
                if (j < 0 || j >= N) continue; // 범위 벗어나면 무시
                if (s[j] == 'H' && !eaten[j]) { 
                    eaten[j] = true; // 햄버거 먹음
                    cnt++;
                    break; // 한 번 먹으면 그만
                }
            }
        }
    }

    cout << cnt;
    return 0;
}
