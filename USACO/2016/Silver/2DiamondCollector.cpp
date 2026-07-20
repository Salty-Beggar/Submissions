// NlogN time complexity
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 50000;
int n;
long int k, arr[MAX_N];
int dp[MAX_N+1];

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && arr[r]-arr[l] <= k) {
            r++;
        }
        dp[l] = r-l;
    }
    for (int i = n-1; i >= 0; i--) {
        dp[i] = max(dp[i], dp[i+1]);
    }
    int ans = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && arr[r]-arr[l] <= k) {
            r++;
        }
        ans = max(ans, r-l+dp[r]);
    }
    cout << ans;
}
