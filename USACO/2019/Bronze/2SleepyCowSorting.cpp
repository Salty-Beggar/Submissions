
#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdio>

using namespace std;

int n, cows[100];

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
        cows[i]--;
    }
    int ans = n-1;
    for (int i = n-2; i >= 0; i--) {
        if (cows[i] > cows[i+1]) break;
        ans--;
    }
    cout << ans;
    return 0;
}