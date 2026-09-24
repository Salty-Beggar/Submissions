
// Utilizar fenwick tree para não misturar itens que vem somente depois no índice.

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const long long MAX_N = 60000;
long long n, k, q, l_stair_arr[MAX_N], r_stair_arr[MAX_N];
pair<long long, pair<long long, long long>> arr[MAX_N];

int main() {
    cin >> n >> q >> k;
    for (long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        arr[i] = {a, {a+i, a+n-1-i}};
    }

    sort(arr, arr+n);
    for (long long i = 0; i < n; i++) {
        l_stair_arr[i] = arr[i].second.first;
        swap(arr[i].second.first, arr[i].second.second);
    }
    sort(arr, arr+n);
    for (long long i = 0; i < n; i++) {
        r_stair_arr[i] = arr[i].second.first;
    }

    for (long long i = 0; i < n; i++) {
        // cout << l_stair_arr[i] << " " << r_stair_arr[i] << "\n";
    }

    long long ans = 0;
    multiset<long long> curr_numbers;
    for (long long i = 0; i < n; i++) {
        cout << l_stair_arr[i] << " " << l_stair_arr[i]-k << " " << curr_numbers.count(l_stair_arr[i]-k) << "\n";
        ans += curr_numbers.count(l_stair_arr[i]-k);
        curr_numbers.insert(l_stair_arr[i]);
    }
    curr_numbers.clear();
    for (long long i = 0; i < n; i++) {
        ans += curr_numbers.count(r_stair_arr[i]-k);
        curr_numbers.insert(r_stair_arr[i]);
    }
    cout << ans;

    return 0;
}
