
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <tuple>
#include <string>

using namespace std;

int n, curMaxMilk, curMilkRate[3];
vector<tuple<int, int, int>> changes;

int _cow(string cow) {
    switch (cow[0]) {
        case 'M': return 0;
        case 'E': return 1;
    }
    return 2;
}

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    curMaxMilk = 7;
    for (int i = 0; i < 3; i++) curMilkRate[i] = 7;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int day, cow, milk;
        string cowStr;
        cin >> day >> cowStr >> milk;
        cow = _cow(cowStr);
        changes.push_back({day, cow, milk});
    }

    int pictures = 0;
    sort(changes.begin(), changes.end());
    for (int i = 0; i < n; i++) {
        tuple<int, int, int> curChange = changes[i];
        bool curBest[3];
        for (int i = 0; i < 3; i++) curBest[i] = curMilkRate[i] == curMaxMilk;
        curMilkRate[get<1>(curChange)] += get<2>(curChange);

        curMaxMilk = 0;
        for (int i = 0; i < 3; i++) {
            curMaxMilk = max(curMaxMilk, curMilkRate[i]);
        }

        for (int i = 0; i < 3; i++) {
            if (curBest[i] ^ (curMilkRate[i] == curMaxMilk)) {
                pictures++;
                break;
            }
        }
    }

    cout << pictures;
}