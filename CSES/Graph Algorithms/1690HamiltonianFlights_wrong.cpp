
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long MAX_N = 20, MODULO = 1000000007;
long long n, m, dp[1 << MAX_N];
vector<vector<long long>> adj_list;

int main() {
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        adj_list.push_back({});
    }
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[v].push_back(u);
    }

    dp[1] = 1;
    queue<pair<long long, long long>> bfs;
    bfs.push({n-1, 1<<(n-1)});
    while (!bfs.empty()) {
        auto [curr_node, curr_bitmask] = bfs.front();
        for (auto child : adj_list[curr_node]) {
            long long child_bit = 1<<child;
            if ((child_bit & curr_bitmask) == 0) {
                // cout << "ba";
                long long new_bitmask = curr_bitmask|child_bit;
                bfs.push(make_pair(child, new_bitmask));
                dp[new_bitmask]++;
                dp[new_bitmask] %= MODULO;
            }
        }
        bfs.pop();
    }
    cout << dp[(1 << n)-1];
    return 0;
}

