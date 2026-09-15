
#include <iostream>
#include <vector>
using namespace std;

const long long MAX_N = 18;
long long n, m, dp[1<<MAX_N][2];
// vector<vector<long long>> adj_list;
bool adj_list[MAX_N][MAX_N];

int main() {
    cin >> n >> m;
    // for (long long i = 0; i < n; i++) {
    //     adj_list.push_back({});
    // }
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        // adj_list[u].push_back(v);
        // adj_list[v].push_back(u);
        adj_list[u][v] = true;
        adj_list[v][u] = true;
    }
    for (long long mask = 1; mask < (1ll<<n); mask++) {
        dp[mask][0] = 1;
        long long first_node, second_node;
        long long curr_subset_size = 0;
        for (long long i = 0; i < n ; i++) {
            long long curr_bit = 1<<i;
            if ((mask & curr_bit) == 0) continue;
            second_node = first_node;
            first_node = i;
            curr_subset_size++;
            long long prev_subset = mask^curr_bit;
            if (dp[prev_subset][0] != 1) dp[mask][0] = n;
        }
        if (curr_subset_size == 1) {
            dp[mask][0] = 1;
            continue;
        }else if (curr_subset_size == 2) {
            dp[mask][0] = (adj_list[first_node][second_node]) ? 1 : 2;
            continue;
        }
        if (dp[mask][0] == 1) continue;
        for (long long submask = ((submask-1) & mask); submask > 0; submask = ((submask-1) & mask)) {
            long long curr_subset = mask^submask;
            long long other_subset = mask^curr_subset;
            dp[mask][0] = min(
                dp[mask][0],
                dp[curr_subset][0]+dp[other_subset][0]
            );
        }
    }
    cout << dp[(1<<n)-1][0];
    return 0;
}