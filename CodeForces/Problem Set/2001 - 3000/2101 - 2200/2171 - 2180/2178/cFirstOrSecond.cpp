
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n;

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        long int children[MAX_N];
        long long int dp[MAX_N-1][2]; /*
            0 - Best
            1 - Removing all
        */
        for (long int i = 0; i < n; i++) {
            cin >> children[i];
            if (i == n-1) continue;
        }
    
        if (n == 2) {
            cout << max(children[0], -children[1]) << "\n";
            continue;
        }
        dp[n-2][0] = max(-children[n-1], max(children[n-2], -children[n-2]));
        dp[n-2][1] = -children[n-1];
        for (long int i = n-3; i >= 0; i--) {
            dp[i][1] = dp[i+1][1]-children[i+1];
            long long int firstOption = max(dp[i+1][0]+children[i], dp[i+1][0]-children[i]);
            if (i == 0) firstOption = dp[i+1][0]+children[i];
            dp[i][0] = max(dp[i][1], firstOption);
        }
        cout << dp[0][0] << "\n";
    }
    return 0;
}
