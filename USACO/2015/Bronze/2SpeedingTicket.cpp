
#include <iostream>
#include <cstdio>

using namespace std;

int n, m, roadSegments[100][2], bessieSegments[100][2];

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> roadSegments[i][0] >> roadSegments[i][1];
    }
    for (int i = 0; i < m; i++) {
        cin >> bessieSegments[i][0] >> bessieSegments[i][1];
    }

    int roadPointer = 0;
    int roadCum = 0;
    int bessiePointer = 0;
    int bessieCum = 0;
    int speedLimit = 0;
    while (roadPointer != n && bessiePointer != m) {
        int curRoadSeg[2] = {roadSegments[roadPointer][0], roadSegments[roadPointer][1]};
        int curBessieSeg[2] = {bessieSegments[bessiePointer][0], bessieSegments[bessiePointer][1]};
        speedLimit = max(speedLimit, curBessieSeg[1]-curRoadSeg[1]);
        bool upBessie = bessieCum+curBessieSeg[0] <= roadCum+curRoadSeg[0];
        bool upRoad = roadCum+curRoadSeg[0] <= bessieCum+curBessieSeg[0];
        if (upBessie) {
            bessiePointer++;
            bessieCum += curBessieSeg[0];
        }
        if (upRoad) {
            roadPointer++;
            roadCum += curRoadSeg[0];
        } 
    }

    cout << speedLimit;

    return 0;
}