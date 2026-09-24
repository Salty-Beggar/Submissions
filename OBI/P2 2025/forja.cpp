
#include <iostream>
using namespace std;

const long long MAX_NK = 100000;
long long n, k, k_sub, arr[MAX_NK], dp[MAX_NK][2], or_sums[MAX_NK];
// 0 - Current or. 1 - Other sum.

int main() {
    cin >> n >> k;
    k_sub = k-1;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        or_sums[i] = arr[i];
        if (i != 0 && (i+1)%k_sub != 0) {
            or_sums[i] |= or_sums[i-1];
        }
    }
    for (long long i = k_sub; i >= 0; i--) {
        for (long long j = i; j < n; j += k_sub) {
            if (i == k_sub) {
                dp[j][0] = or_sums[j];
                continue;
            }
        }
    }

    cout << dp[n-1][0]+dp[n-1][1];
}
