
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct ball {
    public:
        long long l, r;
    ball() : l(0), r(0) {}
    bool operator<(const ball& other) const {
        return r > other.r;
    }
};

const long long MAX_N = 200000;
long long n, t;
ball range_arr[MAX_N];
priority_queue<ball> r_queue;

int main() {
    for (cin >> t; t > 0; t--) {
        while (!r_queue.empty()) r_queue.pop();
        cin >> n;
        for (long long i = 0; i < n; i++) {
            cin >> range_arr[i].l >> range_arr[i].r;
        }
        sort(range_arr, range_arr+n, [](const ball& a, const ball& b) {
            return a.l < b.l;
        });
        long long impossible = false;
        long long soonest_ball = -1;
        for (long long i = 0; i < n;) {
            long long cur_l = range_arr[i].l;
            while (!r_queue.empty() && soonest_ball < cur_l) {
                auto top_ball = r_queue.top();
                r_queue.pop();
                if (top_ball.r <= soonest_ball) {
                    impossible = true;
                    break;
                }
                soonest_ball++;
            }
            if (impossible) break;
            soonest_ball = max(soonest_ball, cur_l-1);
            while (i != n && range_arr[i].l == cur_l) {
                r_queue.push(range_arr[i]);
                i++;
            }
        }
        if (impossible) {
            cout << "No\n";
            continue;
        }
        while (!r_queue.empty()) {
            auto top_ball = r_queue.top();
            r_queue.pop();
            if (top_ball.r <= soonest_ball) {
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
    return 0;
}
