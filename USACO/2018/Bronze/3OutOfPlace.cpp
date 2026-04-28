
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 100;
int n;
vector<long int> orderedCows;

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    cin >> n;
    long int leftedCow = -1, rightedCow = -1;
    for (int i = 0; i < n; i++) {
        long int x;
        cin >> x;
        if (empty(orderedCows) || orderedCows.back() != x) {
            orderedCows.push_back(x);
        }
    }
    int n = orderedCows.size();

    vector<long int> copyCows;
    int swaps = 0;
    int dir = 1;
    for (int i = 0; i < n-1 && i >= 0; i += dir) {
        // copyCows.push_back(orderedCows[i]);
        if (orderedCows[i] > orderedCows[i+1]) {
            // cout << orderedCows[i] << " " << orderedCows[i+1] << " " << orderedCows[i-1] << "::\n";
            if (i != 0 && orderedCows[i+1] < orderedCows[i-1]) {
                dir = -1;
            }
            swaps++;
            int _swap = orderedCows[i];
            orderedCows[i] = orderedCows[i+1];
            orderedCows[i+1] = _swap;
        }
    }
    cout << swaps;
}