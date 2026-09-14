#include <bits/stdc++.h>
using namespace std;

const long long MAX_N = 200000;

long long n, m, k, curr_sum, arr[MAX_N];

int main() {
    cin >> n >> m >> k;

    for (long long i = 0; i < n; i++) {
        if (i >= m) {
            curr_sum -= arr[i - m];
        }
        long long curr_calorie;
        cin >> curr_calorie;
        if (curr_sum+curr_calorie <= k) {
            cout << "Yes\n";
            arr[i] = curr_calorie;
            curr_sum += curr_calorie;
            continue;
        }
        cout << "No\n";
    }
    return 0;
}
