#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, arr[300], rangeDP[300][300];

void initializeDP() {
    for (int i = 0; i < n; i++) {
        rangeDP[i][i] = 1;
    }
    for (int j = 1; j < n; j++) {
        for (int x = 0; x < n-j; x++) {
            int y = x+j;
            int leftBound = rangeDP[x+1][y] + ((arr[x] == arr[x+1] || arr[x] == arr[y]) ? 0 : 1);
            int rightBound = rangeDP[x][y-1] + ((arr[y] == arr[x] || arr[y] == arr[y-1]) ? 0 : 1);
            rangeDP[x][y] = min(leftBound, rightBound);
            //cout << rangeDP[x][y];
        }
    }
}

int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    initializeDP();
    cout << rangeDP[0][n-1];
    
    return 0;
}