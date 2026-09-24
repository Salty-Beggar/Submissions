
#include <vector>
#include <iostream>
using namespace std;

const long long MAX_N = 100000, MAX_LOGN = 17, MAX_NLOGN = MAX_N*MAX_LOGN;
long long n, q, bin_leap[MAX_N][MAX_LOGN], euler_arr[MAX_N][2], euler_i;
vector<long long> adj_list[MAX_N];
// 0 - O índice do nobre no euler. 1 - O tamanho da sub-tree do nobre.

long long _euler(long long nobre) {
    euler_arr[nobre][0] = euler_i++;
    long long curr_size = 0;
    for (auto child : adj_list[nobre]) {
        curr_size += 1+_euler(child);
    }
    euler_arr[nobre][1] = curr_size;
    return curr_size;
}

void euler() {
    _euler(0);
}

// Segment tree
long long seg_tree[MAX_NLOGN], lz[MAX_NLOGN];

// void print() {
//     _print(0, 0, n);
// }

void unlazy(long long ti) {
    if (lz[ti] == -1) return;
    seg_tree[ti] = lz[ti];
    lz[ti*2+1] = lz[ti];
    lz[ti*2+2] = lz[ti];
    lz[ti] = -1;
}

void _update(long long l, long long r, long long value, long long ti, long long tl, long long tr) {
    if (tr <= l || tl >= r) return;
    if (tl >= l && tr <= r) {
        lz[ti] = value;
        return;
    }
    _update(l, r, value, ti*2+1, tl, (tl+tr)/2);
    _update(l, r, value, ti*2+2, (tl+tr)/2, tr);
}

void update(long long l, long long r, long long value) {
    _update(l, r, value, 0, 0, n);
}

long long _query(long long index, long long ti, long long tl, long long tr) {
    // cout << tl << " " << tr << "\n";
    if (index < tl || index >= tr) return 0;
    unlazy(ti);
    if (index == tl && index == tr-1) return seg_tree[ti];
    return 
        _query(index, ti*2+1, tl, (tl+tr)/2)
        +_query(index, ti*2+2, (tl+tr)/2, tr);
}

long long query(long long index) {
    return _query(index, 0, 0, n);
}

int main() {
    for (long long i = 0; i < MAX_NLOGN; i++) {
        seg_tree[i] = -1;
        lz[i] = -1;
    }
    cin >> n;
    for (long long i = 1; i < n; i++) {
        cin >> bin_leap[i][0];
        bin_leap[i][0]--;
        adj_list[bin_leap[i][0]].push_back(i);
    }
    euler();
    for (long long i = 1; i < n; i++) {
        for (long long j = 1; j < MAX_LOGN; j++) {
            bin_leap[i][j] = bin_leap[bin_leap[i][j-1]][j-1];
        }
    }

    cin >> q;
    for (; q > 0; q--) {
        long long type;
        cin >> type;
        if (type == 1) { // Query
            long long v, k;
            cin >> v >> k;
            v--;
            long long superior = query(euler_arr[v][0]);
            if (superior != -1) k--;
            v = (superior == -1) ? v : superior;
            for (long long i = 0; i < MAX_LOGN; i++) {
                long long curr_bit = 1<<i;
                if ((curr_bit&k) != 0) {
                    v = bin_leap[v][i];
                }
            }
            cout << v+1 << "\n";
        } else { // Restruturação
            long long v;
            cin >> v;
            v--;
            if (query(euler_arr[v][0]) != -1) continue;
            update(euler_arr[v][0]+1, euler_arr[v][0]+euler_arr[v][1]+1, v);
        }
    }
}
