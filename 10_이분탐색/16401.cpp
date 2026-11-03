#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int M, N; // M: 조카 수, N: 과자 수

    cin >> M >> N;

    vector<int> snack(N);

    int max_len = 0; // 과자 중 가장 긴 길이

    for (int i = 0; i < N; i++) {

        cin >> snack[i];

        if (snack[i] > max_len) max_len = snack[i];

    }

    // 막대 과자의 길이 L을 이분 탐색

    // L: 1 ~ max_len 사이의 정수

    long long left = 1;

    long long right = max_len;

    long long answer = 0;

    auto can = [&](long long len) -> bool {

        if (len == 0) return true; // 실제로는 len을 0으로 안 넣음

        long long cnt = 0; // len 길이로 잘랐을 때 만들 수 있는 조각 수

        for (int i = 0; i < N; i++) {

            cnt += snack[i] / len;

            if (cnt >= M) return true; // 이미 M명 이상 나눠줄 수 있으면 true

        }

        return cnt >= M;

    };

    while (left <= right) {

        long long mid = (left + right) / 2; // 후보 길이

        if (can(mid)) {

            // mid 길이로 M명 모두에게 줄 수 있음 -> 더 길게 줄 수 있는지 시도

            answer = mid;

            left = mid + 1;

        } else {

            // mid 길이로는 부족 -> 길이를 줄여야 함

            right = mid - 1;

        }

    }

    // 하나도 줄 수 없는 경우에는 answer가 0 그대로

    cout << answer << '\n';

    return 0;

}