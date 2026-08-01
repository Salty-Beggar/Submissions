
#include <functional>
#include <iostream>
using namespace std;

const long long MAX_N = 100000;
long long 
    init_x, init_y, 
    targ_x, targ_y, 
    n,
    x_prefix_sum[MAX_N+1],
    y_prefix_sum[MAX_N+1]
;

long long first_true(function<bool(long long)> func) {
    long long l = 0, r = 100000000000000000;
    while (l != r-1) {
        long long mid = (l+r)/2;
        if (!func(mid)) {
            l = mid;
        }else {
            r = mid;
        }
    }
    return (r == 100000000000000000) ? -1: r;
}

int main() {
    cin >> init_x >> init_y >> targ_x >> targ_y >> n;
    for (long long i = 0; i < n; i++) {
        char wind_dir;
        cin >> wind_dir;
        switch (wind_dir) {
            case 'R':
                x_prefix_sum[i+1] = 1;
                break;
            case 'L':
                x_prefix_sum[i+1] = -1;
                break;
            case 'U':
                y_prefix_sum[i+1] = 1;
                break;
            case 'D':
                y_prefix_sum[i+1] = -1;
                break;
        }
        x_prefix_sum[i+1] += x_prefix_sum[i];
        y_prefix_sum[i+1] += y_prefix_sum[i];
    }
    cout << first_true([&](long long distance) {
        // cout << distance << " ";
        long long x_offset = x_prefix_sum[n]*(distance/n) + x_prefix_sum[distance%n];
        long long y_offset = y_prefix_sum[n]*(distance/n) + y_prefix_sum[distance%n];
        return abs(targ_x - init_x - x_offset)+abs(targ_y - init_y - y_offset) <= distance;
    });
    return 0;
}