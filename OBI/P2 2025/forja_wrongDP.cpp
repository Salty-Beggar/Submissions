
// Você deve calcular as somas não somente nas últimas casas, mas em todo o restante também.

#include <iostream>
using namespace std;

const long long MAX_N = 100000;
long long n, k, arr[MAX_N], dp[MAX_N], sums[MAX_N];

int main() {
    cin >> n >> k;
    if (k == 2 || n%(k-1) == 1) {
        long long total_or = 0;
        for (long long i = 0; i < n; i++) {
            long long a;
            cin >> a;
            total_or |= a;
        }
        cout << total_or;
        return 0;
    }

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long curr_or = 0;
    for (long long i = 0; i < n; i++) {
        if ((n-i-2) % (k-1) == 1) {
            curr_or = 0;
        }
        curr_or |= arr[i];
        sums[i] = curr_or;
    }
    // for (long long i = n-1; i >= n%(k-1)-1; i--) {
        
    // }

    long long left_or = 0;
    for (long long i = (n-2)%(k-1); i >= 0; i--) {
        left_or |= arr[i];
        long long mid_or = 0;
        for (long long j = (n-1)%(k-1); j < n; j += k-1) {

        }
    }
    
    return 0;
}
