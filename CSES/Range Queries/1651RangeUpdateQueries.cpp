
#include <iostream>
using namespace std;

const long int MAX_N = 200000, MAX_NLOGN = 3600000;
long int n, q;
long long int segTree[MAX_NLOGN], lazy[MAX_NLOGN];

void unlazy(long int tl, long int tr, long int tIndex) {
    segTree[tIndex] += lazy[tIndex]*(tr-tl);
    if (tIndex*2+1 < MAX_NLOGN) lazy[tIndex*2+1] += lazy[tIndex];
    if (tIndex*2+2 < MAX_NLOGN) lazy[tIndex*2+2] += lazy[tIndex];
    lazy[tIndex] = 0;
}

void _update(long int l, long int r, long long int value, long int tl, long int tr, long int tIndex) {
    //if (tIndex > 1000) return;
    unlazy(tl, tr, tIndex);
    if (tr <= l || tl >= r) return;
    if (tr <= r && tl >= l) {
        lazy[tIndex] = value;
        unlazy(tl, tr, tIndex);
        return;
    }
    long int mid = (tl+tr)/2;
    _update(l, r, value, tl, mid, tIndex*2+1);
    _update(l, r, value, mid, tr, tIndex*2+2);
    segTree[tIndex] = segTree[tIndex*2+1]+segTree[tIndex*2+2];
}

void update(long int l, long int r, long long int value) {
    _update(l, r, value, 0, n, 0);
}

long long int _check(long int index, long int tl, long int tr, long int tIndex) {
    unlazy(tl, tr, tIndex);
    if (tr <= index || tl > index) return 0;
    if (tl == tr-1) return segTree[tIndex];
    long int mid = (tl+tr)/2;
    return _check(index, tl, mid, tIndex*2+1)+_check(index, mid, tr, tIndex*2+2);
}

long long int check(long int index) {
    return _check(index, 0, n, 0);
}


int main() {
    cin >> n >> q;
    for (long int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        update(i, i+1, x);
    }
    
    for (long int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            long int l, r;
            long long int u;
            cin >> l >> r >> u;
            update(l-1, r, u);
        }else {
            long int k;
            cin >> k;
            cout << check(k-1) << "\n";
        }
    }
    
    return 0;
}