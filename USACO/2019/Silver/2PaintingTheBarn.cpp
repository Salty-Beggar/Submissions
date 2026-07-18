
#include <iostream>
#include <cstdio>
using namespace std;

const long int MAX_XY = 1002;
long int n, k, diffMatrix[MAX_XY+1][MAX_XY+1], matrix[MAX_XY][MAX_XY];

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    cin >> n >> k;
    for (long int i = 0; i < n; i++) {
        long int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        diffMatrix[x1][y1]++;
        diffMatrix[x1][y2]--;
        diffMatrix[x2][y1]--;
        diffMatrix[x2][y2]++;
    }
    long int ans = 0;
    for (long int i = 0; i < MAX_XY; i++) {
        for (long int j = 0 ; j < MAX_XY; j++) {
            matrix[i][j] = diffMatrix[i][j];
            if (i != 0) matrix[i][j] += matrix[i-1][j];
            if (j != 0) matrix[i][j] += matrix[i][j-1];
            if (i != 0 && j != 0) matrix[i][j] -= matrix[i-1][j-1];
            ans += matrix[i][j] == k;
        }
    }
    cout << ans;
}