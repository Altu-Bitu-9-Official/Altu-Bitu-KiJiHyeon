#include <iostream>
#include <string>
using namespace std;

bool chess[8][8];

void moveTo(string dst, int& kingCol, int& kingRow, int& rockCol, int& rockRow) {
    int dCol = 0, dRow = 0;

    if (dst == "R") dCol = 1;
    else if (dst == "L") dCol = -1;
    else if (dst == "B") dRow = -1;
    else if (dst == "T") dRow = 1;
    else if (dst == "RT") { dCol = 1; dRow = 1; }
    else if (dst == "LT") { dCol = -1; dRow = 1; }
    else if (dst == "RB") { dCol = 1; dRow = -1; }
    else if (dst == "LB") { dCol = -1; dRow = -1; }

    int newKingCol = kingCol + dCol;
    int newKingRow = kingRow + dRow;

    // 킹이 체스판 밖으로 나가면 이동 불가
    if (newKingCol < 0 || newKingCol > 7 || newKingRow < 0 || newKingRow > 7)
        return;

    // 돌과 부딪힘
    if (newKingCol == rockCol && newKingRow == rockRow) {
        int newRockCol = rockCol + dCol;
        int newRockRow = rockRow + dRow;

        // 돌이 체스판 밖으로 나가면 이동 불가
        if (newRockCol < 0 || newRockCol > 7 || newRockRow < 0 || newRockRow > 7)
            return;

        // 돌 이동
        rockCol = newRockCol;
        rockRow = newRockRow;
    }

    // 킹 이동
    kingCol = newKingCol;
    kingRow = newKingRow;
}

int main() {
    string kingPos, rockPos;
    int n;
    cin >> kingPos >> rockPos >> n;

    int kingCol = kingPos[0] - 'A';
    int kingRow = kingPos[1] - '1';
    int rockCol = rockPos[0] - 'A';
    int rockRow = rockPos[1] - '1';

    string dst;
    for (int i = 0; i < n; i++) {
        cin >> dst;
        moveTo(dst, kingCol, kingRow, rockCol, rockRow);
    }

    char kingfCol = 'A' + kingCol;
    char kingfRow = '1' + kingRow;
    char rockfCol = 'A' + rockCol;
    char rockfRow = '1' + rockRow;

    cout << string(1, kingfCol) + string(1, kingfRow) << "\n"
         << string(1, rockfCol) + string(1, rockfRow);
}
