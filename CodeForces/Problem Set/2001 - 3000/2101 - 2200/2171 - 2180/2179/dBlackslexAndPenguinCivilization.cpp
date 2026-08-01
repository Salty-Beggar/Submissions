
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

int t, n;

int popCount(int a) {
    int count = 0;
    for (int i = 0; i < 16; i++) {
        if (a&(1<<i) != 0) count++;
    }
    return count;
}

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> choicePQueues[17];
        for (int i = 0; i < pow(2, n); i++) {
            int earliestBit = 16;
            for (int j = 0; j < 16; j++) {
                if (((1<<j) & i) == 0) {
                    earliestBit = j;
                    break;
                }
            }
            choicePQueues[earliestBit].push(i);
        }
        for (int i = 16; i >= 0; i--) {
            while (!choicePQueues[i].empty()) {
                cout << choicePQueues[i].top() << " ";
                choicePQueues[i].pop();
            }
        }
        cout << "\n";
    }
    return 0;
}
