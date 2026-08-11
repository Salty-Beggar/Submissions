
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const long long MAX_N = 200000;
long long n, t;
pair<long long, long long> range_arr[MAX_N];
priority_queue<long long, vector<long long>, greater<long long>> r_queue;

int main() {
    for (cin >> t; t > 0; t--) {
        while (!r_queue.empty()) r_queue.pop();
        cin >> n;
        for (long long i = 0; i < n; i++) {
            long long l, r;
            cin >> l >> r;
            range_arr[i] = {l, r};
        }
        
        sort(range_arr, range_arr+n);
        long long soonest_ball = -1;
        bool impossible = false;
        for (long long i = 0; i < n;) {
            auto cur_range = range_arr[i];
            long long cur_l = cur_range.first;
            long long cur_r = cur_range.second;
            while (i != n && range_arr[i].first == cur_l) {
                r_queue.push(range_arr[i].second);
                i++;
            }
            long long top_r = r_queue.top();
            r_queue.pop();
            if (top_r <= soonest_ball) {
                impossible = true;
                break;
            }
            soonest_ball = max(cur_l, soonest_ball+1);
        }
        while (!impossible && !r_queue.empty()) {
            long long top_r = r_queue.top();
            r_queue.pop();
            if (top_r <= soonest_ball) {
                impossible = true;
                break;
            }
            soonest_ball++;
        }
        if (impossible) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
}