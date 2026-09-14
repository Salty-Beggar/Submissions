
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long MAX_N = 300000;
long long n;
priority_queue<long long> left_cookies;
priority_queue<
    long long,
    vector<long long>,
    greater<long long>
> right_cookies;

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if (a < 0) {
            left_cookies.push(a);
        }else {
            right_cookies.push(a);
        }
    }

    long long ans = 0;
    long long curr_pos = 0;
    while (!left_cookies.empty() || !right_cookies.empty()) {
        if (left_cookies.empty()) {
            ans += right_cookies.top() - curr_pos;
            curr_pos = right_cookies.top();
            right_cookies.pop();
            continue;
        }
        if (right_cookies.empty()) {
            ans += curr_pos - left_cookies.top();
            curr_pos = left_cookies.top();
            left_cookies.pop();
            continue;
        }
        long long delta_r = right_cookies.top() - curr_pos;
        long long delta_l = curr_pos - left_cookies.top();
        if (delta_r < delta_l) {
            ans += delta_r;
            curr_pos += delta_r;
            right_cookies.pop();
        }else {
            ans += delta_l;
            curr_pos -= delta_l;
            left_cookies.pop();
        }
    }

    cout << ans;
    return 0;
}
