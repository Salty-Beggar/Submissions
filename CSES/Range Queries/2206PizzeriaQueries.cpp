
#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = 200000, MAX_NLOGN = 3600000, MAX_X = 100200000;
long int n, q, arr[MAX_N], westSegTree[MAX_NLOGN][2], eastSegTree[MAX_NLOGN][2]; // Same for pair.

// First is value, second is index
pair<long int, long int> _query(long int segTree[MAX_NLOGN][2], long int index, long int tl, long int tr, long int tIndex) {
    if (tl > index) return {MAX_X, n-1};
    if (tr <= index+1) {
        return {segTree[tIndex][0], segTree[tIndex][1]};
    }
    long int mid = (tl+tr)/2;
    pair<long int, long int> lAns = _query(segTree, index, tl, mid, tIndex*2+1);
    pair<long int, long int> rAns = _query(segTree, index, mid, tr, tIndex*2+2);
    if (lAns.first+n-1-lAns.second < rAns.first+n-1-rAns.second)
        return lAns;
    else
        return rAns;
}
long int query(long int segTree[MAX_NLOGN][2], long int index) { // You only ever do queries starting from 0. Index is inclusive.
    pair<long int, long int> ans = _query(segTree, index, 0, n, 0);
    return ans.first+(index-ans.second);
}

void _update(long int segTree[MAX_NLOGN][2], long int index, long int value, long int tl, long int tr, long int tIndex) {
    if (tl > index || tr <= index) return;
    if (tl == tr-1) {
        segTree[tIndex][0] = value;
        segTree[tIndex][1] = index;
        return;
    }
    long int mid = (tl+tr)/2;
    _update(segTree, index, value, tl, mid, tIndex*2+1);
    _update(segTree, index, value, mid, tr, tIndex*2+2);
    if (segTree[tIndex*2+1][0]+n-1-segTree[tIndex*2+1][1] < segTree[tIndex*2+2][0]+n-1-segTree[tIndex*2+2][1]) {
        segTree[tIndex][0] = segTree[tIndex*2+1][0];
        segTree[tIndex][1] = segTree[tIndex*2+1][1];
    }else {
        segTree[tIndex][0] = segTree[tIndex*2+2][0];
        segTree[tIndex][1] = segTree[tIndex*2+2][1];
    }
}

void update(long int index, long int value) {
    _update(westSegTree, index, value, 0, n, 0);
    _update(eastSegTree, n-1-index, value, 0, n, 0);
}

int main() {
    cin >> n >> q;
    for (long int i = 0; i < MAX_NLOGN; i++) {
        westSegTree[i][0] = MAX_X;
        westSegTree[i][1] = n-1;
        eastSegTree[i][0] = MAX_X;
        eastSegTree[i][1] = n-1;
    }
    for (long int i = 0; i < n; i++) {
        long int x;
        cin >> x;
        update(i, x);
    }
    // for (long int i = 0; i <= 1+2+4+8; i++) {
    //     cout << ((westSegTree[i][0] == MAX_X) ? -1 : westSegTree[i][0]) << " " << westSegTree[i][1] << "  ";
    //     if (i == 0 || i == 2 || i == 6 || i == 14) cout << "\n";
    // }
    // cout << "\n";
    // for (long int i = 0; i < n; i++) {
    //     cout << query(westSegTree, i) << " " << query(eastSegTree, i) << "\n";
    // }
    // cout << "\n";
    
    for (long int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) { // update
            long int k, u;
            cin >> k >> u;
            k--;
            update(k, u);
            // cout << "\n";
            // for (long int i = 0; i < n; i++) {
            //     cout << query(westSegTree, i) << " " << query(eastSegTree, i) << "\n";
            // }
            // cout << "\n";
        }else {
            long int k;
            cin >> k;
            k--;
            cout << min(query(westSegTree, k), query(eastSegTree, n-1-k)) << "\n";
        }
    }
    
    return 0;
}
