
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Actually solving this problem seems to require constant time optimization. So, do that another day.
const int MAX_NM = 1000;
short int _map[MAX_NM][MAX_NM];
int n, m;

struct stackItem {
    int x, y;
    string path;
    stackItem(int _y, int _x) : x(_x), y(_y) {
        
    }
    stackItem(int _y, int _x, string _path) {
        x = _x;
        y = _y;
        path = _path;
    }
    short int array() {
        return _map[y][x];
    }
    bool outOfBounds() {
        return x == 0 || y == 0 || x == m-1 || y == n-1;
    }
};

queue<stackItem> playerBFS;
queue<stackItem> monsterBFS;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char curChar;
            cin >> curChar;
            switch (curChar) {
                case '.':
                    _map[i][j] = 0;
                    break;
                case '#':
                    _map[i][j] = 1;
                    break;
                case 'A':
                    playerBFS.push(stackItem(i, j));
                    break;
                case 'M':
                    monsterBFS.push(stackItem(i, j));
                    break;
            }
        }
    }

    while (!playerBFS.empty()) {
        int curSize = monsterBFS.size();
        for (int i = 0; i < curSize; i++) {
            stackItem curItem = monsterBFS.front();
            monsterBFS.pop();
            if (curItem.array() == 3) continue;
            int _x = curItem.x;
            int _y = curItem.y;
            _map[_y][_x] = 3;
            if (_y-1 >= 0 && (_map[_y-1][_x] == 0 || _map[_y-1][_x] == 2)) monsterBFS.push(stackItem(_y-1, _x));
            if (_y+1 < n && (_map[_y+1][_x] == 0 || _map[_y+1][_x] == 2)) monsterBFS.push(stackItem(_y+1, _x));
            if (_x-1 >= 0 && (_map[_y][_x-1] == 0 || _map[_y][_x-1] == 2)) monsterBFS.push(stackItem(_y, _x-1));
            if (_x+1 < m && (_map[_y][_x+1] == 0 || _map[_y][_x+1] == 2)) monsterBFS.push(stackItem(_y, _x+1));
        }
        curSize = playerBFS.size();
        for (int i = 0; i < curSize; i++) {
            stackItem curItem = playerBFS.front();
            playerBFS.pop();
            if (curItem.array() == 3 || curItem.array() == 2) continue;
            int _x = curItem.x;
            int _y = curItem.y;
            if (curItem.outOfBounds()) {
                cout 
                    << "YES" << "\n"
                    << curItem.path.size() << "\n"
                    << curItem.path << "\n";
                return 0;
            }
            _map[_y][_x] = 2;
            if (_map[_y+1][_x] == 0) playerBFS.push(stackItem(_y+1, _x, curItem.path+'D'));
            if (_map[_y-1][_x] == 0) playerBFS.push(stackItem(_y-1, _x, curItem.path+'U'));
            if (_map[_y][_x+1] == 0) playerBFS.push(stackItem(_y, _x+1, curItem.path+'R'));
            if (_map[_y][_x-1] == 0) playerBFS.push(stackItem(_y, _x-1, curItem.path+'L'));
        }
    }
    
    cout << "NO";

    return 0;
}