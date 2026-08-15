
#include <iostream>
#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

const long long MAX_N = 100000;

struct edge {
    public:
    long long u, v, w;
    bool operator<(const auto& edge) const {
        return w < edge.w;
    }
};

long long 
    n, m, cow_next[MAX_N], cc_index[MAX_N], 
    cc_monarch[MAX_N], disjoint_set[MAX_N], 
    disjoint_set_weight[MAX_N];
edge edges[MAX_N];

long long last_true(function<bool(long long)> func) {
    long long l = 0, r = m;
    while (l != r-1) {
        long long mid = (l+r)/2;
        if (func(mid)) {
            l = mid;
        }else {
            r = mid;
        }
    }
    return edges[l].w;
}

#pragma region Disjoint set

long long find(long long u) {
    if (disjoint_set[u] == u) return u;
    disjoint_set[u] = find(disjoint_set[u]);
    return disjoint_set[u];
}

bool is_joined(long long u, long long v) {
    return find(u) == find(v);
}

bool is_joined(edge edge) {
    return is_joined(edge.u, edge.v);
}

void join(long long u, long long v) {
    if (is_joined(u, v)) return;
    if (disjoint_set_weight[u] > disjoint_set_weight[v]) {
        swap(u, v);
    }else if (disjoint_set_weight[u] == disjoint_set_weight[v]) {
        disjoint_set[u] = v;
        disjoint_set_weight[v]++;
        return;
    }
    disjoint_set[u] = v;
}

void join(edge edge) {
    join(edge.u, edge.v);
}

#pragma endregion

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin >> n >> m;
    
    for (long long i = 0; i < n; i++) {
        cc_index[i] = -1;
        cin >> cow_next[i];
        cow_next[i]--;
    }

    long long curr_cc_index = 0;
    for (long long i = 0; i < n; i++) {
        long long curr_cow = i;
        long long curr_cow_pointer = curr_cow;
        if (cc_index[curr_cow] != -1) continue;
        do {
            cc_monarch[curr_cow_pointer] = curr_cow;
            cc_index[curr_cow_pointer] = curr_cc_index;
            curr_cow_pointer = cow_next[curr_cow_pointer];
        } while (curr_cow_pointer != curr_cow);
        curr_cc_index++;
    }
    long long cc_n = curr_cc_index;

    for (long long i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
    }
    sort(edges, edges+m);

    cout << last_true([](long long index) {
        for (long long i = 0; i < n; i++) {
            disjoint_set[i] = i;
            disjoint_set_weight[i] = 0;
        }
        for (long long i = index; i < m; i++) {
            join(edges[i]);
        }
        for (long long i = 0; i < n; i++) {
            long long curr_monarch = cc_monarch[i];
            // cout << cc_index[i] << "\n";
            if (!is_joined(i, curr_monarch)) {
                return false;
            }
        }
        return true;

    });
}
