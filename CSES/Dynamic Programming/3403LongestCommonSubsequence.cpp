
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_NM = 1000;
int n, m;
long int dp[MAX_NM][MAX_NM][2], arr1[MAX_NM], arr2[MAX_NM]; /*
* 0 - Size | 1 - Direction (0 is right, 1 is diagonal, 2 is down)
*/

int main() {
    cin >> n >> m;
    if (n > m) { // arr2 must always be the one without more items.
        for (long int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (long int i = 0; i < m; i++) {
            cin >> arr2[i];
        }
    }else {
        for (long int i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        for (long int i = 0; i < m; i++) {
            cin >> arr1[i];
        }
        int _n = n;
        n = m;
        m = n;
    }

    // dp[n-1][m-1] = (arr1[n-1] == arr2[m-1]) ? 1 : 0;
    // int _ans = 0;
    // int _ansL = 0;
    // int _ansR = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            // if (i == 0 && j == 0) continue;
            long int curSize = 0;
            if (i+1 < n) {
                curSize = dp[i+1][j][0];
                dp[i][j][0] = curSize;
                dp[i][j][1] = 0;
            }
            if (j+1 < m && dp[i][j+1][0] > curSize) {
                curSize = dp[i][j+1][0];
                dp[i][j][0] = curSize;
                dp[i][j][1] = 2;
            }
            if (arr1[i] == arr2[j]) {
                long int diag = 1+((i+1 < n && j+1 < m) ? dp[i+1][j+1][0] : 0);
                if (diag > curSize) {
                    dp[i][j][0] = diag;
                    dp[i][j][1] = 1;
                }
            }
        }
    }

    cout << dp[0][0][0] << "\n";
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (dp[i][j][1] == 1) {
            cout << arr1[i] << " ";
            i++; j++;
        }else if (dp[i][j][1] == 0) i++;
        else if (dp[i][j][1] == 2) j++;
    }

    return 0;
}
