
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long int MAX_N = 200000, MAX_M = 200000;
long int n, m, k, nodeTypes[MAX_N], typeDists[MAX_N];
bool visitedNodes[MAX_N];
vector<vector<long int>> adjList;
queue<long int> bfs;

int main() {
    cin >> n >> m >> k;
    for (long int i = 0; i < n; i++) {
        cin >> nodeTypes[i];
        nodeTypes[i]--;
        adjList.push_back({});
    }

    for (long int i = 0; i < m; i++) {
        long int u, v;
        cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    long int depth = 0;
    bfs.push(0);
    while (!bfs.empty()) {
        long int curSize = bfs.size();
        for (long int i = 0; i < curSize; i++) {
            long int curNode = bfs.front();
            long int curType = nodeTypes[curNode];
            bfs.pop();
            if (visitedNodes[curNode]) continue;
            visitedNodes[curNode] = true;
            typeDists[curType] = depth;
            for (long int j = 0; j < adjList[curNode].size(); j++) {
                long int curChild = adjList[curNode][j];
                bfs.push(curChild);
            }
        }
        depth++;
    }
    for (long int i = 0; i < k; i++) {
        cout << typeDists[i] << " ";
    }
}
