#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int w0, m0, T;
    int d, in, act;
    cin >> w0 >> m0 >> T;
    cin >> d >> in >> act;

    // 변화 없는 경우
    int w_fix = w0;
    int m_fix = m0;

    // 변화 고려하는 경우
    int w_var = w0;
    int m_var = m0;

    for (int day = 0; day < d; day++) {
        // 체중 계산
        w_fix += in - (m_fix + act);
        w_var += in - (m_var + act);

        // 기초대사량 변화
        int diff = in - (m_var + act);
        if (abs(diff) > T) {
            // C++에서 음수 나눗셈 주의 → double로 계산 후 내림
            m_var += (int)floor(diff / 2.0);
        }
    }

    // 출력
    if (w_fix <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << w_fix << " " << m_fix << "\n";
    }

    if (w_var <= 0 || m_var <= 0) {
        cout << "Danger Diet";
    } else {
        cout << w_var << " " << m_var << " ";
        cout << (m_var < m0 ? "YOYO" : "NO");
    }

    return 0;
}
