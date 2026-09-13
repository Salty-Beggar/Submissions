
#include <iostream>
#include <cstdio>
using namespace std;

const long long MAX_NK = 800;
long long n, k, arr[MAX_NK], max_dp[MAX_NK+1][MAX_NK+1], dp[MAX_NK+1][MAX_NK];

int main() {
    // freopen("snakes.in", "r", stdin);
    // freopen("snakes.out", "w", stdout);
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (long long i = 0; i <= n; i++) {
        long long curr_max = 0;
        long long curr_sum = 0;
        for (long long j = i; j <= n; j++) {
            curr_max = max(curr_max, arr[j]);
            curr_sum += arr[j];
            max_dp[i][j] = curr_max*(j-i+1) - curr_sum;
        }
    }
    for (long long i = 0; i <= k; i++) {
        long long break_j = 0;
        for (long long j = 0; j < n; j++) {
            if (i == 0) {
                dp[0][j] = max_dp[0][j];
                cout << dp[i][j] << " ";
                continue;
            }
            while (
                break_j < j 
                && dp[i-1][break_j+1]+max_dp[break_j+2][j] 
                    <= dp[i-1][break_j]+max_dp[break_j+1][j]
            ) {
                break_j++;
            }
            if (
                dp[i-1][j-1]+max_dp[j][j] 
                <= dp[i-1][break_j]+max_dp[break_j+1][j]
            ) {
                break_j = j-1;
            }
            dp[i][j] = dp[i-1][break_j]+max_dp[break_j+1][j];
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp[k][n-1];
}
