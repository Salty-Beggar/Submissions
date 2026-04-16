
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;
long int b;
vector<pair<long int, long int>> xOrderedPos, yOrderedPos;

int main() {
    // freopen("balancing.in", "r", stdin);
    // freopen("balancing.out", "w", stdout);

    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        long int x, y;
        cin >> x >> y;
        x--; y--;
        xOrderedPos.push_back({x, y});
        yOrderedPos.push_back({x, y});
    }
    sort(xOrderedPos.begin(), xOrderedPos.end());
    sort(yOrderedPos.begin(), yOrderedPos.end(), [](const pair<long int, long int> a, const pair<long int, long int> b) { return a.second < b.second; });

    int minMaxCows = 100;
    for (int i = 0; i < n; i++) {
        if (i != 0 && xOrderedPos[i-1].first == xOrderedPos[i].first) {
            i++;
            if (i == n) break;
        }
        pair<long int, long int> curXPos = xOrderedPos[i];
        int leftAmount = i;
        int rightAmount = n-i; 
        int curGroup = 1;
        for (int j = 0; j < n; j++) {
            if (j != n-1 && yOrderedPos[j].second == yOrderedPos[j+1].second) {
                curGroup++;
                continue;
            }
            pair<long int, long int> curYPos = yOrderedPos[j];
            if (i == 0 || curYPos.first >= xOrderedPos[i-1].first) {
                rightAmount -= curGroup;
                // minMaxCows = min(minMaxCows, max( max(leftAmount, rightAmount), max(i-leftAmount, n-i-rightAmount) ));
            }else {
                leftAmount -= curGroup;
            }
            minMaxCows = min(minMaxCows, max( max(leftAmount, rightAmount), max(i-leftAmount, n-i-rightAmount) ));
            curGroup = 1;
        }
    }
    cout << minMaxCows;
}