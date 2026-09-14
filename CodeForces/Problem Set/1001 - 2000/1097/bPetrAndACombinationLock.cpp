
#include <iostream>
using namespace std;

const long long MAX_N = 15, SPIN = 360;
long long n, spins[MAX_N], spin_sum, dp[1ll<<MAX_N];

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> spins[i];
        spin_sum += spins[i];
        dp[1ll<<i] = spins[i];
    }
    for (long long i = 0; i < n; i++) {
        long long first_on_bit = 1ll<<i;
        for (long long j = first_on_bit; j < (first_on_bit<<1); j++) {
            dp[j] = dp[j^first_on_bit]+dp[first_on_bit];
            if ((dp[j]*2 - spin_sum) % SPIN == 0) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
