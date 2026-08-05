
#include <iostream>
#include <cstdio>
#include <map>
#include <stack>
using namespace std;

long long n;
map<long long, long long> peaks;
stack<pair<long long, long long>> peak_stack;

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    
    cin >> n;

    for (long long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        peaks[x] = max(peaks[x], y);
    }
    n = peaks.size();
    for (auto[cur_peak_x, cur_peak_y] : peaks) {
        while (!peak_stack.empty() 
        && (cur_peak_x - peak_stack.top().first <= cur_peak_y - peak_stack.top().second)) {
            peak_stack.pop();
        }
        if (peak_stack.empty() || cur_peak_x - peak_stack.top().first > peak_stack.top().second - cur_peak_y) {
            peak_stack.push({cur_peak_x, cur_peak_y});
        }
    }

    cout << peak_stack.size();

    return 0;
}