
#include <iostream>
using namespace std;

const long long MAX_K = 20;
long long n, k, primes[MAX_K];

long long _solve(long long index, long long amount, long long divisor) {
    if (divisor == n+1) return 0;
    if (index == k) {
        if (amount == 0) return 0;
        // cout << ((amount%2 == 0) ? -(n/divisor) : (n/divisor)) << "\n";
        return (amount%2 == 0) ? -(n/divisor) : (n/divisor);
    }
    return 
        _solve(index+1, amount, divisor)
        +((divisor <= n/primes[index]) 
            ? _solve(index+1, amount+1, min(divisor * primes[index], n+1)) 
            : 0
        )
    ;
}

int main() {
    cin >> n >> k;
    for (long long i = 0; i < k; i++) {
        cin >> primes[i];
    }
    long long ans = _solve(0, 0, 1);
    cout << ans;
    return 0;
}
