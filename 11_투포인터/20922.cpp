#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    unordered_map<int,int> cnt;  // 숫자별 등장 횟수
    int left = 0;
    int ans = 0;

    for (int right = 0; right < N; right++) {
        cnt[a[right]]++;

        // K를 초과하면 left 이동
        while (cnt[a[right]] > K) {
            cnt[a[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans << "\n";
    return 0;
}
