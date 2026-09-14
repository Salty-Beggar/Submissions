
#include <iostream>
using namespace std;

const long long MAX_N = 200000, MAX_BIT = 28;
long long n, arr[MAX_N], bit_count[MAX_BIT], curr_sum;

int main() {
    cin >> n;
    long long curr_xor = 0;
    for (long long i = 0; i < n; i++) {
        long long curr_value;
        cin >> curr_value;
        arr[i] = curr_value;
        curr_xor ^= curr_value;
        if (i != 0) {
            for (long long j = 0; j < MAX_BIT; j++) {
                long long curr_bit = 1ll<<j;
                if ((curr_xor & curr_bit) != 0) bit_count[j]++;
            }
            curr_sum += curr_xor;
        }
        // cout << curr_xor << " ";
    }
    // cout << "\n";
    long long curr_total = curr_sum;
    long long curr_number_amount = n-1;
    for (long long i = 0; i < n-2; i++) {
        long long removed_pair = arr[i]^arr[i+1];
        curr_sum -= removed_pair;
        for (long long j = 0; j < MAX_BIT; j++) {
            long long curr_bit = 1ll<<j;
            if ((removed_pair & curr_bit) != 0) bit_count[j]--;
        }
        curr_number_amount--;
        long long curr_value = arr[i];
        for (long long j = 0; j < MAX_BIT; j++) {
            long long curr_bit = 1ll<<j;
            if ((curr_value & curr_bit) != 0) {
                long long prev_bit_count = bit_count[j];
                bit_count[j] = curr_number_amount - bit_count[j];
                curr_sum += (bit_count[j] - prev_bit_count)*curr_bit;
                // cout << curr_sum << " " << bit_count[j] << " " << curr_number_amount << "|";
            }
        }
        curr_total += curr_sum;
    }
    cout << curr_total;
    return 0;
}