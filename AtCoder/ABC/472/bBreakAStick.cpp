
#include <bits/stdc++.h>
using namespace std;

const long long MAX_N = 100;
long long n, arr[MAX_N], total_sum = 0, other_sum = 0;

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        total_sum += arr[i];
    }

    long long ans = 1000000000000ll;
    for (long long i = 1; i < n; i++) {
        total_sum -= arr[i-1];
        other_sum += arr[i-1];
        ans = min(ans, abs(total_sum - other_sum));
    }
    cout << ans;
    return 0;
}
