
#include <iostream>

using namespace std;

int n, k;
int consistentPairs[20][20];

int main() {
    cin >> k >> n;

    for (int i = 0; i < k; i++) {

    }

    for (int i = 0; i < k; i++) {
        int cows[n];
        for (int j = 0; j < n; j++) {
            cin >> cows[j];
        }
        for (int j = 0; j < n; j++) {
            for (int k = i+1; k < n; k++) {
                if (i == 0) {
                    consistentPairs[j][k] = (cows[j] > cows[k]) ? 1 : ((cows[j] < cows[k]) ? -1 : 0);
                    continue;
                } else if (consistentPairs[j][k] == 0) continue;

                int newPair = (cows[j] > cows[k]) ? 1 : ((cows[j] < cows[k]) ? -1 : 0);
                if (newPair != consistentPairs[j][k]) consistentPairs[j][k] = 0;
            }
        }
    }

    int count = 0;
    for (int j = 0; j < n; j++) {
        for (int k = j+1; k < n; k++) {
            count += consistentPairs[j][k] != 0;
        }
    }

    cout << count;
    // RIGHT_NOW: Understand why the output is giving 5 instead of 4.

    return 0;
}