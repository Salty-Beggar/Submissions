
#include <iostream>
#include <cmath>
using namespace std;

const long long MAX_SIZE = 18;

long long n, m, dp[MAX_SIZE][MAX_SIZE][2][2]
// RIGHT_NOW: Continue doing the DP thing;
string lower_str, upper_str;

long long solve(long long index, long long digit, long long count, bool leading, bool bound, long long targ) {

}

int main() {
    cin >> lower_str >> upper_str;
    n = upper_str.size();
    m = lower_str.size();

    long long ans = 0;
    for (long long k = 0; k <= 9; k++) {
        for (long long i = 0; i < MAX_SIZE; i++) {
            long long upper_digit = upper_str[i]-'0';
            long long lower_digit = lower_str[i]-'0';
            for (long long j = 1; j <= MAX_SIZE; j++) {

            }
        }
    }

    return 0;
}
