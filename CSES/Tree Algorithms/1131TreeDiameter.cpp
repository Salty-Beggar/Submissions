
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
long int n;
vector<vector<long int>> adjList;

// First is distance/depth, second is diameter.
pair<long int, long int> _solve(long int index, long int prev) {
    vector<long int> curChildren = adjList[index];
    if ((prev == -1 && curChildren.size() == 0) || (prev != -1 && curChildren.size() == 1)) {
        return {0, 0};
    }
    long int maxDiameter = 0;
    long int maxDist1 = 0;
    long int maxDist2 = 0;
    for (long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        pair<long int, long int> curPair = _solve(curChildren[i], index);
        maxDiameter = max(maxDiameter, curPair.second);
        long int curDist = curPair.first+1;
        if (curDist >= maxDist1) {
            maxDist2 = maxDist1;
            maxDist1 = curDist;
        }else if (curDist > maxDist2) {
            maxDist2 = curDist;
        }
    }
    return {maxDist1, max(maxDiameter, maxDist1+maxDist2)};
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
    cout << _solve(0, -1).second;
}
