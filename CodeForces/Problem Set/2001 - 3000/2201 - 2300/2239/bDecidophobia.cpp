
#include <iostream>
using namespace std;

const long long MAX_N = 200000;
long long t, n, d, arr[MAX_N], range_prefix_sum[MAX_N+1];

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> d;
        for (long long i = 0; i < n; i++) {
            range_prefix_sum[i] = 0;
        }
        for (long long i = 0; i < n; i++) {
            long long weight;
            cin >> weight;
            arr[i] = weight;
            range_prefix_sum[max(0ll, i-d)] += -weight;
            range_prefix_sum[min(n, i+d+1)] += weight;
            if (i-d < 0) {
                range_prefix_sum[n+(i-d)] += -weight;
            }else if (i+d+1 > n) {
                range_prefix_sum[0] += -weight;
                range_prefix_sum[i+d+1 - n] += weight;
            }
        }
        long long max_happiness = 0;
        long long cur_happiness_loss = 0;
        for (long long i = 0; i < n; i++) {
            long long cur_weight = arr[i];
            cur_happiness_loss += range_prefix_sum[i];
            max_happiness += max(0ll, cur_happiness_loss+cur_weight*(2*d+1));
        }
        cout << max_happiness << "\n";
    }
}