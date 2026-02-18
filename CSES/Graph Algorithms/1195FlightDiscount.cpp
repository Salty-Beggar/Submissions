
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<long int, long long int> path;

const long int MAX_N = 100000;
long int n, m;
long long int dist[MAX_N][2]; // 0 - No discount 1 - Has discounted
vector<vector<path>> adjList;

struct node {
    long int index;
    long long int totalW;
    bool hasDiscounted;
    /*node(long int _index, long long int _totalW, long long int _discount) {

    }*/
};

class comp {
    public:
        bool operator()(node a, node b) {
            return a.totalW > b.totalW;
        }
};

int main() {
    cin >> n >> m;
    for (long int i = 0; i < n; i++) {
        dist[i][0] = -1;
        dist[i][1] = -1;
        adjList.push_back({});
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
    nodePQueue.push({0, 0, false});
    while (!nodePQueue.empty()) {
        node curNode = nodePQueue.top();
        nodePQueue.pop();
        if (!curNode.hasDiscounted && dist[curNode.index][0] != curNode.totalW) continue;
        if (curNode.hasDiscounted && dist[curNode.index][1] != curNode.totalW) continue;
        for (long int i = 0; i < adjList[curNode.index].size(); i++) {
            path child = adjList[curNode.index][i];
            if (!curNode.hasDiscounted) {
                if (dist[child.first][0] == -1 || curNode.totalW+child.second < dist[child.first][0]) {
                    dist[child.first][0] = curNode.totalW+child.second;
                    nodePQueue.push({child.first, dist[child.first][0], false});
                }
                if (dist[child.first][1] == -1 || curNode.totalW+child.second/2 < dist[child.first][1]) {
                    dist[child.first][1] = curNode.totalW+child.second/2;
                    nodePQueue.push({child.first, dist[child.first][1], true});
                }
            }else {
                if (dist[child.first][1] == -1 || curNode.totalW+child.second < dist[child.first][1]) {
                    dist[child.first][1] = curNode.totalW+child.second;
                    nodePQueue.push({child.first, dist[child.first][1], true});
                }
            }
        }
    }

    cout << dist[n-1][1];
    return 0;
}