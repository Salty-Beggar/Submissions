// Y5x7XXd

#include <iostream>
// #include <string>
using namespace std;

const long long MAX_N = 200000;
long long n, prefix_sum_count[MAX_N*2+1];
string word;

int main() {
    cin >> n >> word;
    long long curr_sum = 0;
    long long i = 1;
    prefix_sum_count[MAX_N] = 1;
    for (auto letter : word) {
        curr_sum += letter == '1' ? 1 : -1;
        prefix_sum_count[curr_sum+MAX_N]++;
        i++;
    }
    long long ans = 0;
    for (long long i = 0; i <= MAX_N*2; i++) {
        long long curr_ps_count = prefix_sum_count[i];
        // cout << curr_ps_count << " ";
        ans += curr_ps_count*(curr_ps_count-1)/2;
    }
    cout << ans;
}
