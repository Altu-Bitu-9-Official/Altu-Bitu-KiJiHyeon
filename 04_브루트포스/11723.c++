#include <iostream>

using namespace std;
int s; // 비어있는 공집합 s

// check로직만 따로 빼도 될듯? 되게 자주 쓰여서.

void bitmasking(string cmd, int n)
{
    if (cmd == "add")
    {
        // if(s &= (1 << (x-1)))
        //     return; 굳이 필요없음.
        s = s | 1 << (n - 1);
    }
    if (cmd == "remove")
    {
        s &= ~(1 << (n - 1));
    }
    if (cmd == "check")
    {
        if (s & (1 << (n - 1)))
            cout << 1 <<'\n';
        else
            cout << 0 << '\n';
    }
    if (cmd == "toggle")
    {
        if (s & (1 << (n - 1)))
            s &= ~(1 << (n - 1));
        else
            s |= (1 << (n - 1));
    }
    if (cmd == "all")
    {
        s = (1 << 20) - 1;
    }
    if (cmd == "empty")
    {
        s = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;

    string cmd;
    int n;

    for (int i = 0; i < m; i++)
    {
        cin >> cmd;
        if (cmd == "add" || cmd == "remove" || cmd == "check" || cmd == "toggle")
            cin >> n;
        else
            n = 0; // 의미 없음

        bitmasking(cmd, n);
    }

    return 0;
}