#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<bool> wheelLeft(N, false); //차있는지 아닌지 구별할 벡터
    vector<char> wheel(N, '?'); //알파벳 채울 벡터

    int num = 0; // 화살표 위치 (0부터 시작)

    for (int i = 0; i < K; i++) {
        int n;
        char s;
        cin >> n >> s;

        // 회전 먼저
        num = (num + n) % N;

        // 현재 화살표 위치에 글자 쓰기
        if (wheelLeft[num]) { // 이미 채워져 있다면
            if (wheel[num] != s) { // 다른 글자면 모순
                cout << "!\n";
                return 0;
            }
        } else { // 비어있으면
            wheel[num] = s;
            wheelLeft[num] = true;
        }
    }

    // 중복 알파벳 체크
    vector<bool> used(26, false);
    for (int i = 0; i < N; i++) {
        if (wheelLeft[i]) {
            int idx = wheel[i] - 'A';
            if (used[idx]) {
                cout << "!\n";
                return 0;
            }
            used[idx] = true;
        }
    }

    // 출력
    for (int i = 0; i < N; i++) {
        int idx = (num - i + N) % N;  //시계방향 기준 마지막 칸부터 출력
        cout << wheel[idx];
    }
    cout << '\n';

    return 0;
}
