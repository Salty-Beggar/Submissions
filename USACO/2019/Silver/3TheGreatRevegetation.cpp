
#include <queue>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const long long MAX_N = 100000;

long long n, m, colors[MAX_N];
vector<pair<long long, char>> adj_list[MAX_N];

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    cin >> n >> m;
    for (long long i = 0; i < m; i++) {
        char type;
        long long u, v;
        cin >> type >> u >> v;
        u--; v--;
        adj_list[u].push_back(make_pair(v, type));
        adj_list[v].push_back(make_pair(u, type));
    }
    long long cc_amount = 0;
    for (long long i = 0; i < n; i++) {
        if (colors[i] == 0) {
            cc_amount++;
            queue<long long> bfs;
            colors[i] = 1;
            bfs.push(i);
            while (!bfs.empty()) {
                long long top_node = bfs.front();
                bfs.pop();
                for (const auto& child : adj_list[top_node]) {
                    if (colors[child.first] != 0) {
                        if (child.second == 'S' && colors[child.first] != colors[top_node]) {
                            cout << "0\n";
                            return 0;
                        }
                        if (child.second == 'D' && colors[child.first] == colors[top_node]) {
                            cout << "0\n";
                            return 0;
                        }
                    }else {
                        if (child.second == 'S') {
                            colors[child.first] = colors[top_node];
                        }
                        else if (child.second == 'D') {
                            colors[child.first] = colors[top_node] == 1 ? 2 : 1;
                        }
                        bfs.push(child.first);
                    }
                }
            }
        }
    }

    cout << "1";
    for (long long i = 0; i < cc_amount; i++) cout << "0";

    return 0;
}
