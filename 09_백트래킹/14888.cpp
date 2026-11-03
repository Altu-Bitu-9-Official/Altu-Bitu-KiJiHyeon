#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> a;
int opCnt[4]; // 0: +, 1: -, 2: *, 3: /
int maxVal = INT_MAX * -1;
int minVal = INT_MAX;

void dfs(int idx, int cur) {
    // idx : 현재까지 사용한 숫자의 인덱스 (cur는 a[idx-1]까지 계산한 값)
    if (idx == N) {
        if (cur > maxVal) maxVal = cur;
        if (cur < minVal) minVal = cur;
        return;
    }

    // + 사용
    if (opCnt[0] > 0) {
        opCnt[0]--;
        dfs(idx + 1, cur + a[idx]);
        opCnt[0]++;
    }
    // - 사용
    if (opCnt[1] > 0) {
        opCnt[1]--;
        dfs(idx + 1, cur - a[idx]);
        opCnt[1]++;
    }
    // * 사용
    if (opCnt[2] > 0) {
        opCnt[2]--;
        dfs(idx + 1, cur * a[idx]);
        opCnt[2]++;
    }
    // / 사용
    if (opCnt[3] > 0) {
        opCnt[3]--;
        // C++ 정수 나눗셈은 0을 기준으로 버림 → 문제 조건과 동일
        dfs(idx + 1, cur / a[idx]);
        opCnt[3]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> opCnt[i];
    }

    dfs(1, a[0]);

    cout << maxVal << "\n" << minVal << "\n";
    return 0;
}
