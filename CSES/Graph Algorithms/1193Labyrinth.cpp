
// This code works for what the problem asks. It's just that, apparently, CSES does not have multiple solution support. It seems like you'd have to implement Djikstra for CSES to count the problem as solved, due to the test case's nature.

#include <iostream>
#include <stack>
using namespace std;

struct vector2 {
    int x;
    int y;
    vector2& operator =(const int a[2]) {
        x = a[0]; y = a[1];
    }
};

const int MAX_NM = 1000;
int n, m;
vector2 start;
short labyrinth[MAX_NM][MAX_NM];
// 0 - Empty/Unexplored | 1 - Wall/Explored | 2 - Finish line
stack<tuple<char, vector2, short>> moveStack;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char curChar;
            cin >> curChar;
            if (curChar == 'A') {
                moveStack.push({'S', {i, j}, 0});
                labyrinth[i][j] = 3;
            }else {
                labyrinth[i][j] = (curChar == '.') ? 0 : (curChar == '#') ? 1 : 2;
            }
        }
    }

    bool hasReached = false;
    while (!moveStack.empty()) {
        tuple<char, vector2, short> &curItem = moveStack.top();
        short curDir = get<2>(curItem);
        int _x = get<1>(curItem).x;
        int _y = get<1>(curItem).y;
        if (labyrinth[_x][_y] == 5) {
            hasReached = true;
            break;
        }
        if (labyrinth[_x][_y] == 1 || curDir == 4) {
            moveStack.pop();
            continue;
        }
        //cout << _x << " " << _y << " " << labyrinth[_x][_y] << "\n";
        switch (curDir) {
            case 0:
                if (_y+1 < m && labyrinth[_x][_y+1] != 3 && labyrinth[_x][_y+1] != 1) {
                    moveStack.push({'R', {_x, _y+1}, 0});
                    labyrinth[_x][_y+1] += 3;
                }
                break;
            case 1:
                if (_x+1 < n && labyrinth[_x+1][_y] != 3 && labyrinth[_x+1][_y] != 1) {
                    moveStack.push({'D', {_x+1, _y}, 0});
                    labyrinth[_x+1][_y] += 3;
                }
                break;
            case 2:
                if (_y-1 >= 0 && labyrinth[_x][_y-1] != 3 && labyrinth[_x][_y-1] != 1) {
                    moveStack.push({'L', {_x, _y-1}, 0});
                    labyrinth[_x][_y-1] += 3;
                }
                break;
            case 3:
                if (_x-1 >= 0 && labyrinth[_x-1][_y] != 3 && labyrinth[_x-1][_y] != 1) {
                    moveStack.push({'U', {_x-1, _y}, 0});
                    labyrinth[_x-1][_y] += 3;
                }
                break;
        }
        get<2>(curItem)++;
    }

    if (!hasReached) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n" << (moveStack.size()-1) << "\n";
    stack<char> pathStack;
    while (moveStack.size() != 1) {
        tuple<char, vector2, short> curItem = moveStack.top();
        moveStack.pop();
        pathStack.push(get<0>(curItem));
    }
    while (!pathStack.empty()) {
        cout << pathStack.top();
        pathStack.pop();
    }

    return 0;
}