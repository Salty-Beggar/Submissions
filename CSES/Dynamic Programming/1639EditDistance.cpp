
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_NM = 5000;
int n, m, dp[MAX_NM+1][MAX_NM+1]; // The answer for the question, from the beginning of targ to i, and of src to j, exclusive.
string wordTarg, wordSrc;

int main() {
    cin >> wordTarg >> wordSrc;
    n = wordTarg.size();
    m = wordSrc.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) continue;
            dp[i][j] = 10000;
            
            if (j != 0) {
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            }
            if (i != 0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            }
            
            
            if (i != 0 && j != 0) {
                if (wordTarg[n-i] == wordSrc[m-j]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }else {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    cout << dp[n][m];
    return 0;
}
