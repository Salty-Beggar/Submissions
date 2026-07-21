
#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX_N = 100000;
long int n;
pair<long int, long int> cows[MAX_N];

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    cin >> n;
    for (long int i = 0; i < n; i++) {
        long int x, y;
        cin >> x >> y;
        cows[i] = {y, x};
    }
    sort(cows, cows+n);
    long int maxPairSum = 0;
    long int l = 0, r = n-1;
    while (l < r || (l == r && cows[l].second > 0)) {
        maxPairSum = max(maxPairSum, cows[l].first+cows[r].first);
        long int smallerCount = min(cows[l].second, cows[r].second);
        cows[l] = {cows[l].first, cows[l].second-smallerCount};
        cows[r] = {cows[r].first, cows[r].second-smallerCount};
        if (cows[l].second == 0) l++;
        if (cows[r].second == 0) r--;
    }
    cout << maxPairSum;
}