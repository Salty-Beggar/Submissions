
#include <iostream>

using namespace std;

int n, k;
int consistentPairs[20][20];

int main() {
    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        int cows[n];
        for (int j = 0; j < n; j++) {
            cin >> cows[j];
        }
        for (int j = 0; j < n; j++) {
            for (int q = j+1; q < n; q++) {
                if (i == 0) {
                    consistentPairs[j][q] = (cows[j] > cows[q]) ? 1 : ((cows[j] < cows[q]) ? -1 : 0);
                    continue;
                } else if (consistentPairs[j][q] == 0) continue;

                int newPair = (cows[j] > cows[q]) ? 1 : ((cows[j] < cows[q]) ? -1 : 0);
                if (newPair != consistentPairs[j][q]) consistentPairs[j][q] = 0;
            }
        }
    }

    int count = 0;
    for (int j = 0; j < n; j++) {
        for (int q = j+1; q < n; q++) {
            count += consistentPairs[j][q] != 0;
        }
    }

    cout << count;
    // RIGHT_NOW: Understand why the output is giving 5 instead of 4.

    return 0;
}