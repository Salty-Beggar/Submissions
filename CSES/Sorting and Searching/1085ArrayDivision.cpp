
#include <functional>
#include <iostream>
using namespace std;

const long long MAX_N = 200000, MAX_X = 1000000000, MAX_ANS = MAX_N*MAX_X;
long long n, k, arr[MAX_N];

long long first_true(function<bool(long long)> func) {
    long long l = 0, r = MAX_ANS;
    while (l+1 != r) {
        long long mid = (l+r)/2;
        if (!func(mid)) {
            l = mid;
        }else {
            r = mid;
        }
    }
    return r;
}

int main() {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << first_true([&](long long maximum_sum) {
        long long cur_sum = 0;
        long long minimum_divisions = 1;
        for (long long i = 0; i < n; i++) {
            long long x = arr[i];
            if (x > maximum_sum) return false;
            if (cur_sum+x > maximum_sum) {
                minimum_divisions++;
                cur_sum = 0;
            }
            cur_sum += x;
        }   
        // cout << "\n";
        return minimum_divisions <= k;
    });
    return 0;
}