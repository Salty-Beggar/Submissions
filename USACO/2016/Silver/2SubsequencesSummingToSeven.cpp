
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 50000;
int n;
pair<int, int> prefixSum[MAX_N+1];

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    cin >> n;
    prefixSum[0] = {0, 0};

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prefixSum[i+1] = {
            (prefixSum[i].first+x) % 7,
            i+1
        };
    }
    sort(prefixSum, prefixSum+n+1);
    
    int p = n+1; // The size of the prefix array, which has an additional null item for the case where the entire subarray is considered.
    int pointer = 0;
    int ans = 0;
    while (pointer < p) {
        int pivot = prefixSum[pointer].first;
        int arrStart = prefixSum[pointer].second;
        int arrEnd = 0;
        while (pointer < p && prefixSum[pointer].first == pivot) {
            arrEnd = prefixSum[pointer].second;
            pointer++;
        }
        ans = max(ans, arrEnd-arrStart);
    }
    cout << ans;
}