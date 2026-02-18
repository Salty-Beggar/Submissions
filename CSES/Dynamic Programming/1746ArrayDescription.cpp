
#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX_N = 100000, MODULO = 1000000007;
const int MAX_M = 100;
long int n;
int m;
long int dp[MAX_N][MAX_M+1];
int arr[MAX_N];

void modulate(long int &value) {
    if (value >= MODULO) value %= MODULO;
}

int main() {
    cin >> n >> m;
    for (long int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long int sum = 0;
    for (long int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            long int value = arr[i];
            if (i != 0) {
                dp[i][value] += dp[i-1][value];
                if (value+1 <= m) dp[i][value] += dp[i-1][value+1];
                if (value-1 != 0) dp[i][value] += dp[i-1][value-1];
                modulate(dp[i][value]);
            }else {
                dp[i][value] = 1;
            }
            continue;
        }
        for (int j = 1; j <= m; j++) {
            if (i == 0) {
                dp[i][j] = 1;
            }else {
                dp[i][j] += dp[i-1][j];
                if (j+1 <= m) dp[i][j] += dp[i-1][j+1];
                if (j-1 != 0) dp[i][j] += dp[i-1][j-1];
                modulate(dp[i][j]);
            }

            if (i == n-1) {
                sum += dp[i][j];
                modulate(sum);
            }
        }
    }
    cout << ((arr[n-1] == 0) ? sum : dp[n-1][arr[n-1]]);
}