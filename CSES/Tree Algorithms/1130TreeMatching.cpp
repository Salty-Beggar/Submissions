
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const long long int MAX_N = 200000;

long long int n, treeDP[MAX_N][2]; // 0 - Supposing the current node is edged; 1 - Supposing it's not.
vector<vector<long long int>> adjList;

void _solve(long long int index, long long int prev) {
    vector<long long int> curChildren = adjList[index];
    treeDP[index][0] = 0;
    treeDP[index][1] = 0;
    //cout << "DAMN ";
    if (prev != -1 && curChildren.size() == 1) {
        return;
    }
    for (long long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        _solve(curChildren[i], index);
    }
    long long int fewestLoss = -1; // The smallest value edged node, relative to non edged node. It's -1 if at least one node has greater value when it's not edged.
    long long int curMaxSum = 0;
    for (long long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        curMaxSum += max(treeDP[curChildren[i]][0], treeDP[curChildren[i]][1]);
        if (treeDP[curChildren[i]][1] >= treeDP[curChildren[i]][0]) {
            fewestLoss = 0;
        }else {
            fewestLoss = (fewestLoss == -1) ? (treeDP[curChildren[i]][0] - treeDP[curChildren[i]][1]) : min(fewestLoss, (treeDP[curChildren[i]][0] - treeDP[curChildren[i]][1]));
        }
    }
    treeDP[index][0] = curMaxSum+1;
    treeDP[index][0] -= fewestLoss;
    treeDP[index][1] = curMaxSum;
}

int main() {
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (long long int i = 0; i < n; i++) {
        adjList.push_back({});
        treeDP[i][0] = 0;
        treeDP[i][1] = 0;
    }
    for (long long int i = 0; i < n-1; i++) {
        long long int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    _solve(0, -1);

    cout << (max(treeDP[0][0], treeDP[0][1]));

    return 0;
}