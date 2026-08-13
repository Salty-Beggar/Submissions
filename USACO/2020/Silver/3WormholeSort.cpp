
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct edge {
    public:
    long long u, v, w;
    edge(long long u, long long v, long long w) : u(u), v(v), w(w) {}
    bool operator <(const edge& other) const {
        return w < other.w;
    }
};

const long long MAX_N = 100000, MAX_W = 1000000000;
long long n, m, cows[MAX_N], cc_index[MAX_N], cc_count[MAX_N], disjoint_set[MAX_N], disjoint_set_weight[MAX_N];
priority_queue<edge> edges;

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

int main() {
    // freopen("wormsort.in", "r", stdin);
    // freopen("wormsort.out", "w", stdout);
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        disjoint_set[i] = i;
        cc_index[i] = -1;
        // cc_count[i] = -1;
        cin >> cows[i];
        cows[i]--;
    }
    
    long long curr_cc_index = -1;
    for (long long i = 0; i < n; i++) {
        long long curr_cow = cows[i];
        if (cc_index[curr_cow] == -1) { 
            curr_cc_index++;
            while (cc_index[curr_cow] == -1) {
                // cout << curr_cc_index << " ";
                cc_index[curr_cow] = curr_cc_index;
                cc_count[curr_cc_index]++;
                curr_cow = cows[curr_cow];
            }
        }
    }
    long long cc_n = curr_cc_index+1;

    // for (long long i = 0; i < cc_n; i++) {
    //     cout << cc_count[i] << " ";
    // }
    // cout << "\n";

    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push(edge(u, v, w));
    }

    // RIGHT_NOW: Do the binary search algorithm
    long long min_weight = MAX_W;
    for (long long i = 0; i < m; i++) {
        edge top_edge = edges.top();
        // cout << top_edge.u << " " << top_edge.v << " " << top_edge.w << "\n";
        edges.pop();
        if (
            (
                cc_count[cc_index[top_edge.u]] <= 1
                && cc_count[cc_index[top_edge.v]] <= 1
            )
            || is_joined(top_edge)
        ) {

        }else {
            min_weight = min(min_weight, top_edge.w);
        }
        if (cc_index[top_edge.u] == cc_index[top_edge.v]) {
            cc_count[cc_index[top_edge.u]]--;
        }
        join(top_edge);
    }
    cout << min_weight;
    return 0;
}
