
#include <iostream>
#include <queue>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n, inputArr[MAX_N];
deque<long int> monotonicQueue;

// Disjoint Set
long int disjointSet[MAX_N][3]; /*
0 - Monarch
1 - Weight
2 - Size
*/
long int find(long int u) {
    if (disjointSet[u][0] == u) return u;
    long int monarch = find(disjointSet[u][0]);
    disjointSet[u][0] = monarch;
    return monarch;
}
bool isJoined(long int u, long int v) {
    if (find(u) == find(v)) return true;
}
void join(long int u, long int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (disjointSet[u][1] > disjointSet[v][1]) { // u is supposed to be the lighter one.
        long int _u = u;
        u = v;
        v = _u;
    }
    if (disjointSet[u][1] == disjointSet[v][1]) disjointSet[v][1]++;
    disjointSet[v][2] += disjointSet[u][2];
    disjointSet[u][0] = v;
}

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
            inputArr[i] = x-1;
            disjointSet[i][0] = i;
            disjointSet[i][1] = 0;
            disjointSet[i][2] = 1;
        }
    
        // while (!monotonicQueue.empty()) monotonicQueue.pop();
        // monotonicQueue.push(inputArr[n-1]);
        // for (long int i = n-2; i >= 0; i--) {
        //     long int curItem = inputArr[i];
        //     if (monotonicQueue.size() == 1 && monotonicQueue.top() > curItem) {
        //         join(curItem, monotonicQueue.top());
        //         continue;
        //     }
        //     while (!monotonicQueue.empty() && monotonicQueue.top() > curItem) {
        //         join(curItem, monotonicQueue.top());
        //         monotonicQueue.pop();
        //     }
        //     monotonicQueue.push(curItem);
        // }
        while (!monotonicQueue.empty()) monotonicQueue.pop_front();
        monotonicQueue.push_front(inputArr[n-1]);
        for (long int i = n-2; i >= 0; i--) {
            long int curItem = inputArr[i];
            if (curItem > monotonicQueue.front()) monotonicQueue.push_front(curItem);
            bool addToDeque = true;
            while (curItem < monotonicQueue.back()) {
                join(curItem, monotonicQueue.back());
                if (monotonicQueue.size() == 1) {
                    addToDeque = false;
                    break;
                }
                monotonicQueue.pop_back();
            }
            if (addToDeque) monotonicQueue.push_back(curItem);
        }
        if (disjointSet[find(disjointSet[0][0])][2] == n) cout << "Yes\n";
        else cout << "No\n";
    }
}