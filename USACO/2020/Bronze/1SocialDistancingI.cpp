
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// PARA_AGORA: Ou há uma trifurcação, ou uma greedy approach

long int n;
string stalls;
// vector<long int> middleGaps;

int main() {
    cin >> n >> stalls;

    long int leftGap = 0;
    long int rightGap = 0;
    long int smallestGap = 100000;
    long int biggestGap = 0;
    long int biggest2Gap = 0;

    long int lastIndex = 0;
    bool doingMiddleCows = false;
    for (long int i = 0; i < n; i++) {
        char curStall = stalls[i];
        if (curStall == '1') {
            if (!doingMiddleCows) {
                doingMiddleCows = true;
                leftGap = i;
                lastIndex = i;
                continue;
            }

            long int curGap = i-lastIndex;
            smallestGap = min(curGap, smallestGap);
            if (curGap >= biggestGap) {
                biggest2Gap = biggestGap;
                biggestGap = curGap;
            }
            lastIndex = i;
        }
    }
    rightGap = n-1-lastIndex;
    if (rightGap == n-1) {
        cout << n-1;
        return 0;
    }

    long int bestGapTrifurcated = biggestGap/3;
    long int bestGapGreedy = 0;
    for (int i = 0; i < 2; i++) {
        long int gapBifurcated = biggestGap/2;
        long int gapLeftInsert = leftGap;
        long int gapRightInsert = rightGap;
        if (gapBifurcated >= gapLeftInsert && gapBifurcated >= gapRightInsert) {
            bestGapGreedy = gapBifurcated;
            biggestGap = biggest2Gap;
        }else if (gapLeftInsert > gapRightInsert) {
            bestGapGreedy = gapLeftInsert;
            leftGap--;
        }else {
            bestGapGreedy = gapRightInsert;
            rightGap--;
        }
    }
}