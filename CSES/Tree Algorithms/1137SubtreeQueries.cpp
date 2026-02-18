
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const long int MAX_N = 200000;
long int n, q, values[MAX_N], parent[MAX_N][2], treeMap[MAX_N]; /*
* treeMap's index refers to a node, whereas the value refers to its post-order traversal position.
* parent's second index refers to the node that includes the part of the sum that's subtracted from that node's sum, in post-order traversal index.
*/
long long int biTree[MAX_N];
vector<vector<long int>> adjList;

// Binary indexed tree
void update(long int index, long int value) {
    for (index++; index <= n; index += (index&(-index))) {
        biTree[index-1] += value;
    }
}

long long int query(long int index) {
    long long int sum = 0;
    for (index++; index > 0; index -= (index&(-index))) {
        sum += biTree[index-1];
    }
    return sum;
}

// Tree
long int treeIndex = 0;
void _build(long int index, long int prev, long int special) {
    // parent[index][0] = prev;
    parent[index][1] = special;

    vector<long int> curChildren = adjList[index];

    long int _index = 0;
    long int _prev = -1;
    for (long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        if (_index == 0) _build(curChildren[i], index, special);
        else _build(curChildren[i], index, treeMap[curChildren[_prev]]);
        _prev = i;
        _index++;
    }

    treeMap[index] = treeIndex;
    treeIndex++;
}

int main() {
    cin >> n >> q;

    for (long int i = 0; i < n; i++) { // Reads value inputs.
        cin >> values[i];
        adjList.push_back({});
    }

    for (long int i = 0; i < n-1; i++) { // Reads edge inputs.
        long int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    _build(0, -1, -1);

    for (long int i = 0; i < n; i++) { // Defining BI tree's initial values.
        update(treeMap[i], values[i]);
    }
    
    // for (long int i = 0; i < n; i++) {
    //     cout << query(i) << " " << treeMap[i] << " | ";
    // }
    // cout << "\n\n";

    for (long int i = 0; i < q; i++) { // Reading queries.
        int type;
        cin >> type;
        if (type == 1) { // Update query
            long int k, x;
            cin >> k >> x; k--;
            long int _diff = x - values[k];
            values[k] = x;
            update(treeMap[k], _diff);
            /*for (long int i = 0; i < n; i++) {
                cout << query(i) << " ";
            }
            cout << "\n\n";*/
        }else { // Check query
            long int s;
            cin >> s; s--;
            if (parent[s][1] == -1) cout << query(treeMap[s]);
            else cout << query(treeMap[s]) - query(parent[s][1]);
            cout << "\n";
        }
    }

}