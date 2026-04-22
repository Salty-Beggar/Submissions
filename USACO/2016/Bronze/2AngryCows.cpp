
#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long int x;
vector<long int> bales;
stack<pair<long int, int>> curSoonBlows, curLateBlows;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        long int x;
        cin >> x;
        bales.push_back(x);
    }
    sort(bales.begin(), bales.end());

    /* curSoonBlows.push({bales[0], 1}); */

    pair<long int, int> soonestBlow = {bales[0], 1};
    int maxBlows = 1;
    int curBlows = 1;
    for (int i = 1; i < n; i++) {
        int curRadius = 1;
        long int curBale = bales[i];
        if (soonestBlow.first+soonestBlow.second <= curBale) {
            
        }
    }
}
