
#include <iostream>
using namespace std;

const long int MODULO = 1000000007;
int n;
bool map[1000][1000];
long int dp[1000][1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char curChar;
            cin >> curChar;
            dp[n-1-i][n-1-j] = (curChar == '.') ? 0 : -1;
        }
    }
    if (dp[0][0] == -1) {
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1) continue;

            if (i != 0 && dp[i-1][j] != -1) dp[i][j] += dp[i-1][j];
            if (dp[i][j] >= MODULO) dp[i][j] %= MODULO;

            if (j != 0 && dp[i][j-1] != -1) dp[i][j] += dp[i][j-1];
            if (dp[i][j] >= MODULO) dp[i][j] %= MODULO;
        }
    }

    cout << ((dp[n-1][n-1] == -1) ? 0 : dp[n-1][n-1]);
    return 0;
}