
#include <iostream>
using namespace std;

const int MAX_NM = 500;
int n, m;
long int dp[MAX_NM][MAX_NM];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                dp[i][j] = 0l;
                continue;
            }
            dp[i][j] = 10000000;
            for (int k = 0; k < i; k++) { // Horizontal cutting
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-1-k][j]+1);
            }
            for (int k = 0; k < j; k++) { // Vertical cutting
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-1-k]+1);
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    cout << dp[n-1][m-1];
    return 0;
}
