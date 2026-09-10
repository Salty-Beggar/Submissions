
#include <iostream>
#include <algorithm>
using namespace std;

const long long MAX_M = 40;
long long t, n, m, packages[MAX_M];

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> m;
        for (long long i = 0; i < m; i++) {
            cin >> packages[i];
        }
        long long cur_bag_index = 0;
        long long cur_max_bag_diff = 0;
        long long cur_max_bag = 0;
        long long cur_bag_weight = 0;
        for (long long i = m-1; i >= 0; i--) {
            long long cur_package_amount = packages[i];
            long long cur_package_weight = 1ll<<i;
            if (cur_package_amount == 0) continue;

            long long bag_weight_gain = cur_package_amount * cur_package_weight;
            cur_bag_weight += bag_weight_gain;
            if (cur_max_bag_diff != 0) {
                cur_bag_index += cur_bag_weight/cur_max_bag_diff;
                cur_bag_weight %= cur_max_bag_diff;
            } else {
                cur_bag_index = n;
                cur_bag_weight = 0;
            }
            if (cur_bag_index >= n) {
                cur_package_amount -= (cur_bag_index - n)*(cur_max_bag_diff/cur_package_weight);
                cur_package_amount -= cur_bag_weight/cur_package_weight;
                cur_bag_index = cur_package_amount%n;
                cur_max_bag += (cur_package_amount/n+1)*cur_package_weight;
                cur_max_bag_diff = cur_package_weight;
            }
        }

        cout << cur_max_bag << "\n";
    }
    return 0;
}