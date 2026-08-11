
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const long long MAX_N = 100000;
long long n, cows[MAX_N][3];
priority_queue<pair<long long, long long>> cow_queue;

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cows[i][1] = i;
        long long a, t;
        cin >> a >> t;
        cin >> cows[i][0] >> cows[i][2];
    }
    sort(cows, cows+n, [](const long long[MAX_N][3] a, const long long[MAX_N][3] b) -> bool {
        return (a[0] != b[0]) ? a[0] < b[0] : a[1] < b[1];
    });
    long long max_waiting_time = 0;
    long long curr_stop_time = -1;
    for (long long i = 0; i < n; i++) {
        if (!cow_queue.empty()) {
            auto curr_cow_top = cow_queue.top();
            long long curr_cow_arrival = cows[i][0];
            if (curr_cow_arrival > curr_stop_time) {
                long long curr_cow_top_info[3] = {cows[curr_cow_top.second][0], cows[curr_cow_top.second][1], cows[curr_cow_top.second][2]};
                max_waiting_time = max(max_waiting_time, curr_stop_time - curr_cow_top_info[0]);
                curr_stop_time = curr_cow_top_info[0]+curr_cow_top_info[2];
            }
        }
        cow_queue.push(make_pair(cows[i][1], i));
    }
}
