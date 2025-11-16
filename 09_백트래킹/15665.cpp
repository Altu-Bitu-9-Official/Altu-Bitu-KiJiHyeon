#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> nums;
int answer[8];

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++)
            cout << answer[i] << " ";
        cout << "\n";
        return;
    }

    int last = -1; // 이번 depth에서 이전에 쓴 숫자 기억

    for (int i = 0; i < N; i++) {
        if (last == nums[i]) continue; // 같은 depth에서 중복 방지

        last = nums[i];
        answer[depth] = nums[i];
        dfs(depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    nums.resize(N);

    for (int i = 0; i < N; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    dfs(0);
    return 0;
}
