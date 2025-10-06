#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
vector<bool> isPrime(MAX + 1, true);

void findPrime() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
}

string funcGold(int n) {
    for (int i = 3; i <= n / 2; i += 2) {
        if (isPrime[i]) {
            int diff = n - i;
            if (diff % 2 == 1 && isPrime[diff]) {
                return to_string(n) + " = " + to_string(i) + " + " + to_string(diff);
            }
        }
    }
    return "Goldbach's conjecture is wrong.";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    findPrime();

    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << funcGold(n) << '\n';
    }
    return 0;
}
