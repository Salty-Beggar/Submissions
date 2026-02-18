
#include <algorithm>
#include <iostream>
using namespace std;

const long int MODULE = 1000000007;
const long int MAX_N = 1000000;
long int n;
long long int dp[MAX_N];

int main() {
    cin >> n;
    dp[0] = 1;
    for (long int i = 1; i < n; i++) {
        int value = i+1;
        long long int possibilities = 0;
        if (value >= 1 && value <= 6) possibilities = 1;
        for (long int j = 1; j <= min(value-1, 6); j++) {
            possibilities += dp[i-j];
            if (possibilities >= MODULE) possibilities %= MODULE;
        }
        dp[i] = possibilities;
    }
    cout << dp[n-1];
    return 0;
}