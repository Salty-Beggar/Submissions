
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 100;
int n;
vector<long int> orderedCows;

int main() {
    // freopen("outofplace.in", "r", stdin);
    // freopen("outofplace.out", "w", stdout);

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

    if (orderedCows[0] > orderedCows[1])
        leftedCow = 0;
    else if (orderedCows[n-1] < orderedCows[n-2]) 
        rightedCow = n-1;
    else for (int i = 1; i < n-1; i++) {
        if (orderedCows[i] > orderedCows[i+1] && orderedCows[i] > orderedCows[i-1]) {
            leftedCow = i;
            break;
        }else if (orderedCows[i] < orderedCows[i+1] && orderedCows[i] < orderedCows[i-1]) {
            rightedCow = i;
            break;
        }
    }
    if (leftedCow != -1) {
        for (int i = leftedCow+1; i < n; i++) {
            if (orderedCows[i] >= orderedCows[leftedCow]) {
                cout << i-leftedCow-1;
                return 0;
            }
        }
        cout << n-leftedCow-1 << "\n";
    }else {
        for (int i = 0; i < rightedCow; i++) {
            if (orderedCows[i] >= orderedCows[rightedCow]) {
                cout << rightedCow-i;
                return 0;
            }
        }
        cout << rightedCow-n-1 << "\n";
    }
    return 0;
}