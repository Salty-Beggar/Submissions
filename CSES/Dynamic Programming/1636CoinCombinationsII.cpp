
#include <iostream>
#include <algorithm>
using namespace std;

const long int MODULO = 1000000007;
const int MAX_N = 100;
const long int MAX_X = 1000000;

int n;
long int dp[MAX_X+1];
long int x, coins[MAX_N];

int main() {
    cin >> n >> x;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    //sort(coins, coins+n);
    for (int i = 0; i < n; i++) {
        long int c = coins[i];
        //cout << c << " ";
        for (int j = 1; j <= x; j++) {
            if (j-c >= 0) dp[j] += dp[j-c];
            if (dp[j] >= MODULO) dp[j] %= MODULO;
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            cout << dp[j][i] << " ";
        }
        cout << "\n";
    }*/
    cout << dp[x];
    return 0;
}