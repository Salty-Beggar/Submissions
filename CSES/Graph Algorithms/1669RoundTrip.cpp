
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const long int MAX_N = 100000;
long int n, m;
vector<vector<long int>> adjList;
long int depth[MAX_N];
typedef tuple<long int, long int, long int> stackItem;

int main() {
    cin >> n >> m;
    for (long int i = 0; i < n; i++) {
        adjList.push_back({});
    }
    for (long int i = 0; i < m; i++) {
        long int u, v;
        cin >> u >> v; u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    stack<stackItem> dfs;
    long int loopSize = 0;
    for (long int i = 0; i < n; i++) {
        if (depth[i] == 0) {
            dfs.push({i, 1, 0});
            while (!dfs.empty()) {
                stackItem &node = dfs.top();
                if (depth[get<0>(node)] != 0 && depth[get<0>(node)] != get<1>(node)) {
                    if (get<1>(node) - depth[get<0>(node)] > 2) {
                        loopSize = get<1>(node) - depth[get<0>(node)];
                        break;
                    }
                    dfs.pop();
                    continue;
                }
                depth[get<0>(node)] = get<1>(node);
                long int _index = get<2>(node);
                //cout << get<0>(node) << " " << adjList[get<0>(node)].size() << "\n";
                if (get<2>(node) == adjList[get<0>(node)].size()) {
                    dfs.pop();
                }else 
                //cout << get<0>(node) << " " << get<2>(node) << "\n";
                    dfs.push({adjList[get<0>(node)][_index], get<1>(node)+1, 0});
                get<2>(node)++;
                //cout << "\n";
            }
            if (loopSize != 0) break;
        }
    }

    if (loopSize == 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    loopSize++;
    cout << loopSize << "\n";
    
    stack<long int> order;
    
    for (long int i = 0; i < loopSize; i++) {
        order.push(get<0>(dfs.top()));
        dfs.pop();
    }
    
    for (long int i = 0; i < loopSize; i++) {
        cout << order.top()+1 << " ";
        order.pop();
    }
    
    return 0;
}
