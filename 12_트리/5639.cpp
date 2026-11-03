#include <iostream>
#include <vector>
using namespace std;

vector<int> pre;

/*
    pre[l] ~ pre[r-1] 구간을 처리한다.
    preorder → postorder 로 변환
*/
void solve(int l, int r)
{
    if (l >= r)
        return;

    int root = pre[l];

    int idx = l + 1;
    // 왼쪽 서브트리는 root보다 작은 값들
    while (idx < r && pre[idx] < root)
        idx++;

    // [l+1, idx) : left subtree
    solve(l + 1, idx);
    // [idx, r) : right subtree
    solve(idx, r);

    cout << root << "\n"; // postorder: left → right → root
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while (cin >> x)
    {
        pre.push_back(x);
    }

    solve(0, pre.size());
    return 0;
}
