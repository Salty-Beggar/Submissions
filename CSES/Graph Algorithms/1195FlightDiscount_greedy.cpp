
// The greedy approach of considering each node's weight while automatically having the heaviest node as the discounted one, leads into not considering certain
// paths whose optimal discount only happens in a later node.

#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<long int, long long int> path;

const long int MAX_N = 100000;
long int n, m;
long long int dist[MAX_N][2];
vector<vector<path>> adjList;

struct node {
    long int index;
    long long int totalW;
    long long int discount;
    /*node(long int _index, long long int _totalW, long long int _discount) {

    }*/
};

class comp {
    public:
        bool operator()(node a, node b) {
            return a.totalW-(a.discount+1)/2 > b.totalW-(b.discount+1)/2;
        }
};

int main() {

    cin >> n >> m;
    for (long int i = 0; i < n; i++) {
        adjList.push_back({});
        dist[i][0] = -1;
    }

    for (long int i = 0; i < m; i++) {
        long int u, v;
        long long int w;
        cin >> u >> v >> w;
        u--;
        v--;
        adjList[u].push_back({v, w});
    }

    priority_queue<node, vector<node>, comp> nodePQueue;
    dist[0][0] = 0;
    dist[0][0] = 0;
    nodePQueue.push({0, 0, 0});

    while (!nodePQueue.empty()) {
        node curNode = nodePQueue.top();
        nodePQueue.pop();
        if (dist[curNode.index][0] != curNode.totalW || dist[curNode.index][1] != curNode.discount) 
            continue;
        vector<path> curAdjList = adjList[curNode.index];
        for (long int i = 0; i < curAdjList.size(); i++) {
            path child = curAdjList[i];
            long long int curDiscount = max(curNode.discount, child.second);
            bool replaces = curNode.totalW+child.second - (curDiscount+1)/2 < dist[child.first][0]-(dist[child.first][1]+1)/2;
            if (curNode.totalW+child.second - (curDiscount+1)/2 == dist[child.first][0]-(dist[child.first][1]+1)/2)
                replaces = curNode.discount < dist[child.first][1];
            if (dist[child.first][0] == -1 || replaces) {
                dist[child.first][0] = curNode.totalW+child.second;
                dist[child.first][1] = curDiscount;
                nodePQueue.push({child.first, curNode.totalW+child.second, curDiscount});
            }
        }
    }

    cout << dist[n-1][0] - (dist[n-1][1]+1)/2;

    return 0;
}