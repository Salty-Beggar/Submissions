
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long MAX_N = 20, MODULO = 1000000007;
long long n, m, dp[1ll << MAX_N][MAX_N], ans;
vector<vector<long long>> adj_list;

int main() {
    cin >> n >> m;
    for (long long i = 0; i < (1ll<<n); i++) {
        for (long long j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    for (long long i = 0; i < n; i++) {
        adj_list.push_back({});
    }
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
    }

    dp[1][0] = 1;
    queue<pair<long long, long long>> bfs;
    bfs.push({0, 1});

    while (!bfs.empty()) {
        auto [curr_node, curr_bitmask] = bfs.front();
        for (auto child : adj_list[curr_node]) {
            long long child_bit = 1ll<<child;
            long long new_bitmask = curr_bitmask|child_bit;
            if (curr_bitmask != new_bitmask) {
                // if (child == n-1 && new_bitmask != (1<<n)-1) continue;
                if (dp[new_bitmask][child] != -1) {
                    dp[new_bitmask][child] += dp[curr_bitmask][curr_node];
                    dp[new_bitmask][child] %= MODULO;
                }else {
                    dp[new_bitmask][child] = dp[curr_bitmask][curr_node];
                    bfs.push(make_pair(child, new_bitmask));
                }
                // cout << "ba";
            }
        }
        bfs.pop();
    }

    cout << dp[(1ll<<n)-1][n-1];
    return 0;
}
