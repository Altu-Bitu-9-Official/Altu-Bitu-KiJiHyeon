#include <iostream>
#include <deque>
using namespace std;

#define DODO 0
#define SUYEON 1

struct Player {
    deque<int> deck;
    deque<int> field;
};

// 필드의 카드들을 뒤집어서 덱 아래에 넣기
void collect(Player& p, Player& enemy) {
    while (!enemy.field.empty()) {
        p.deck.push_back(enemy.field.back());
        enemy.field.pop_back();
    }
    while (!p.field.empty()) {
        p.deck.push_back(p.field.back());
        p.field.pop_back();
    }
}

// 종 울릴 수 있는지 확인 (도도=0, 수연=1, 아니면 -1)
int bellCheck(Player& dodo, Player& suyeon) {
    if (!dodo.field.empty() && dodo.field.front() == 5) return DODO;
    if (!suyeon.field.empty() && suyeon.field.front() == 5) return DODO;
    if (!dodo.field.empty() && !suyeon.field.empty() &&
        dodo.field.front() + suyeon.field.front() == 5)
        return SUYEON;
    return -1;
}

// m번 게임 진행
string playGame(int m, Player& dodo, Player& suyeon) {
    bool turn = DODO;
    while (m--) {
        Player& cur = (turn == DODO ? dodo : suyeon);
        Player& opp = (turn == DODO ? suyeon : dodo);

        // 덱에서 한 장 꺼내 필드에 올림
        cur.field.push_front(cur.deck.front());
        cur.deck.pop_front();

        // 덱이 비면 즉시 종료
        if (cur.deck.empty()) break;

        int bell = bellCheck(dodo, suyeon);
        if (bell == DODO) collect(dodo, suyeon);
        else if (bell == SUYEON) collect(suyeon, dodo);

        turn = !turn;
    }

    if (dodo.deck.size() > suyeon.deck.size()) return "do";
    if (dodo.deck.size() < suyeon.deck.size()) return "su";
    return "dosu";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Player dodo, suyeon;
    while (n--) {
        int a, b;
        cin >> a >> b;
        dodo.deck.push_front(a);
        suyeon.deck.push_front(b);
    }

    cout << playGame(m, dodo, suyeon);
    return 0;
}
