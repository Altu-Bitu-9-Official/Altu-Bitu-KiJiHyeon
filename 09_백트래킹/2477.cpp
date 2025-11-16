#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    vector<int> dir(6), len(6);
    for (int i = 0; i < 6; i++)
        cin >> dir[i] >> len[i];

    int maxW = 0, maxH = 0;
    int idxW = -1, idxH = -1;

    // 가장 큰 가로/세로 찾기
    for (int i = 0; i < 6; i++) {
        if (dir[i] == 1 || dir[i] == 2) { // 가로
            if (len[i] > maxW) {
                maxW = len[i];
                idxW = i;
            }
        } else { // 세로(3,4)
            if (len[i] > maxH) {
                maxH = len[i];
                idxH = i;
            }
        }
    }

    // 작은 직사각형의 변: 양옆
    int smallW = abs(len[(idxW + 1) % 6] - len[(idxW + 5) % 6]);
    int smallH = abs(len[(idxH + 1) % 6] - len[(idxH + 5) % 6]);

    int bigArea = maxW * maxH;
    int smallArea = smallW * smallH;

    cout << (bigArea - smallArea) * K << "\n";
    return 0;
}
