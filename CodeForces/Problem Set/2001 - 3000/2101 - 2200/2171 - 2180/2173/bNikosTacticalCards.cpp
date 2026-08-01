
#include <iostream>
using namespace std;

const long int MAX_N = 100000;
int T;
long int n, arrA[MAX_N], arrB[MAX_N];
long long int dp[MAX_N][2];

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        for (long int i = 0; i < n; i++) {
            cin >> arrA[i];
        }
        for (long int i = 0; i < n; i++) {
            cin >> arrB[i];
        }

        dp[0][0] = max(-arrA[0], arrB[0]);
        dp[0][1] = min(-arrA[0], arrB[0]);
        // cout << dp[0][0] << "|" << dp[0][1] << "\n";
        for (long int i = 1; i < n; i++) {
            long long int aChoiceMax = dp[i-1][0] - arrA[i];
            long long int bChoiceMax = arrB[i] - dp[i-1][1];
            long long int aChoiceMin = dp[i-1][1] - arrA[i];
            long long int bChoiceMin = arrB[i] - dp[i-1][0];
            dp[i][0] = max(aChoiceMax, bChoiceMax);
            dp[i][1] = min(aChoiceMin, bChoiceMin);
            // cout << dp[i][0] << "|" << dp[i][1] << "\n";
        }

        cout << dp[n-1][0] << "\n";
    }
}