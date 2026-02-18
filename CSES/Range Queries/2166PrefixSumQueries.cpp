
#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = 200000, MAX_NLOGN = 3600000;
long int n, q, arr[MAX_N];
long long int segTree[MAX_NLOGN][2]; // 0 - Prefix sum | 1 - Non-prefix, default sum

void _update(long int index, long int value, long int tl, long int tr, long int tIndex) {
    if (index < tl || index >= tr) return;
    segTree[tIndex][1] += value;
    if (tl == tr-1) {
        segTree[tIndex][0] = (segTree[tIndex][1] > 0) ? segTree[tIndex][1] : 0;
        return;
    }
    long int mid = (tl+tr)/2;
    _update(index, value, tl, mid, tIndex*2+1);
    _update(index, value, mid, tr, tIndex*2+2);
    segTree[tIndex][0] = max(segTree[tIndex*2+1][0], segTree[tIndex*2+1][1]+segTree[tIndex*2+2][0]);
    // segTree[tIndex][0] = max(segTree[tIndex][0], segTree[tIndex][1]);
}
void update(long int index, long int value) {
    long int add = value-arr[index];
    arr[index] = value;
    _update(index, add, 0, n, 0);
}

pair<long long int, long long int> _check(long int l, long int r, long int tl, long int tr, long int tIndex) {
    if (tr <= l || tl >= r) return {0, 0};
    if (tl >= l && tr <= r) return {segTree[tIndex][0], segTree[tIndex][1]};
    long int mid = (tl+tr)/2;
    auto prefixSumL = _check(l, r, tl, mid, tIndex*2+1);
    auto prefixSumR = _check(l, r, mid, tr, tIndex*2+2);
    return {
        max(prefixSumL.first, prefixSumL.second+prefixSumR.first),
        prefixSumL.second+prefixSumR.second
    };
}
long long int check(long int l, long int r) {
    return _check(l, r, 0, n, 0).first;
}

int main() {
    cin >> n >> q;
    for (long int i = 0; i < n; i++) {
        long int x;
        cin >> x;
        update(i, x);
    }
    // for (long int k = 0; k < n; k++) {
    //     cout << check(k, k+1) << " ";
    // }
    // cout << "\n";
    for (long int i = 0; i < q; i++) {
        long int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) { // Update
            a--;
            update(a, b);
            // for (long int k = 0; k < n; k++) {
            //     cout << check(k, k+1) << " ";
            // }
            // cout << "\n";
        }else { // Check
            a--;
            cout << check(a, b) << "\n";
        }
    }
    return 0;
}