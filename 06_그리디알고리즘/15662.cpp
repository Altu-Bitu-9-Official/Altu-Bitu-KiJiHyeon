#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> gears;
vector<int> dirs;

// 회전 함수
void rotateGear(vector<int>& gear, int dir) {
    if (dir == 1) { // 시계 방향
        int last = gear.back();
        for (int i = 7; i > 0; --i) gear[i] = gear[i - 1];
        gear[0] = last;
    } else if (dir == -1) { // 반시계 방향
        int first = gear[0];
        for (int i = 0; i < 7; ++i) gear[i] = gear[i + 1];
        gear[7] = first;
    }
}

//회전
void checkAndRotate(int idx, int dir) {
    int n = gears.size();
    dirs.assign(n, 0);
    dirs[idx] = dir;

    // 왼
    for (int i = idx - 1; i >= 0; --i) {
        if (gears[i][2] != gears[i + 1][6])
            dirs[i] = -dirs[i + 1];
        else
            break;
    }

    // 오
    for (int i = idx + 1; i < n; ++i) {
        if (gears[i - 1][2] != gears[i][6])
            dirs[i] = -dirs[i - 1];
        else
            break;
    }

    // 실제 회전
    for (int i = 0; i < n; ++i)
        if (dirs[i] != 0)
            rotateGear(gears[i], dirs[i]);
}

// 12시 방향이 S(1)인 톱니 개수 세기
int countSAtTop() {
    int cnt = 0;
    for (auto& g : gears)
        if (g[0] == 1)
            cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N; // 톱니바퀴 개수

    gears.assign(N, vector<int>(8));
    dirs.resize(N);

    // 각 톱니바퀴 상태 입력
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        if (s.size() < 8) { // 입력 오류 방지
            cerr << "Invalid gear input length\n"; //에러 뜸.
            return 1;
        }
        for (int j = 0; j < 8; ++j)
            gears[i][j] = s[j] - '0'; // N=0, S=1
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int num, dir;
        cin >> num >> dir;
        if (num < 1 || num > N) continue; // 안전 체크
        checkAndRotate(num - 1, dir);
    }

    cout << countSAtTop() << "\n";
    return 0;
}
