
#include <set>
#include <iostream>
using namespace std;

const long long MAX_K = 1000000000, MAX_A = 1000000000;
long long n, k;
multiset<long long> values;

int main() {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        long long value;
        cin >> value;
        values.insert(value);
    }

    for (long long i = 0; i < n/2; i++) {
        values.erase(values.begin());
    }

    // long long cur_value = *values.begin();
    long long cur_median = *values.begin();
    long long cur_count = 0;
    while (k > 0) {
        cur_count += values.count(cur_median);
        auto next_value_iterator = values.upper_bound(cur_median);
        if (next_value_iterator == values.end()) {
            cout << cur_median + k/cur_count;
            return 0;
        }
        long long next_value = *next_value_iterator;
        if (k <= (next_value - cur_median) * cur_count) {
            // cout << k << "\n";
            cout << cur_median + k/cur_count;
            return 0;
        }else {
            k -= (next_value - cur_median) * cur_count;
            cur_median = next_value;
        }
    }
    cout << cur_median;
    return 0;
}