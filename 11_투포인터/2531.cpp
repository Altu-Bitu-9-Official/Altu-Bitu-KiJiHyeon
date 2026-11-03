#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> belt(N);
    for (int i = 0; i < N; i++)
        cin >> belt[i];

    vector<int> cnt(d + 1, 0); // 각 초밥 종류 개수
    int kinds = 0;

    // 초기 윈도우 설정
    for (int i = 0; i < k; i++) {
        if (cnt[belt[i]] == 0) kinds++;
        cnt[belt[i]]++;
    }

    int answer = kinds;
    // 쿠폰 고려
    if (cnt[c] == 0) answer++;

    // 슬라이딩 윈도우
    for (int i = 1; i < N; i++) {
        int remove_sushi = belt[i - 1];
        cnt[remove_sushi]--;
        if (cnt[remove_sushi] == 0) kinds--;

        int add_sushi = belt[(i + k - 1) % N];
        if (cnt[add_sushi] == 0) kinds++;
        cnt[add_sushi]++;

        int current = kinds;
        if (cnt[c] == 0) current++;

        answer = max(answer, current);
    }

    cout << answer << "\n";
    return 0;
}
