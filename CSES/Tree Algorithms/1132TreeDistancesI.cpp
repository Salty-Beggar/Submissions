
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long int MAX_N = 200000;
long int n, maxDists[MAX_N][3];
vector<vector<long int>> adjList;

long int _solveFirst(long int index, long int prev) {
    long int curMax = 0;
    long int curMax2 = 0;
    long int curChild = -1;
    vector<long int> curChildren = adjList[index];
    for (long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        long int curDist = _solveFirst(curChildren[i], index)+1;
        if (curDist >= curMax) {
            curMax2 = curMax;
            curMax = curDist;
            curChild = curChildren[i];
        }else if (curDist > curMax2) {
            curMax2 = curDist;
        }
    }
    maxDists[index][0] = curMax;
    maxDists[index][1] = curChild;
    maxDists[index][2] = curMax2;
    return curMax;
}

void _solveSecond(long int index, long int prev) {
    vector<long int> curChildren = adjList[index];
    for (long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        long int parentDist = (curChildren[i] == maxDists[index][1]) ? maxDists[index][2] : maxDists[index][0];
        parentDist++;
        if (parentDist > maxDists[curChildren[i]][0]) {
            maxDists[curChildren[i]][2] = maxDists[curChildren[i]][0];
            maxDists[curChildren[i]][0] = parentDist;
            maxDists[curChildren[i]][1] = index;
        }else if (parentDist > maxDists[curChildren[i]][2]) {
            maxDists[curChildren[i]][2] = parentDist;
        }
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
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    _solveFirst(0, -1);
    _solveSecond(0, -1);
    for (long int i = 0; i < n; i++) {
        cout << maxDists[i][0] << " ";
    }
    return 0;
}
