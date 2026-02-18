
#include <iostream>
using namespace std;

const long int MAX_N = 100000, MAX_NLOGN = 1700000, INVALID_X = -1, INVALID_I = -1;
long int t, n, m;
pair<long int, long int> segTreeA[MAX_NLOGN], segTreeB[MAX_NLOGN];

// Segment tree
pair<long int, long int> _query(pair<long int, long int> segTree[MAX_NLOGN], long int l, long int r, long int tl, long int tr, long int tIndex) {
    if (tr <= l || tl >= r) return {INVALID_X, INVALID_I};
    if (tl >= l && tr <= r) {
        return segTree[tIndex];
    }
    long int tmid = (tl+tr)/2;
    return max(
        _query(segTree, l, r, tl, tmid, tIndex*2+1),
        _query(segTree, l, r, tmid, tr, tIndex*2+2)
    );
}
pair<long int, long int> query(pair<long int, long int> segTree[MAX_NLOGN], long int size, long int l, long int r) { // [l, r[
    return _query(segTree, l, r, 0, size, 0);
}

void _update(pair<long int, long int> segTree[MAX_NLOGN], long int index, long int value, long int tl, long int tr, long int tIndex) {
    if (index < tl || index >= tr) return;
    if (tl == tr-1) {
        segTree[tIndex] = {value, index};
        return;
    }
    long int tmid = (tl+tr)/2;
    _update(segTree, index, value, tl, tmid, tIndex*2+1);
    _update(segTree, index, value, tmid, tr, tIndex*2+2);
    segTree[tIndex] = max(segTree[tIndex*2+1], segTree[tIndex*2+2]);
}
void update(pair<long int, long int> segTree[MAX_NLOGN], long int size, long int index, long int value) {
    return _update(segTree, index, value, 0, size, 0);
}

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> m;
        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
            update(segTreeA, n, i, x);
        }
        for (long int i = 0; i < m; i++) {
            long int x;
            cin >> x;
            update(segTreeB, m, i, x);
        }

        // cout << query(segTreeA, n, 0, n) << " " << query(segTreeB, m, 0, m) << "\n";
        // for (long int i = 0; i < n; i++) {
        //     cout << query(segTreeA, n, i, i+1) << " ";
        // }
        // cout << "\n";
        // for (long int i = 0; i < 16; i++) {
        //     cout << segTreeA[i] << " ";
        // }
        // cout << "\n";
        // cout << "\n";
        // cout << "\n";

        bool gameEnded = false;
        string winner = "";
        while (!gameEnded) {
            pair<long int, long int> maxAlice = query(segTreeA, n, 0, n);
            pair<long int, long int> maxBob = query(segTreeB, m, 0, m);
            if (maxAlice.first == 0) {
                winner = "Bob";
                break;
            }
            
            update(segTreeB, m, maxBob.second, max(0l, maxBob.first - maxAlice.first));
            maxBob = query(segTreeB, m, 0, m);
            if (maxBob.first == 0) { 
                winner = "Alice";
                break;
            }

            update(segTreeA, n, maxAlice.second, max(0l, maxAlice.first - maxBob.first));
        }
        cout << winner << "\n";
    }
    return 0;
}
