
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const long int MAX_N = 200000, MAX_LOGN = 18;

long int n, q, depth[MAX_N], binLift[MAX_N][MAX_LOGN];
vector<vector<long int>> adjList;

int main() {
    cin >> n >> q;
    binLift[0][0] = -1;

    // Initializing adj list.
    for (long int i = 0; i < n; i++) {
        adjList.push_back({});
    }

    // Reading input.
    for (long int i = 1; i < n; i++) {
        cin >> binLift[i][0];
        binLift[i][0]--;
        adjList[binLift[i][0]].push_back(i);
    }

    // Implementing bin lifting
    for (long int j = 1; j < MAX_LOGN; j++) {
        for (long int i = 0; i < n; i++) {
            long int _next = binLift[i][j-1];
            if (_next == -1) binLift[i][j] = -1;
            else binLift[i][j] = binLift[_next][j-1];
        }
    }

    // Defining depth
    queue<long int> bfs;
    long int curDepth = 0;
    bfs.push(0);
    while (!bfs.empty()) {
        long int _size = bfs.size();
        for (long int i = 0; i < _size; i++) {
            long int _front = bfs.front();
            depth[_front] = curDepth;
            bfs.pop();
            for (long int j = 0; j < adjList[_front].size(); j++) {
                //cout << "a";
                bfs.push(adjList[_front][j]);
            }
        }
        curDepth++;
    }

    // Solving queries
    for (long int i = 0; i < q; i++) {
        long int a, b;
        cin >> a >> b; // 'a' has lower depth
        a--; b--;
        if (depth[a] > depth[b]) { // which means 'a' has lower depth
            long int _a = a;
            a = b;
            b = _a;
        }
        // Equalizing depth
        //cout << depth[a] << " " << depth[b] << "\n";
        
        long int _diff = depth[b]-depth[a];
        for (long int j = 0; j < MAX_LOGN; j++) {
            long int curBit = 1<<j;
            if ((curBit&_diff) != 0) {
                b = binLift[b][j];
            }
        }
        //cout << depth[a] << " " << depth[b] << "\n";
        for (long int j = MAX_LOGN-1; j >= 0; j--) {
            if (binLift[b][j] != binLift[a][j]) {
                b = binLift[b][j];
                a = binLift[a][j];
            }
        }
        cout << ((a == b) ? a+1 : binLift[a][0]+1) << "\n";
    }
}
