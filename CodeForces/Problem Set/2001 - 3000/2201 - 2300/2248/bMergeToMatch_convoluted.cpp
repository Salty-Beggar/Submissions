
#include <iostream>
#include <algorithm>
using namespace std;

const long long MAX_NM = 200000;
long long t, n, m, arr[MAX_NM], arr_rev[MAX_NM], targ_arr[MAX_NM],
right_range_sum[MAX_NM], left_range_sum[MAX_NM];

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> m;
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
            arr_rev[n-i-1] = arr[i];
            right_range_sum[i] = 0;
            left_range_sum[i] = 0;
        }
        for (long long i = 0; i < m; i++) {
            cin >> targ_arr[i];
        }
        sort(arr, arr+n);
        sort(targ_arr, targ_arr+m);
        bool impossible = false;
        long long left_last = -1;
        long long left_space = 0;
        for (long long i = 0; i < m; i++) {
            long long cur_target = targ_arr[i];
            long long left_neighbour = n-1-(lower_bound(arr_rev, arr_rev+n, cur_target, greater()) - arr_rev);
            left_space += left_neighbour - left_last;
            long long right_neighbour = lower_bound(arr, arr+n, cur_target) - arr;
            if (left_neighbour < 0 || right_neighbour >= n) {
                cout << "NO\n";
                impossible = true;
                break;
            }else if (left_neighbour == right_neighbour) {
                long long equal_neighbour = left_neighbour;
                left_neighbour--;
                right_neighbour++;
                if (left_space == 1) {
                    if (right_neighbour >= n) {
                        cout << "NO\n";
                        impossible = true;
                        break;
                    }
                    left_range_sum[equal_neighbour]++;
                    right_range_sum[right_neighbour]++;
                    left_last = equal_neighbour;
                    left_space--;
                }else {
                    left_range_sum[left_neighbour]++;
                    right_range_sum[equal_neighbour]++;
                    left_last = left_neighbour;
                    left_space--;
                }
                continue;
            }
            left_range_sum[left_neighbour]++;
            left_space--;
            right_range_sum[right_neighbour]++;

            left_last = left_neighbour;
        }
        if (impossible) continue;
        long long l_acc = 0;
        long long r_acc = 0;
        for (long long i = 0; i < n; i++) {
            r_acc += right_range_sum[i];
            r_acc = max(0ll, r_acc-1);
        }
        for (long long i = n-1; i >= 0; i--) {
            l_acc += left_range_sum[i];
            l_acc = max(0ll, l_acc-1);
        }
        if (l_acc > 0 || r_acc > 0) {
            cout << "NO\n";
        }else {
            cout << "YES\n";
        }
    }
    return 0;
}