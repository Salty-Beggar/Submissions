
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 3000;
int n;
bool dp[MAX_N][MAX_N];
/*
0 - Whether it goes down (0), or right (1)
1 - The next non-ambiguous character.
*/
int arr[MAX_N][MAX_N];

int _v(char letter) {
    switch (letter)
    {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    case 'E':
        return 4;
    case 'F':
        return 5;
    case 'G':
        return 6;
    case 'H':
        return 7;
    case 'I':
        return 8;
    case 'J':
        return 9;
    case 'K':
        return 10;
    case 'L':
        return 11;
    case 'M':
        return 12;
    case 'N':
        return 13;
    case 'O':
        return 14;
    case 'P':
        return 15;
    case 'Q':
        return 16;
    case 'R':
        return 17;
    case 'S':
        return 18;
    case 'T':
        return 19;
    case 'U':
        return 20;
    case 'V':
        return 21;
    case 'W':
        return 22;
    case 'X':
        return 23;
    case 'Y':
        return 24;
    case 'Z':
        return 25;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            arr[i][j] = _v(x);
        }
    }

    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    queue<pair<int, int>> bfs;
    bfs.push({0, 0});
    while (!bfs.empty()) {
        int curSize = bfs.size();
        int smallestValue = 26;
        vector<pair<int, int>> smallestCells;
        for (int i = 0; i < curSize; i++) {
            pair<int, int> curCell = bfs.front();
            bfs.pop();
            if (arr[curCell.first][curCell.second] <= smallestValue) {
                smallestValue = arr[curCell.first][curCell.second];
                while (!smallestCells.empty() && arr[(smallestCells[smallestCells.size()-1]).first][(smallestCells[smallestCells.size()-1]).second] > smallestValue) {
                    smallestCells.pop_back();
                }
                smallestCells.push_back(curCell);
            }
        }
        cout << alphabet[smallestValue];
        for (int i = 0; i < smallestCells.size(); i++) {
            pair<int, int> curCell = smallestCells[i];
            if (curCell.first != n-1 && !dp[curCell.first+1][curCell.second]) {
                dp[curCell.first+1][curCell.second] = true;
                bfs.push(make_pair(curCell.first+1, curCell.second));
            }
            if (curCell.second != n-1 && !dp[curCell.first][curCell.second+1]) {
                dp[curCell.first][curCell.second+1] = true;
                bfs.push(make_pair(curCell.first, curCell.second+1));
            }
        }
    }


    // int _x = 0;
    // int _y = 0;
    // cout << arr[0][0];
    // while (_x != n-1 && _y != n-1) {
    //     if (dp[_y][_x][0] == 0) {
    //         _y++;
    //     }else {
    //         _x++;
    //     }
    //     cout << alphabet[arr[_x][_y]];
    // }

    return 0;
}
