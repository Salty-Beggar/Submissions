
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const long int MAX_N = 100000;
long int n, m;
short teams[MAX_N];
vector<vector<long int>> adjList;

int main() {
    cin >> n >> m;
    for (long int i = 0; i < n; i++) {
        adjList.push_back({});
    }
    for (long int i = 0; i < m; i++) {
        long int u, v;
        cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    queue<long int> dfs;
    for (long int i = 0; i < n; i++) {
        if (teams[i] == 0) {
            dfs.push(i);
            short curTeam = 2;
            while (!dfs.empty()) {
                curTeam = (curTeam == 1) ? 2 : 1;
                long int curSize = dfs.size();
                for (long int j = 0; j < curSize; j++) {
                    long int node = dfs.front();
                    dfs.pop();
                    if (teams[node] == 0) {
                        teams[node] = curTeam;
                        for (long int k = 0; k < adjList[node].size(); k++)
                            dfs.push(adjList[node][k]);
                    }else if (teams[node] != curTeam) {
                        cout << "IMPOSSIBLE";
                        return 0;
                    }
                }
            }
        }
    }

    for (long int i = 0; i < n; i++) {
        cout << teams[i] << " ";
    }
}