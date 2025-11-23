#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> cards(n);

    for (int i = 0; i < n; i++) cin >> cards[i];

    sort(cards.begin(), cards.end());

    int m;

    cin >> m;

    int x;

    while (m--) {

        cin >> x;

        // 이분 탐색으로 존재 여부 확인

        if (binary_search(cards.begin(), cards.end(), x))

            cout << 1 << " ";

        else

            cout << 0 << " ";

    }

    return 0;

}