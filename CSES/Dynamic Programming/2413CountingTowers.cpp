
#include <iostream>
using namespace std;

const long int MAX_N = 1000000, MODULO = 1000000007;
long long int n, dp[MAX_N][2]; // 0 - Uno 1 - Bi

int main() {
    long int t;
    cin >> t;
    for (long k = 0; k < t; k++) {
        cin >> n;
        dp[0][0] = 1;
        dp[0][1] = 1;
        for (long int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0]*2 + dp[i-1][1];
            dp[i][0] %= MODULO;
            dp[i][1] = dp[i-1][0] + dp[i-1][1]*4;
            dp[i][1] %= MODULO;
        }
        cout << ((dp[n-1][0]+dp[n-1][1])%MODULO) << "\n";
    }
    return 0;
}