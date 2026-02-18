
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_X = 1000000;
int n;
long int x, dp[MAX_X+1];
long int coins[100];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        long int coin;
        cin >> coin;
        dp[coin] = 1;
        coins[i] = coin;
    }
    for (long int i = 1; i <= x; i++) {
        if (dp[i] != 0) continue;
        for (int j = 0; j < n; j++) {
            long int curCoin = coins[j];
            if (i-curCoin >= 0 && dp[i-curCoin] != 0) {
                if (dp[i] == 0) dp[i] = dp[i-curCoin]+1;
                else dp[i] = min(dp[i], dp[i-curCoin]+1);
            }
        }
    }
    cout << ((dp[x] == 0) ? -1 : dp[x]);
    return 0;
}
