
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// c - color amount
const int MAX_N = 10, MAX_C = 9;
int n, c = MAX_C, grid[MAX_N][MAX_N];
int isColorPossible[MAX_C+1], colorPos[MAX_C+1][4]; /*
0 - Hasn't appeared
1 - Has appeared and is possible
-1 - Hasn't appeared and isn't possible
------------------
0 - x1
1 - y1
2 - x2
3 - y2
*/
vector<pair<int, bool>> rectRows, rectCols;



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string curLine;
        cin >> curLine;
        for (int j = 0; j < n; j++) {   
            int curChar = (int)(curLine[j]-'0');
            isColorPossible[curChar] = 1;
            colorPos[curChar][0] = min(colorPos[curChar][0], j);
            colorPos[curChar][1] = min(colorPos[curChar][1], i);
            colorPos[curChar][2] = max(colorPos[curChar][2], j);
            colorPos[curChar][3] = max(colorPos[curChar][3], i);
        }
    }
    for (int i = 1; i <= c; i++) {
        if (isColorPossible[i]) {
            // Inclusive
            rectRows.push_back({colorPos[i][0], false});
            rectCols.push_back({colorPos[i][2], false});
            // Exclusive
            rectRows.push_back({colorPos[i][1]+1, true});
            rectCols.push_back({colorPos[i][3]+1, true});
        }
    }

    sort(rectRows.begin(), rectRows.end());
    sort(rectCols.begin(), rectCols.end());

    // RIGHT_NOW: Create the bounding mechanism
    for (int i = 0; i < n; i++) {
        auto rowPointer = rectRows.begin();
        for (int j = 0; j < n; j++) {
            auto colPointer = rectCols.begin();
        }
    }

}