
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const long long MAX_N = 100000;
long long n, m, curr_scc_index, scc_index[MAX_N];
vector<long long> adj_list[MAX_N], adj_list_inv[MAX_N], scc_tree[MAX_N], scc_tree_inv[MAX_N];
stack<long long> dfs_order;
bool visited[MAX_N];

void solve(long long index) {
    for (const long long child : adj_list[index]) {
        if (!visited[child]) {
            visited[child] = true;
            dfs_order.push_back(i);
            solve(i);
        }
    }
}

void kosajaru(long long index) {
    for (const long long child : adj_list_inv[index]) {
        if (visited[child]) {
            visited[child] = false;
            scc_index[child] = curr_scc_index;
            kosajaru(i);
        }else if (scc_index[child] != curr_scc_index) {
            if (scc_index[child] == 0 || curr_scc_index == 0) {
                scc_tree[scc_index[child]].push_back(curr_scc_index);
                scc_tree_inv[curr_scc_index].push_back(scc_index[child]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
        adj_list_inv[v].push_back(u);
    }

    for (long long i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs_order.push(i);
            solve(i);
        }
    }

    while (!dfs_order.empty()) {
        long long curr_node = dfs_order.top();
        dfs_order.pop();
        if (!visited[curr_node]) continue;
        scc_index[curr_node] = curr_scc_index;
        kosajaru(curr_node);
        curr_scc_index++;
    }

    long long scc_n = curr_scc_index;

    if (scc_n == 1) {
        cout << "YES";
        return 0;
    }

    cout << "NO\n";
    for (long long i = 0; i < n; i++) {
        if (scc_index[i] != 0) {
            
        }
    }

    return 0;
}
