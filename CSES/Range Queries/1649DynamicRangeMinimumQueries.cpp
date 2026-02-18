
#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX_N = 200000, MAX_NLOGN = 3600000;
const long long int MAX_X = 1000000000;
long int n, q;
long long int segTree[MAX_NLOGN];

void initializeSegTree() {
    for (long long int i = 0; i < MAX_NLOGN; i++) {
        segTree[i] = MAX_X;
    }
}

long long int _update(long int index, long long int value, long int treeIndex, long int l, long int r) {
    if (index < l || index >= r) return segTree[treeIndex];
    if (l == r-1) {
        segTree[treeIndex] = value;
        return value;
    }
    long int mid = (l+r)/2;
    segTree[treeIndex] = min(_update(index, value, treeIndex*2+2, mid, r), _update(index, value, treeIndex*2+1, l, mid));
    return segTree[treeIndex];
}

void update(long int index, long long int value) {
    _update(index, value, 0, 0, n);
}

long long int _query(long int l, long int r, long int _l, long int _r, long int treeIndex) {
    if (_r <= l || _l >= r) return MAX_X;
    if (_r <= r && _l >= l) return segTree[treeIndex];
    long int mid = (_l+_r)/2;
    return min(_query(l, r, mid, _r, treeIndex*2+2), _query(l, r, _l, mid, treeIndex*2+1));
}

long long int query(long int l, long int r) {
    return _query(l, r, 0, n, 0);
}

int main() {
    initializeSegTree();
    cin >> n >> q;
    for (long int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        update(i, x);
    }
    for (long int i = 0; i < q; i++) {
        long int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            update(a-1, b);
        }else {
            cout << query(a-1, b) << "\n";
        }
    }
}