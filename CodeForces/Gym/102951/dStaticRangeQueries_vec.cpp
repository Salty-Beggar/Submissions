
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
        l--;
        if (rps_map.count(l) == 0) {
            rps_map[l] = v;
        }else {
            rps_map[l] += v;
        }
        if (rps_map.count(r) == 0) {
            rps_map[l] = -v;
        }else {
            rps_map[r] -= v;
        }
    }

    long long cur_value = 0;
    long long prev_value_add = 0;
    long long prev_pos = 0;
    vector<pair<long long, long long>> prefix_sum_vec;
    vector<pair<long long, long long>> rps_vec;
    for (const auto[key, value] : rps_map) {
        rps_vec.push_back({key, value});
        cur_value += prev_value_add*(key-prev_pos);

        prefix_sum_vec.push_back({key, cur_value});
        prev_value = value;
        prev_pos = key;
    }

    for (long long i = 0; i < q; i++) {
        long long l, r;
        cin >> l >> r;
        l--;
        vector<pair<long long, long long>>::iterator prefix_sum_l = lower_bound(prefix_sum_vec.begin(), prefix_sum_vec.end(), {l, -1ll});
        vector<pair<long long, long long>>::iterator prefix_sum_r = upper_bound(prefix_sum_vec.begin(), prefix_sum_vec.end(), {r, 999999999999ll})-1;
        vector<pair<long long, long long>>::iterator rps_sum_l = lower_bound(rps_vec.begin(), rps_vec.end(), {l, -1ll});
        vector<pair<long long, long long>>::iterator rps_sum_r = upper_bound(rps_vec.begin(), rps_vec.end(), {r, 999999999999ll})-1;
        long long l_diff = prefix_sum_l - prefix_sum_vec.begin() - l;
        long long r_diff = r - (prefix_sum_r - prefix_sum_vec.begin());
    }

    return 0;
}
