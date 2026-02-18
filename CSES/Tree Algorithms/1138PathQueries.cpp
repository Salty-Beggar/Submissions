
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long int MAX_N = 200000;
long int n, q, values[MAX_N], rangePrevs[MAX_N], orderIndex[MAX_N][2]; /*
* rangePrevs[i][0] - pre-order
* rangePrevs[i][1] - post-order
*/
long long int biTree[MAX_N][2]; /*
* Same for the binary indexed tree.
*/
vector<vector<long int>> adjList;

// Binary indexed tree
void update(long int index, long int value, long int order) {
    for (index++; index <= n; index += (index&(-index))) {
        biTree[index-1][order] += value;
    }
}
long long int query(long int index, long int order) {
    long long int sum = 0;
    for (index++; index > 0; index -= (index&(-index))) {
        sum += biTree[index-1][order];
    }
    return sum;
}

// Ordering tree
long int postOrderIndex = 0;
long int preOrderIndex = 0;
void _bothOrders(long int index, long int prev, long int rangePrev) {
    rangePrevs[index] = rangePrev;
    orderIndex[index][0] = preOrderIndex++;
    vector<long int> curChildren = adjList[index];
    long int prevChild = -1;
    for (long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        if (prevChild == -1) _bothOrders(curChildren[i], index, rangePrev);
        else _bothOrders(curChildren[i], index, orderIndex[prevChild][1]);
        prevChild = curChildren[i];
    }
    
    orderIndex[index][1] = postOrderIndex++;
}

int main() {
    cin >> n >> q;
    
    for (long int i = 0; i < n; i++) { // Initializing adj list & reading value input.
        cin >> values[i];
        adjList.push_back({});
    }

    for (long int i = 0; i < n-1; i++) { // Reading tree's edges.
        long int u, v;
        cin >> u >> v; u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    _bothOrders(0, -1, -1);

    for (long int i = 0; i < n; i++) { // Initializing binary indexed trees.
        update(orderIndex[i][0], values[i], 0);
        update(orderIndex[i][1], values[i], 1);
    }

    for (long int i = 0; i < q; i++) { // Reading queries.
        short int type;
        cin >> type;
        if (type == 1) { // Update query
            long int s, x;
            cin >> s >> x;
            s--;
            long int _diff = x - values[s];
            values[s] = x;
            update(orderIndex[s][0], _diff, 0);
            update(orderIndex[s][1], _diff, 1);
        }else { // Check query
            long int s;
            cin >> s;
            s--;
            if (rangePrevs[s] == -1) cout << (query(orderIndex[s][0], 0)) << "\n";
            else cout << (query(orderIndex[s][0], 0) - query(rangePrevs[s], 1)) << "\n";
        }
    }

}