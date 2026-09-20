
#include <iostream>
#include <cmath>
using namespace std;

const long long MAX_SIZE = 18;

long long n, m, dp[MAX_SIZE][2][MAX_SIZE][2];
// Position, tight, count, leading zeroes. 
string lower_str, upper_str;

long long solve(string targ) {
    while (targ.size() < MAX_SIZE) {
        targ = "0"+targ;
    }
    for (long long k = 0; k <= 9; k++) {
        for (long long i = MAX_SIZE-1; i >= 0; i--) {
            
        }
    }
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
            for (long long j = 0; j < MAX_SIZE; j++) {
                
            }
        }
    }

    return 0;
}
