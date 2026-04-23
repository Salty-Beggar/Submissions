
#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n, thirdCaseBlows[100][2]; /*
0 - Left to Right
1 - Right to Left
*/
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

    pair<long int, int> soonestBlow = {bales[0], 1};
    int maxBlows = 1;
    int curBlows = 1;
    for (int i = 1; i < n; i++) {
        long int curBale = bales[i];
        if (soonestBlow.first+soonestBlow.second <= curBale) {
            curBlows++;
            maxBlows = max(maxBlows, curBlows);
            soonestBlow = {curBale, curBlows};
        }else {
            curBlows = 1;
            soonestBlow = {curBale, curBlows};
        }
    }

    curBlows = 1;
    soonestBlow = {bales[n-1], 1};
    for (int i = n-2; i >= 0; i--) {
        long int curBale = bales[i];
        if (soonestBlow.first-soonestBlow.second >= curBale) {
            curBlows++;
            maxBlows = max(maxBlows, curBlows);
            soonestBlow = {curBale, curBlows};
        }else {
            curBlows = 1;
            soonestBlow = {curBale, curBlows};
        }
    }


    stack<tuple<long int, int, long int, int, int>> blowStack;
    /* 0 - Blow itself | 1 - Current radius | 2 - Start point | 3 - Overhead | 4 - Exploded bales */
    blowStack.push(make_tuple(bales[0], 1, bales[0], 0, 0));
    for (int i = 1; i < n; i++) {
        long int curBale = bales[i];
        int curRadius = 1;
        auto curTop = blowStack.top();
        if (get<2>(curTop)+1 == curBale) {
            blowStack.pop();
            if (get<3>(curTop) == 0) {
                curRadius = get<1>(curTop)+1;
                int curExplodedBales = get<4>(curTop)+1;
                while (!blowStack.empty() && get<0>(blowStack.top()) >= get<0>(curTop)-curRadius) {
                    curTop = blowStack.top();
                    curExplodedBales += get<4>(curTop)+1;
                    blowStack.pop();
                    curRadius++;
                }
                blowStack.push(make_tuple(get<0>(curTop), curRadius, curBale, curRadius-2, curExplodedBales));
                thirdCaseBlows[i][0] = curExplodedBales;
            }else {
                curRadius = get<1>(curTop)+1;
                int curExplodedBales = get<4>(curTop)+1;
                blowStack.push(make_tuple(get<0>(curTop), curRadius, curBale, get<3>(curTop)-1, curExplodedBales));
                thirdCaseBlows[i][0] = curExplodedBales;
            }
        }else {
            blowStack.push(make_tuple(curBale, 1, curBale, 0, 0));
        }
    }

    while (!blowStack.empty()) blowStack.pop();
    for (int i = 0; i < n; i++) {
        bales[i] = bales[n-1]-bales[i]+1;
    }
    reverse(bales.begin(), bales.end());
    // cout << "\n";
    blowStack.push(make_tuple(bales[0], 1, bales[0], 0, 0));
    for (int i = 1; i < n; i++) {
        long int curBale = bales[i];
        int curRadius = 1;
        auto curTop = blowStack.top();
        if (get<2>(curTop)+1 == curBale) {
            blowStack.pop();
            // cout << get<3>(curTop) << " &\n";
            if (get<3>(curTop) == 0) { // RIGHT_NOW: THis check should be based on distance
                curRadius = get<1>(curTop)+1;
                int curExplodedBales = get<4>(curTop)+1;
                while (!blowStack.empty() && get<0>(blowStack.top()) >= get<0>(curTop)-curRadius) {
                    curTop = blowStack.top();
                    curExplodedBales += get<4>(curTop)+1;
                    blowStack.pop();
                    curRadius++;
                }
                blowStack.push(make_tuple(get<0>(curTop), curRadius, curBale, curRadius-2, curExplodedBales));
                thirdCaseBlows[n-1-i][1] = curExplodedBales;
            }else {
                curRadius = get<1>(curTop)+1;
                int curExplodedBales = get<4>(curTop)+1;
                blowStack.push(make_tuple(get<0>(curTop), curRadius, curBale, get<3>(curTop)-1, curExplodedBales));
                thirdCaseBlows[n-1-i][1] = curExplodedBales;
            }
        }else {
            blowStack.push(make_tuple(curBale, 1, curBale, 0, 0));
        }
    }

    // cout << maxBlows << "\n";
    for (int i = 0; i < n; i++) {
        cout << thirdCaseBlows[i][0] << "," << thirdCaseBlows[i][1] << " | ";
        maxBlows = max(maxBlows, thirdCaseBlows[i][0]+thirdCaseBlows[i][1]+1);
    }
    // cout << "\n";
    cout << maxBlows;

}
