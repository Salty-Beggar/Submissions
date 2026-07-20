
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 50000;
int n;
long int k, arr[MAX_N];

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    long int maxDiamonds = 0;
    long int r = 0;
    long int seqMax = 0;
    for (long int l = 0; l < n; l++) {
        while (r < n && max(arr[r], seqMax)-arr[l] <= k) {
            seqMax = max(arr[r], seqMax);
            r++;
        }
        long int y = r;
        long int rSeqMax = 0;
        for (long int x = r; x < n; x++) {
            while (y < n && max(arr[y], rSeqMax)-arr[x] <= k) {
                rSeqMax = max(arr[y], rSeqMax);
                y++;
            }
            maxDiamonds = max(maxDiamonds, r+y-l-x);
        }
    }
    cout << maxDiamonds;
    return 0;
}