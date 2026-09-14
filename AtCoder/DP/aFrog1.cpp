
#include <iostream>
using namespace std;

const long long MAX_N = 100000;
long long n, stones[MAX_N], dp[MAX_N];

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> stones[i];
        if (i == 0) continue;
        if (i == 1) {
            dp[i] = abs(stones[1]-stones[0]);
            continue;
        }
        dp[i] = min(
            abs(stones[i] - stones[i-1])+dp[i-1],
            abs(stones[i] - stones[i-2])+dp[i-2]
        );
    }
    cout << dp[n-1];
}