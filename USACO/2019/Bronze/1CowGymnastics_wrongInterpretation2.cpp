
#include <cstdio>
#include <iostream>

using namespace std;

int n, k;
int consistentPairs[20][20];

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    cin >> k >> n;
    int cows[k][n];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cows[i][j];
        }
    }

    int count = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a+1; b < n; b++) {
            bool isConsistent = true;
            int dir = cows[0][a] < cows[0][b];
            for (int i = 0; i < k; i++) {
                if (cows[i][a] == cows[i][b] || (cows[i][a] < cows[i][b]) != dir) {
                    isConsistent = false;
                    break;
                }
            }
            count += isConsistent;
        }
    }

    /* for (int i = 0; i < k; i++) {
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
    } */

    cout << count;

    return 0;
}


