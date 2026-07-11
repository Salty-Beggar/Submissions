
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

const long int MAX_N = 200000;
long int n, x, p;
pair<long long int, long int> prefixSum[MAX_N+1];
set<pair<long long int, long int>> prefixSumSet;

int main() {
    prefixSum[0] = {0, 0};
    prefixSumSet.insert({0, 0});
    cin >> n >> x;
    p = n+1;
    for (long int i = 0; i < n; i++) {
        long int a;
        cin >> a;
        prefixSum[i+1] = {a+prefixSum[i].first, i+1};
        prefixSumSet.insert(prefixSum[i+1]);
    }
    sort(prefixSum, prefixSum+p);
    auto iterator = prefixSumSet.begin();
    long long int ans = 0;
    while (iterator != prefixSumSet.end()) {
        // RIGHT_NOW: Now it's easy. Just keep traversing the set to make sure you don't commit the same mistake as before.
        long long int curSum = *iterator;
        if (x == 0) {
            ans += prefixSumSet.count(curSum)*(prefixSumSet.count(curSum)-1)/2;
            iterator = prefixSumSet.upper_bound(curSum);
            continue;
        }
        
        // if (x == 0) {
        //     ans += prefixSumSet.count(curSum)*(prefixSumSet.count(curSum)-1)/2;
        // }else {
        //     long long int biggerSum = x+curSum;
        //     ans += prefixSumSet.count(curSum)*prefixSumSet.count(biggerSum);
        // }
        // // cout << curSum << " ";
        // iterator = prefixSumSet.upper_bound(curSum);
    }

    return 0;
}