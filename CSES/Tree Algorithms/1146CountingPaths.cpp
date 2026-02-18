
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long int MAX_N = 200000, MAX_LOGN = 18;
long int n, m, binLift[MAX_N][MAX_LOGN], depth[MAX_N], pathAmntPerNode[MAX_N];
vector<vector<long int>> adjList;
vector<long int> startingPathsPerNode[MAX_N];//, nodePerDepth[MAX_N];
priority_queue<long int, vector<long int>, greater<>> curPathsPerNode[MAX_N];

void _solve(long int index, long int prev) {
    vector<long int> curChildren = adjList[index];
    for (long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        _solve(curChildren[i], index);
    }

    for (long int i = 0; i < startingPathsPerNode[index].size(); i++) {
        curPathsPerNode[index].push(startingPathsPerNode[index][i]);
    }
    while (curPathsPerNode[index].top() > depth[index]) {
        curPathsPerNode[index].pop();
    }
    curPathsPerNode[prev] = curPathsPerNode[index];
}

void _setPrevs(long int index, long int prev, long int _depth) {
    binLift[index][0] = prev;
    depth[index] = _depth;
    //nodePerDepth[_depth].push_back(index);
    vector<long int> curChildren = adjList[index];
    for (long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        _setPrevs(curChildren[i], index, _depth+1);
    }
}

int main() {
    cin >> n >> m;
    for (long int i = 0; i < n; i++) { // Initializing adj list
        adjList.push_back({});
    }

    for (long int i = 0; i < n-1; i++) { // Reading input for adj list
        long int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    _setPrevs(0, -1, 0);

    for (long int j = 1; j < MAX_LOGN; j++) { // Binary lift implementation
        for (long int i = 0; i < n; i++) {
            long int _prev = binLift[i][j-1];
            if (_prev == -1) binLift[i][j] = -1;
            else binLift[i][j] = binLift[_prev][j-1];
        }
    }

    for (long int i = 0; i < m; i++) { // Reading input for paths and processing them
        long int a, b;
        cin >> a >> b;
        a--; b--;
        long int _a, _b;
        _a = min(a, b);
        _b = max(a, b);
        long int _diff = depth[_b]-depth[_a];
        for (long int j = MAX_LOGN-1; j >= 0; j--) {
            long int curBit = 1<<j;
            if ((_diff & curBit) != 0) {
                _b = binLift[_b][j];
            }
        }
        for (long int j = MAX_LOGN-1; j >= 0; j--) {
            if (binLift[_a][j] != binLift[_b][j]) {
                _a = binLift[_a][j];
                _b = binLift[_b][j];
            }
        }
        long int lca = (_a != _b) ? binLift[a][0] : a; 
        startingPathsPerNode[a].push_back(depth[lca]);
        startingPathsPerNode[b].push_back(depth[lca]-1);
    }

    _solve(0, -1);
}