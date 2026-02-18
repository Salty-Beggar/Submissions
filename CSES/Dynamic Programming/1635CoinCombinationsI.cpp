
#include <algorithm>
#include <iostream>
using namespace std;

const long long int MODULO = 1000000007;
const long int MAX_X = 1000000;
int n;
long int x, coins[100];
long long int dp[MAX_X+1];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        long int coin;
        cin >> coin;
        coins[i] = coin;
        dp[coin] = 1;
    }
    for (long int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            long int curCoin = coins[j];
            if (i - curCoin > 0) {
                dp[i] += dp[i - curCoin];
                if (dp[i] >= MODULO) dp[i] %= MODULO;
            }
        }
    }
    cout << dp[x];
    return 0;
}