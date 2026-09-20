
#include <iostream>
using namespace std;

const long long MAX_N = 300;
long long n, arr[MAX_N], dp[MAX_N][MAX_N];

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            dp[i][j] = MAX_N;
            if (j < i) dp[i][j] = 0;
            else if (j == i) dp[i][j] = 1;
        }
    }
    long long curr_streak = -1;
    long long streak_index = -1;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i][i] = 1;
        // if (arr[i] != curr_streak) {
        //     if (streak_index != -1) {
        //         dp[streak_index][i-1] = 1;
        //     }
        //     curr_streak = arr[i];
        //     streak_index = i;
        // }
    }
    // dp[streak_index][n-1] = 1;
    for (long long j = 0; j < n; j++) {
        for (long long i = 0; i < n-j; i++) {
            if (j != 0 && arr[i] == arr[i+j]) {
                if (j != 1 && (arr[i+1] == arr[i] || arr[i+j-1] == arr[i]))
                    dp[i][i+j] = min(dp[i][i+j], dp[i+1][i+j-1]);
                else 
                    dp[i][i+j] = min(dp[i][i+j], dp[i+1][i+j-1]+1);
            }
            for (long long k = i; k < i+j; k++) {
                dp[i][i+j] = min(
                    dp[i][i+j], 
                    dp[i][k]+dp[k+1][i+j]
                );
            }
        }
    }

    // for (long long i = 0; i < n; i++) {
    //     for (long long j = 0; j < n; j++) {
    //         cout << ((char) ((dp[i][j] == MAX_N) ? '.' : (dp[i][j]+'0'))) << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[0][n-1];
}
