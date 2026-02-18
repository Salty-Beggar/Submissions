#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

const long int MAX_N = 100000;
const long int MAX_M = 200000;
long int n, m;
bool traversedNodes[MAX_N];
vector<vector<long int>> adjVector;

int main() {
    cin >> n >> m;
    for (long int i = 0; i < n; i++) {
        adjVector.push_back({});
    }
    for (long int i = 0; i < m; i++) {
        long int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjVector[u].push_back(v);
        adjVector[v].push_back(u);
    }
    queue<long int> dfs;
    vector<long int> unionsVector;
    for (long int i = 0; i < n; i++) {
        if (!traversedNodes[i]) {
            dfs.push(i);
            unionsVector.push_back(i);
            while (!dfs.empty()) {
                long int curNode = dfs.front();
                dfs.pop();
                if (traversedNodes[curNode]) continue;
                traversedNodes[curNode] = true;
                for (long int k = 0; k < adjVector[curNode].size(); k++) {
                    if (!traversedNodes[adjVector[curNode][k]])
                        dfs.push(adjVector[curNode][k]);
                }
            }
        }
    }
    int k = unionsVector.size();
    cout << k-1 << "\n";
    for (long int i = 1; i < k; i++) {
        cout << unionsVector[i-1]+1 << " " << unionsVector[i]+1 << "\n";
    }
}
