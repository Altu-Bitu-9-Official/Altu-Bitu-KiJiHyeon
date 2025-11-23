#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;

    vector<int> x(M);

    for (int i = 0; i < M; i++) cin >> x[i];

    // 가로등 높이 h가 주어졌을 때 전체를 밝힐 수 있는지 확인

    auto can = [&](int h) -> bool {

        int covered = 0;        // 현재까지 커버된 가장 오른쪽 지점

        for (int i = 0; i < M; i++) {

            int left = x[i] - h;     // 이 가로등이 비추는 왼쪽 끝

            int right = x[i] + h;    // 이 가로등이 비추는 오른쪽 끝

            if (left > covered)  // 이전 가로등 범위와 연결 안 됨

                return false;

            covered = right;

            if (covered >= N) return true; // 끝까지 덮으면 성공

        }

        return covered >= N;

    };

    int left = 0, right = N, ans = N;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (can(mid)) {

            ans = mid;          // 가능한 높이면 줄여봄

            right = mid - 1;

        } else {

            left = mid + 1;     // 불가능 → 더 높여야 함

        }

    }

    cout << ans << '\n';

    return 0;

}