
#include <iostream>
#include <algorithm>

using namespace std;

int n, weights[100], diffs[99], prefixSums[100][2]; /*
0 - Actual one
1 - Subtractive one
*/

int main() {
    cin >> n;
    int nHalf = n;
    n *= 2;
    int evenPrefixSum[50];
    int oddPrefixSum[50];
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights, weights+n);
    
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            diffs[i-1] = weights[i] - weights[i-1];
        }
    }

    evenPrefixSum[nHalf-1] = diffs[n-2];
    oddPrefixSum[nHalf-2] = diffs[n-3];
    for (int i = nHalf-2; i >= 0; i--) {
        evenPrefixSum[i] = diffs[i*2]+evenPrefixSum[i+1];
    }
    for (int i = nHalf-3; i >= 0; i--) {
        oddPrefixSum[i] = diffs[i*2+1]+oddPrefixSum[i+1];
    }

    for (int i = 0; i < nHalf; i++) {
        prefixSums[i][0] = -evenPrefixSum[i];
        if (i != nHalf-1){
            prefixSums[i][0] += oddPrefixSum[i];
            prefixSums[i][1] = oddPrefixSum[i]-evenPrefixSum[i+1];
        }
    }

    int smallestPrefixSum = 10000;
    int smallestRangeSum = 10000;

    for (int i = 0; i < nHalf; i++) {
        if (prefixSums[i][0] < smallestPrefixSum) {
            smallestPrefixSum = prefixSums[i][0];
        }
        smallestRangeSum = min(smallestRangeSum, smallestPrefixSum - prefixSums[i][1]);
    }

    /* cout << "aa\n";
    for (int i = 0; i < nHalf; i++) {
        cout << evenPrefixSum[i] << "\n";
    }
    cout << "\n";
    for (int i = 0; i < nHalf; i++) {
        cout << oddPrefixSum[i] << "\n";
    }
    cout << "\n"; */

    cout << (evenPrefixSum[0] + smallestRangeSum);

    return 0;
}