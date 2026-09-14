
#include <iostream>
using namespace std;

const long long MAX_N = 500000;
long long n, prefix_sum_count[1 << 10];
string s;

int main() {
    cin >> s;
    long long curr_prefix = 0, index = 1;
    prefix_sum_count[0] = 1;
    for (char i : s) {
        long long curr_value = i-'0';
        long long curr_bit = 1 << curr_value;
        curr_prefix ^= curr_bit;
        prefix_sum_count[curr_prefix]++;
        index++;
    }

    long long ans = 0;
    for (long long i = 0; i < (1<<10); i++) {
        ans += prefix_sum_count[i] * (prefix_sum_count[i]-1) / 2;
    }
    cout << ans;
    return 0;
}
