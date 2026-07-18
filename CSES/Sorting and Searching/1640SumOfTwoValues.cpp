
#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
long int n, x, l, r;
pair<long int, long int> arr[MAX_N];

int main() {
    cin >> n >> x;
    if (n == 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    r = n-1;
    for (long int i = 0; i < n; i++) {
        long int a;
        cin >> a;
        arr[i] = {a, i+1};
    }

    sort(arr, arr+n);
    // cout << l << " " << r << " " << arr[l]+arr[r] << "\n";
    while (l < r-1 && arr[l].first+arr[r].first != x) {
        if (arr[l].first+arr[r].first < x) {
            l++;
        }else {
            r--;
        }
    }
    if (arr[l].first+arr[r].first == x) cout << arr[l].second << " " << arr[r].second;
    else cout << "IMPOSSIBLE";
    return 0;
}