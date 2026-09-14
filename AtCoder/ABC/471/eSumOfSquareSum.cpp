
#include <cmath>
#include <iostream>
using namespace std;

const long long MAX_N = 200000, MODULO = 998244353;
long long n, arr[MAX_N], sum, factorial[MAX_N+1];

int main() {
    cin >> n;
    factorial[1] = 1;
    for (long long i = 0; i < n; i++) {
        if (i+1 != 1) {
            factorial[i+1] = (factorial[i]*(i+1)) % MODULO;
        }
        long long a;
        cin >> a;
        arr[i] = a;
        sum += a;
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        long long m = n-i;
        // ans += 
    }
    return 0;
}