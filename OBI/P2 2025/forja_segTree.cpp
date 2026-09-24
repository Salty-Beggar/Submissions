
#include <iostream>
using namespace std;

const long long MAX_N = 100000, MAX_NLOGN = 1700000;
long long n, k, dp[MAX_N], seg_tree[MAX_NLOGN];

void _update(long long index, long long value, long long ti, long long tl, long long tr) {
    if (index < tl || index >= tr) {
        return;
    }
    seg_tree[ti] |= value;
    if (tl+1 == tr) return;
    _update(index, value, ti*2+1, tl, (tl+tr)/2);
    _update(index, value, ti*2+2, (tl+tr)/2, tr);
}

void update(long long index, long long value) {
    _update(index, value, 0, 0, n);
}

long long _query(long long l, long long r, long long ti, long long tl, long long tr) {
    if (tr <= l || tl >= r) return 0;
    if (tl >= l && tr <= r) return seg_tree[ti];
    return
        _query(l, r, ti*2+1, tl, (tl+tr)/2)
        | _query(l, r, ti*2+2, (tl+tr)/2, tr);
}

long long query(long long l, long long r) {
    return _query(l, r, 0, 0, n);
}

int main() {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        update(i, a);
    }
    
    return 0;
}
