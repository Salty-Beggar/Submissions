
#include <iostream>
#include <vector>
using namespace std;

const long int MAX_N = 200000;
long int n, subordinates[MAX_N+1];
vector<vector<long int>> tree;

void _solve(long int index) {
    vector<long int> children = tree[index];
    for (long int i = 0; i < children.size(); i++) {
        //cout << children[i] << " ";
        _solve(children[i]);
        subordinates[index] += subordinates[children[i]]+1;
    }
}

int main() {
    cin >> n;
    for (long int i = 0; i < n; i++) {
        tree.push_back({});
    }
    for (long int i = 0; i < n-1; i++) {
        long int x;
        cin >> x;
        tree[x-1].push_back(i+1);
    }

    _solve(0);
    //cout << "\n";
    for (long int i = 0; i < n; i++) {
        cout << subordinates[i] << " ";
    }
}
