
#include <iostream>
#include <queue>
using namespace std;

const int MAX_NM = 1000;
bool traversal[MAX_NM][MAX_NM];
queue<pair<int, int>> dfs;
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char curChar;
            cin >> curChar;
            traversal[i][j] = (curChar == '#') ? true : false;
        }
    }

    int amount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!traversal[i][j]) {
                amount++;
                dfs.push({i, j});
                while (!dfs.empty()) {                    
                    pair<int, int> cell = dfs.front();
                    dfs.pop();
                    int _i = cell.first;
                    int _j = cell.second;
                    if (traversal[_i][_j]) continue;
                    traversal[_i][_j] = true;
                    if (_i-1 >= 0) dfs.push({_i-1, _j});
                    if (_j-1 >= 0) dfs.push({_i, _j-1});
                    if (_i+1 < n) dfs.push({_i+1, _j});
                    if (_j+1 < m) dfs.push({_i, _j+1});
                }
            }
        }
    }

    cout << amount;
    
    return 0;
}