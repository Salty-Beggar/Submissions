
#include <iostream>
#include <set>
using namespace std;

const long long MAX_N = 300000;
long long t, n, k;
multiset<long long> count_by_value, count_by_size;

int main() {
    cin >> t;
    for (; t > 0; t--) {
        // count_by_value.clear();
        // count_by_size.clear();
        cin >> n >> k;
        for (long long i = 0; i < n; i++) {
            long long a;
            cin >> a;
            count_by_value.insert(a);
        }
        long long cur_size_count = 0;
        long long cur_value;
        for (auto i = count_by_value.begin(); i != count_by_value.end(); i = count_by_value.upper_bound(cur_value)) {
            cur_value = *i;
            cur_size_count++;
            count_by_size.insert(count_by_value.count(cur_value));
            count_by_value.erase(cur_value);
        }
        long long cur_size = n;
        long long reachable_arr_amount = 0;
        long long prev_value = 0;
        for (auto i = count_by_size.begin(); i != count_by_size.end(); i = count_by_size.upper_bound(cur_value)) {
            cur_value = *i;
            long long size_diff_up = k - cur_size;
            long long size_diff_down = cur_size - k;
            // cout << size_diff << " " << cur_size_count << "\n";
            if (size_diff_up > 0 && size_diff_up % cur_size_count == 0) {
                reachable_arr_amount++;
            }
            else if (size_diff_down >= 0 && size_diff_down != cur_size_count*(cur_value - prev_value) && size_diff_down % cur_size_count == 0) {
                reachable_arr_amount++;
            }
            cur_size -= cur_size_count*(cur_value - prev_value);
            cur_size_count -= count_by_size.count(cur_value);
            count_by_size.erase(cur_value);
            prev_value = cur_value;
        }
        cout << reachable_arr_amount << "\n";
    }
}