
#include <bits/stdc++.h>
using namespace std;

const long long MAX_NM = 200000;
long long 
    t, n, m, 
    disjoint_set[MAX_NM], disjoint_set_weight[MAX_NM], 
    degrees[MAX_NM],
    next_of[MAX_NM][2],
    node_to_index[MAX_NM],
    index_to_node[MAX_NM];

#pragma region Disjoint set

long long find(long long u) {
    if (disjoint_set[u] == u) return u;
    long long monarch = find(disjoint_set[u]);
    disjoint_set[u] =  monarch;
    return monarch;
}
bool is_joined(long long u, long long v) {
    return find(u) == find(v);
}
void join(long long u, long long v) {
    u = find(u);
    v = find(v);
    if (is_joined(u, v)) return;
    if (disjoint_set_weight[u] == disjoint_set_weight[v]) {
        disjoint_set[u] = v;
        disjoint_set_weight[v]++;
        return;
    }else if (disjoint_set_weight[u] > disjoint_set_weight[v]) {
        swap(u, v);
    }
    disjoint_set[u] = v;
}

#pragma endregion

struct edge {
    public:
    long long u, v;
    edge() : u(0), v(0) {}
    edge(long long u, long long v) : u(u), v(v) {}
    bool joined() {
        return is_joined(u, v);
    }
    void join_self() {
        join(u, v);
    }
    long long delta_index() {
        return abs(node_to_index[u] - node_to_index[v]);
    }
};

edge edges[MAX_NM];

int main() {
    cin >> t;
    for (; t > 0; t--) {
        cin >> n >> m;
        for (long long i = 0; i < n; i++) {
            disjoint_set[i] = i;
            disjoint_set_weight[i] = 0;
            degrees[i] = 0;
            next_of[i][0] = -1;
            next_of[i][1] = -1;
        }
        for (long long i = 0; i < m; i++) {
            long long u, v;
            cin >> u >> v;
            u--; v--;
            edges[i] = edge(u, v);
        }
        // Creating the linear graph.
        long long last_degree = 0;
        for (long long i = 0; i < m; i++) {
            edge curr_edge = edges[i];
            if (!curr_edge.joined()) {
                curr_edge.join_self();
                long long _u = curr_edge.u, _v = curr_edge.v;
                if (next_of[_u][0] == -1)
                    next_of[curr_edge.u][0] = curr_edge.v;
                else 
                    next_of[curr_edge.u][1] = curr_edge.v;
                if (next_of[_v][0] == -1)
                    next_of[curr_edge.v][0] = curr_edge.u;
                else 
                    next_of[curr_edge.v][1] = curr_edge.u;
                degrees[curr_edge.u]++;
                degrees[curr_edge.v]++;
                if (degrees[curr_edge.u] == 1) last_degree = curr_edge.u;
                else if (degrees[curr_edge.v] == 1) last_degree = curr_edge.v;
            }
        }

        node_to_index[last_degree] = 0;
        index_to_node[0] = last_degree;
        long long prev_pointer = last_degree;
        long long curr_pointer = next_of[last_degree][0];
        if (curr_pointer == -1) curr_pointer = next_of[last_degree][1];
        for (long long i = 1; i < n; i++) {
            node_to_index[curr_pointer] = i;
            index_to_node[i] = curr_pointer;
            long long new_pointer = next_of[curr_pointer][0];
            if (new_pointer == prev_pointer) {
                new_pointer = next_of[curr_pointer][1];
            }
            prev_pointer = curr_pointer;
            curr_pointer = new_pointer;
        }

        bool done = false;
        for (long long i = 0; i < m; i++) {
            edge curr_edge = edges[i];
            long long delta_index = curr_edge.delta_index();
            if (delta_index%2 == 0) {
                cout << (delta_index+1) << "\n";
                long long curr_pointer = min(node_to_index[curr_edge.u], node_to_index[curr_edge.v]);
                for (long long j = 0; j <= delta_index; j++) {
                    cout << index_to_node[curr_pointer]+1 << " ";
                    curr_pointer++;
                }
                cout << "\n";
                done = true;
                break;
            }
        }
        if (done) continue;
        cout << "-1\n";
    }
}
