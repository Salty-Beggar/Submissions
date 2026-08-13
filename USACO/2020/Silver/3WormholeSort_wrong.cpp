
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const long long MAX_N = 100000, MAX_W = 1000000000;

struct edge {
    public:
        long long u, v, w;
    edge(long long u, long long v, long long w) : u(u), v(v), w(w) {}
    bool operator<(const edge& other) const {
        return w > other.w;
    }
};

struct cc {
    vector<long long> disjoint_set_weight;
    public:
        long long n;
        priority_queue<edge> edges;
        vector<long long> disjoint_set;
    void initialize() {
        for (long long i = 0; i < n; i++) {
            disjoint_set.push_back(i);
            disjoint_set_weight.push_back(0);
        }
    }
    long long monarch(long long u) {
        if (disjoint_set[u] == u) return u;
        disjoint_set[u] = monarch(disjoint_set[u]);
        return disjoint_set[u];
    }
    bool is_joined(long long u, long long v) {
        return monarch(u) == monarch(v);
    }
    bool is_joined(edge edge) {
        return monarch(edge.u) == monarch(edge.v);
    }
    void join(edge edge) {
        join(edge.u, edge.v);
    }
    void join(long long u, long long v) {
        u = monarch(u);
        v = monarch(v);
        if (is_joined(u, v)) return;
        if (disjoint_set_weight[u] > disjoint_set_weight[v]) {
            swap(u, v);
        }else if (disjoint_set_weight[u] == disjoint_set_weight[v]) {
            disjoint_set[u] = v;
            disjoint_set_weight[v]++;
        }
        disjoint_set[u] = v;
    }
};

long long n, m, cc_n, cows[MAX_N], cows_cc_index[MAX_N];
cc connected_components[MAX_N];

int main() {
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        cows_cc_index[i] = -1;
        cin >> cows[i];
        cows[i]--;
    }

    long long curr_cc_index = 0;
    for (long long i = 0; i < n; i++) {
        if (cows_cc_index[i] == -1) {
            long long curr_cc_n = 0;
            while (cows_cc_index[cows[i]] == -1) {
                cows_cc_index[cows[i]] = curr_cc_index;
                curr_cc_n++;
                i = cows[i];
            }
            connected_components[curr_cc_index].n = curr_cc_n;
            connected_components[curr_cc_index].initialize();
            curr_cc_index++;
        }
    }
    long long cc_n = curr_cc_index;

    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        if (cows_cc_index[u] != cows_cc_index[v]) continue;
        long long curr_cc_index = cows_cc_index[u];
        connected_components[curr_cc_index].edges.push(edge(u, v, w));
    }

    long long min_weight = MAX_W;
    for (long long i = 0; i < cc_n; i++) {
        cc curr_cc = connected_components[i];
        long long mst_remain = curr_cc.n-1;
        while (mst_remain > 0) {
            edge top_edge = curr_cc.edges.top();
            curr_cc.edges.pop();
            // RIGHT_NOW: You're excluding the possibility of using edges between connected components.
            cout << top_edge.u << " " << top_edge.v << "\n";
            // if (curr_cc.is_joined(top_edge)) continue;
            // curr_cc.join(top_edge);
            // min_weight = min(min_weight, top_edge.w);
            // mst_remain--;
        }
    }

    cout << min_weight;

    return 0;
}
