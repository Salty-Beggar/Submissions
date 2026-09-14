
#include <iostream>
#include <string>
using namespace std;

long long n = 0, dp[100000000];
string digits;

void print_bits(long long bitmask) {
    for (long long i = 15; i >= 0; i--) {
        cout << (((1<<i)&bitmask) != 0);
    } // RIGHT_NOW: Solve this problem.
}

int main() {
    long long bitmask = 0;
    cin >> digits;
    n = digits.size();
    long long ans = 0;
    long long curr_prefix = 0;
    for (const long long digit : digits) {
        long long curr_bit = 1<<digit;
        bitmask ^= curr_bit;
        print_bits(bitmask);
        cout << " ";
        ans += dp[bitmask];
        dp[bitmask]++;
    }
    // for (long long i = 0; i < (1<<15); i++) {
    //     ans += dp[i]*(dp[i]-1)/2;
    // }
    cout << ans;
    return 0;
}
