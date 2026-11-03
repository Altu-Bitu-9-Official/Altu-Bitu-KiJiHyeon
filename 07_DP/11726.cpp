#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[1001];
    dp[1] = 1; // 2×1은 세로 하나로만 채움
    dp[2] = 2; //2x2는 세로 2개, 가로 2개의 케이스.
 
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007; //이전 게 세로였는지 / 가로였는지
    }

    cout << dp[n] << '\n';
    return 0;
}
