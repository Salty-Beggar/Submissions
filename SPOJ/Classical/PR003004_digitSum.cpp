
#include <iostream>
#include <string>
using namespace std;

const long long MAX_SIZE = 16, MAX_SUM = 135, MAX_N = 1000000000000000;
long long t, dp[MAX_SIZE][2][MAX_SUM+1];
string a, b;

long long _solve(long long index, long long tight, long long sum, string targ) {
    if (index == MAX_SIZE) return 1;
    if (dp[index][tight][sum] != -1) 
        return dp[index][tight][sum];
    long long curr_digit = targ[index]-'0';
    dp[index][tight][sum] = 0;
    for (long long k = 0; k <= 9; k++) {
        if (tight && k > curr_digit) continue;
        dp[index][tight][sum] += (k+1)*_solve(
            index+1, 
            tight && k == curr_digit,
            sum+k,
            targ
        );
    }
    return dp[index][tight][sum];
}

long long solve(string targ) {
    for (long long i = 0; i < MAX_SIZE; i++) {
        for (long long j = 0; j < 2; j++) {
            for (long long z = 0; z <= MAX_SUM; z++) {
                dp[i][j][z] = -1;
            }
        }
    }
    return _solve(0, true, 0, targ);
}

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> a >> b;
        if (b == "0") {
            cout << "0\n";
            continue;
        }else if (a == "0") {
            while (b.size() < MAX_SIZE) b = "0"+b;
            cout << solve(b) << "\n";
            continue;
        }
        a = to_string(stoi(a)-1);
        while (a.size() < MAX_SIZE) a = "0"+a;
        while (b.size() < MAX_SIZE) b = "0"+b;
        // cout << a << "\n" << b << "\n\n";
        cout << solve(b) << " " << solve(a) << "\n";
    }
    return 0;
}