
#include <queue>
#include <iostream>
using namespace std;

const long int MAX_N = 100000;
long int n, m, slices[MAX_N];
priority_queue<pair<long long int, long int>> slicesPQueue;

int main() {
    cin >> n >> m;
    if (m == 0) {
        long int maximum = 0;
        for (long int i = 0; i < n; i++) {
            cin >> slices[i];
            maximum = max(maximum, slices[i]);
        }
        for (long int i = 0; i < n; i++) {
            cout << maximum << " ";
        }
        return 0;
    }
    for (long int i = 0; i < n; i++) {
        cin >> slices[i];
        slicesPQueue.push({slices[i], i});
    }
    while (!empty(slicesPQueue)) {
        pair<long long int, long int> curSlice = slicesPQueue.top();
        slicesPQueue.pop();
        long long int curSliceSalt = curSlice.first;
        long int curSliceIndex = curSlice.second;
        if (slices[curSliceIndex] > curSliceSalt) continue;
        slices[curSliceIndex] = curSliceSalt;
        if (curSliceIndex > 0)
            slicesPQueue.push({slices[curSliceIndex]-m, curSliceIndex-1});
        if (curSliceIndex < n-1)
            slicesPQueue.push({slices[curSliceIndex]-m, curSliceIndex+1});
    }
    for (long int i = 0; i < n; i++) {
        cout << slices[i] << " ";
    }
    return 0;
}
