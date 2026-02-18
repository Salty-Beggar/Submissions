
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n, arr[MAX_N], costs[MAX_N], nexts[MAX_N], prevs[MAX_N]; /*
    costs[i] - The cost to merge i'th item with its next one.
*/
bool removedNode[MAX_N];

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        priority_queue<pair<long int, long int>, vector<pair<long int, long int>>, greater<pair<long int, long int>>> choicePQueue;
        /*
            First - The cost of the operation
            Second - The sooner node of the operation
        */
        for (long int i = 0; i < n; i++) {
            cin >> arr[i];
            nexts[i] = (i == n-1) ? 0 : i+1;
            prevs[i] = (i == 0) ? n-1 : i-1;
            removedNode[i] = false;
        }
        for (long int i = 0; i < n; i++) {
            costs[i] = max(arr[i], arr[nexts[i]]);
            choicePQueue.push({costs[i], i});
        }
        long long int totalCost = 0;
        long int operationAmount = 0;
        while (operationAmount != n-1) {
            pair<long int, long int> curChoice = choicePQueue.top();
            long int curCost = curChoice.first;
            long int curNode = curChoice.second;
            choicePQueue.pop();
            if (costs[curChoice.second] != curChoice.first || removedNode[curChoice.second]) continue;
            totalCost += curChoice.first;
            operationAmount++;
            if (costs[prevs[curNode]] < arr[nexts[curNode]]) {
                costs[prevs[curNode]] = arr[nexts[curNode]];
                choicePQueue.push({costs[prevs[curNode]], prevs[curNode]});
            }
            nexts[prevs[curNode]] = nexts[curNode];
            prevs[nexts[curNode]] = prevs[curNode];
            removedNode[curNode] = true;
        }
        cout << totalCost << "\n";
    }
}
