#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> a(n), dp(n, 1); //dp는 a[i]를 마지막 원소로 가지는 가장 긴 증가하는 부분 수열의 길이
    //모든 원소는 자기 자신으로 길이 1짜리 수열을 만들 수 있음. 
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}
