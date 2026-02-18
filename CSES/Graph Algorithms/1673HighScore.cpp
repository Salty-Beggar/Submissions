
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int MAX_N = 2500;
int n, m;
vector<vector<pair<int, long int>>> adjList;
vector<vector<pair<int, long int>>> adjListInv;
long long dist[MAX_N];
bool visited[MAX_N];
bool valid[MAX_N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        adjList.push_back({});
        adjListInv.push_back({});
    }
    dist[0] = 0;
    visited[0] = true;

    for (int i = 0; i < m; i++) {
        int u, v;
        long int w;
        cin >> u >> v >> w;
        u--;
        v--;
        adjList[u].push_back({v, w});
        adjListInv[v].push_back({u, w});
    }

    queue<int> bfs;
    bfs.push(n-1);
    while (!bfs.empty()) {
        int curItem = bfs.front();
        bfs.pop();
        if (valid[curItem]) continue;
        valid[curItem] = true;
        vector<pair<int, long int>> curAdj = adjListInv[curItem];
        for (int k = 0; k < curAdj.size(); k++) {
            pair<int, long int> child = curAdj[k];
            bfs.push(child.first);
        }
    }

    bfs.push(0);
    bool changed = false;
    for (int i = 0; i < n; i++) {
        int curSize = bfs.size();
        changed = false;
        for (int j = 0; j < curSize; j++) {
            int curItem = bfs.front();
            bfs.pop();
            vector<pair<int, long int>> curAdj = adjList[curItem];
            for (int k = 0; k < curAdj.size(); k++) {
                pair<int, long int> child = curAdj[k];
                if (!valid[child.first]) continue;
                if (!visited[child.first] || dist[child.first] < dist[curItem]+child.second) {
                    visited[child.first] = true;
                    dist[child.first] = dist[curItem]+child.second;
                    bfs.push(child.first);
                    changed = true;
                }
            }
        }
    }

    cout << ((changed) ? -1 : dist[n-1]);

    return 0;
}