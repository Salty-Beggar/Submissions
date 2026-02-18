
#include <iostream>
#include <vector>
using namespace std;

const long int MAX_N = 200000;
long int n;
vector<vector<long int>> adjList;
long long int dp[MAX_N][2]; // 0 - The sum of the sub tree | 1 - The edge amount in the sub tree.

void _solveFirst(long int index, long int prev) {
    vector<long int> curChildren = adjList[index];
    for (long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        _solveFirst(curChildren[i], index);
        dp[index][1] += dp[curChildren[i]][1]+1;
        dp[index][0] += dp[curChildren[i]][0];
    }
    dp[index][0] += dp[index][1];
}

void _solveSecond(long int index, long int prev) {
    vector<long int> curChildren = adjList[index];
    for (long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        dp[curChildren[i]][0] += dp[index][0]-dp[curChildren[i]][0]-dp[curChildren[i]][1]-1 + (n-1-dp[curChildren[i]][1]);
        _solveSecond(curChildren[i], index);
    }
}

int main() {
    cin >> n;
    for (long int i = 0; i < n; i++) {
        adjList.push_back({});
    }
    for (long int i = 0; i < n-1; i++) {
        long int u, v;
        cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    _solveFirst(0, -1);
    _solveSecond(0, -1);
    for (long int i = 0; i < n; i++) {
        cout << dp[i][0] << " ";
    }
    
    
    return 0;
    
}