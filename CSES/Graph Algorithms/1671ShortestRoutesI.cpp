
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

typedef pair<long int, unsigned long long int> Choice;
const long int MAX_N = 100000;
long int n, m;
unsigned long long int shortestRoutes[MAX_N];
vector<vector<pair<long int, long int>>> adjList;

class Compare {
    public:
        bool operator() (Choice a, Choice b) {
            return a.second > b.second;
        }
};

int main() {
    cin >> n >> m;
    for (long int i = 0; i < n; i++) {
        adjList.push_back({});
        shortestRoutes[i] = 18446744073709551615;
    }
    for (long int i = 0; i < m; i++) {
        long int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adjList[u].push_back({v, w});
    }

    shortestRoutes[0] = 0;
    priority_queue<Choice, vector<Choice>, Compare> choicePQueue;
    choicePQueue.push({0, 0});

    while (!choicePQueue.empty()) {
        Choice curChoice = choicePQueue.top();
        choicePQueue.pop();
        if (shortestRoutes[curChoice.first] < curChoice.second) continue;
        vector<pair<long int, long int>> curAdjList = adjList[curChoice.first];
        for (long int i = 0; i < curAdjList.size(); i++) {
            pair<long int, long int> curNode = curAdjList[i];
            if (shortestRoutes[curChoice.first]+curNode.second < shortestRoutes[curNode.first]) {
                shortestRoutes[curNode.first] = shortestRoutes[curChoice.first]+curNode.second;
                choicePQueue.push({curNode.first, shortestRoutes[curChoice.first]+curNode.second});
            }
        }
    }

    for (long int i = 0; i < n; i++) {
        cout << shortestRoutes[i] << " ";
    }

    return 0;
}