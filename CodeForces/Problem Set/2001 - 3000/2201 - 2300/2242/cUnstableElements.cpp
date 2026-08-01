
#include <set>
#include <iostream>
using namespace std;

const long long MAX_N = 300000;
long long t, n, k;
multiset<long long> sizes;

int main() {
    cin >> t;
    for (; t > 0; t--) {
        cin >> n >> k;
        long long prev_item = 0;
        long long streak = 0;
        long long distinct_amount = 0;
        long long value_amount = n;
        for (long long i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (prev_item != 0 && prev_item != x) { 
                sizes.insert(streak); 
                streak = 0;
                distinct_amount++;
            }
            prev_item = x;
            streak++;
        }
        sizes.insert(streak); 
        distinct_amount++;
        auto sizes_iter = sizes.begin();
        long long reachable_arr_amount = 0;
        long long prev_size = 0;
        while (sizes_iter != sizes.end()) {
            long long cur_size = *sizes_iter;
            long long next_value_decrease = (cur_size - prev_size)*distinct_amount;
            long long up_diff = k - value_amount, down_diff = value_amount - k;
            if (up_diff > 0 && up_diff % distinct_amount == 0) {
                reachable_arr_amount++;
            }
            if (down_diff >= 0 && down_diff < next_value_decrease && down_diff % distinct_amount == 0) {
                reachable_arr_amount++;
            }
            value_amount -= next_value_decrease;
            distinct_amount -= sizes.count(cur_size);
            sizes_iter = sizes.upper_bound(cur_size);
            prev_size = cur_size;
            sizes.erase(cur_size);
        }
        cout << reachable_arr_amount << "\n";
    }
    return 0;
}
