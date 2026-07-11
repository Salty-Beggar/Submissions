
#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
long int n, prefixSum[MAX_N+1];

int main() {
    cin >> n;
    for (long int i = 1; i <= n; i++) {
        long int x;
        cin >> x;
        prefixSum[i] = prefixSum[i-1]+x;
        prefixSum[i] %= n;
        if (prefixSum[i] < 0) prefixSum[i] += n;
    }
    sort(prefixSum, prefixSum+n+1);
    long long int ans = 0;
    long int pointer = 0;
    while (pointer < n+1) {
        long int pivot = prefixSum[pointer];
        long int streak = 0;
        while (pointer < n+1 && prefixSum[pointer] == pivot) {
            // cout << prefixSum[pointer] << " ";
            streak++;
            pointer++;
        }
        ans += streak*(streak-1)/2;
    }
    cout << ans;
    return 0;
}
