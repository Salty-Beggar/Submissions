
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

const long long MAX_N = 1000;
long long n, m, c, arr[MAX_N+1], curr_weight[MAX_N], cycle_dp[MAX_N+1], mooney_dp[MAX_N+1];
vector<vector<long long>> adj_list;

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    cin >> n >> m >> c;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        adj_list.push_back({});
        curr_weight[i] = -1;
    }
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
    }

    queue<pair<long long, long long>> bfs;
    bfs.push({0, 0});
    long long ans = 0;
    for (long long i = 0; i <= MAX_N+1; i++) {
        long long curr_size = bfs.size();
        long long max_weight = -1;
        for (long long j = 0; j < curr_size; j++) {
            auto top_choice = bfs.front();
            bfs.pop();
            long long choice_index = top_choice.first;
            long long choice_weight = top_choice.second;
            if (choice_index == 0 && choice_weight > max_weight) {
                max_weight = choice_weight;
                // if (i != 0) continue;
            }
            if (choice_weight > curr_weight[choice_index]) {
                curr_weight[choice_index] = choice_weight;
                for (auto child : adj_list[choice_index]) {
                    bfs.push({child, choice_weight+arr[child]});
                }
            }
        }
        ans = max(ans, max_weight - c*i*i);
    }

    cout << ans;
}
