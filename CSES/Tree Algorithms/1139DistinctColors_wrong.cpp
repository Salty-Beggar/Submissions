
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

const long int MAX_N = 200000;
long int n, colors[MAX_N], distinctColors[MAX_N];
vector<vector<long int>> adjList;
unordered_map<long int, long int> colorCount;

void add(long int color) {
    unordered_map<long int, long int>::iterator _pos = colorCount.find(color);
    if (_pos == colorCount.end())
        colorCount.insert(color, 1l);
    else
        (*_pos).second++;
}

void subtract(long int color) {
    unordered_map<long int, long int>::iterator _pos = colorCount.find(color);
    if (_pos == colorCount.end()) {
        
    }else {
        (*_pos).second--;
        if ((*_pos).second == 0) {
            colorCount.erase(distance(colorCount.begin(), _pos));
        }
    }
}

void _solve(long int index, long int prev) {
    distinctColors[index] = colorCount.size();
    subtract(colors[index]);

    vector<long int> curChildren = adjList[index];
    for (long int i = 0; i < curChildren.size(); i++) {
        if (curChildren[i] == prev) continue;
        _solve(curChildren[i], index);
        add(colors[curChildren[i]]);
    }
}

int main() {
    cin >> n;
    for (long int i = 0; i < n; i++) {
        cin >> colors[i];
        adjList.push_back({});
        add(colors[i]);
        // RIGHT_NOW: Make sure you're dereferencing the pointer correctly.
    }
    for (long int i = 0; i < n-1; i++) {
        long int u, v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    _solve(0, -1);

    for (long int i = 0; i < n; i++) {
        cout << distinctColors[i] << " ";
    }
}