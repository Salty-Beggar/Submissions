
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, subTreeSizes[100];
int ans = -1;
bool visited[100];
vector<vector<int>> adjList;

int _traverse(int i) {
    subTreeSizes[i] = 1;
    visited[i] = true;
    for (int child : adjList[i]) {
        if (visited[child]) subTreeSizes[i] += subTreeSizes[child];
        else subTreeSizes[i] += _traverse(child);
    }
    if (subTreeSizes[i] == n) ans = i;
    return subTreeSizes[i];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        adjList.push_back({});
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            _traverse(i);
        }
    }

    cout << (ans == -1) ? -1 : ans+1;
}