
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long int n;
string stalls;
vector<long int> intervals;

int main() {
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);

    cin >> n >> stalls;
    long int lastPos = 0;
    long int biggestInterval = 0;
    long int biggest2Interval = 0;
    long int smallestInterval = 100000;
    for (long int i = 0; i < n; i++) {
        char curStall = stalls[i];
        if (curStall == '1') {
            long int curInterval = i - lastPos;
            if (intervals.size() != 0) {
                smallestInterval = min(curInterval, smallestInterval);
                if (curInterval >= biggestInterval) {
                    biggest2Interval = biggestInterval;
                    biggestInterval = curInterval;
                }
            }
            intervals.push_back(curInterval);
            lastPos = i;
        }
    }
    long int curInterval = n - lastPos-1;
    intervals.push_back(curInterval);

    if (intervals.size() == 1) {
        cout << n-1;
        return 0;
    }else if (intervals.size() == 2) {
        long int biggestSideInterval = max(*intervals.begin(), *intervals.rbegin())+1;
        long int smallestSideInterval = min(*intervals.begin(), *intervals.rbegin())+1;
        if (biggestSideInterval - smallestSideInterval <= 1) cout << smallestSideInterval-1;
        else cout << smallestSideInterval;
        return 0;
    }

    long int biggestIntervalSplit = biggestInterval/3;

    long int biggestSideInterval = max(*intervals.begin(), *intervals.rbegin());
    long int smallestSideInterval = min(*intervals.begin(), *intervals.rbegin());
    long int biggestIntervalHalved = biggestInterval/2;
    long int smallestIntervalHalved = biggest2Interval/2;

    long int otherIntervals[4] = {biggestSideInterval, smallestSideInterval, biggestIntervalHalved, smallestIntervalHalved};
    sort(otherIntervals, otherIntervals+4);

    long int ans = max({
        min({smallestInterval, biggestIntervalSplit}), 
        min({smallestInterval, otherIntervals[2]}), 
    });

    if (otherIntervals[3] == biggestSideInterval) ans = max(ans, min(smallestInterval, biggestSideInterval/2));
    
    cout << ans;
    return 0;
}