
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

const long long MAX_NQ = 100000;
long long n, q;
map<long long, long long> rps_map;
map<long long, long long> prefix_sum_map;

int main() {
    cin >> n >> q;
    for (long long i = 0; i < n; i++) {
        long long l, r, v;
        cin >> l >> r >> v;
        rps_map[l] += v;
        rps_map[r] -= v;
    }

    long long min_pos = -1;
    long long cur_value = 0;
    long long prev_value_add = 0;
    long long prev_pos = 0;
    for (const auto[key, value] : rps_map) {
        if (min_pos == -1) min_pos = key;
        cur_value += prev_value_add*(key-prev_pos);
        prefix_sum_map[key] = cur_value;
        prev_value_add += value;
        rps_map[key] = prev_value_add;
        // cout << key << " " << prev_value_add << " " << cur_value << "\n";
        prev_pos = key;
    }

    for (long long i = 0; i < q; i++) {
        long long l, r;
        cin >> l >> r;
        l = max(l, min_pos);
        r = max(r, min_pos);
        auto prefix_sum_l = prefix_sum_map.lower_bound(l);
        if (prefix_sum_l == prefix_sum_map.end()) {
            prefix_sum_l--;
        }
        auto prefix_sum_r = prefix_sum_map.lower_bound(r);
        if (prefix_sum_r == prefix_sum_map.end()) {
            prefix_sum_r--;
        }
        auto rps_l = rps_map.upper_bound(l);
        auto rps_r = rps_map.upper_bound(r);
        rps_l--;
        rps_r--;

        // if (prefix_sum_l->first > prefix_sum_r->first) {
        //     cout << (r-l)*rps_l->second;
        //     cout << "\n";
        //     continue;
        // }
        
        long long l_diff = prefix_sum_l->first - l;
        long long r_diff = prefix_sum_r->first - r;

        // cout << rps_l->first << " " << rps_r->first << "\n";

        cout << 
            (l_diff*(rps_l->second))
            -(r_diff*(rps_r->second))
            +(prefix_sum_r->second - prefix_sum_l->second);
        cout << "\n";
    }

    return 0;
}
