
// This solution is wrong because you don't consider the fact you can't subtract a smaller prefix sum by a bigger one.

#include <set>
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
long int n, x;
long long int prefixSumArr[MAX_N+1];
multiset<long long int> prefixSumSet;

int main() {
    prefixSumSet.insert(0);
    cin >> n >> x;
    for (long int i = 0; i < n; i++) {
        long int a;
        cin >> a;
        prefixSumArr[i+1] = prefixSumArr[i]+a;
        prefixSumSet.insert(prefixSumArr[i+1]);
    }
    auto iterator = prefixSumSet.begin();
    long long int ans = 0;
    while (iterator != prefixSumSet.end()) {
        long long int curSum = *iterator;
        if (x == 0) {
            ans += prefixSumSet.count(curSum)*(prefixSumSet.count(curSum)-1)/2;
        }else {
            long long int biggerSum = x+curSum;
            ans += prefixSumSet.count(curSum)*prefixSumSet.count(biggerSum);
        }
        // cout << curSum << " ";
        iterator = prefixSumSet.upper_bound(curSum);
    }
    cout << ans;
    return 0;
}