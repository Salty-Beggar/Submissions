#include <iostream>
#include <string>
 
using namespace std;
 
long int ans;
bool chessBoard[8][8], freeLines[8][2], freeDiags[15][2];
 
void _solve(int x, int y, int count) {
    if (count == 8) {
        ans++; 
        return;
    }
    for (int i = x; i < 8; i++) {
        for (int j = y; j < 8; j++) {
            y = 0;
            int curNegativeDiag = 7+i-j;
            int curPositiveDiag = 14-i-j;
            if (!chessBoard[i][j] && !freeLines[i][0] && !freeLines[j][1] && !freeDiags[curNegativeDiag][0] && !freeDiags[curPositiveDiag][1]) {
                freeLines[i][0] = true;
                freeLines[j][1] = true;
                freeDiags[curNegativeDiag][0] = true;
                freeDiags[curPositiveDiag][1] = true;
                _solve(i, j, count+1);
                freeLines[i][0] = false;
                freeLines[j][1] = false;
                freeDiags[curNegativeDiag][0] = false;
                freeDiags[curPositiveDiag][1] = false;
            }
        }
    }
}
 
int main() {
    for (int i = 0; i < 8; i++) {
        string curLine;
        cin >> curLine;
        for (int j = 0; j < 8; j++) {
            char curChar = curLine[j];
            if (curChar == '*') chessBoard[i][j] = true;
        }
    }
 
    _solve(0, 0, 0);
    cout << ans;
 
    return 0;
}