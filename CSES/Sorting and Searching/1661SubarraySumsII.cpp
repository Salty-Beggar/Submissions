
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

const long int MAX_N = 200000;
const long long int MAX_SUM = 200000000000000;
long int n, x, p;
long long int prefixSum[MAX_N+1];

struct CustomComp {
    bool operator()(pair<long long int, long int> a, pair<long long int, long int> b) const {
        return (a.first != b.first) ? a.first < b.first : a.second > b.second;
    }
};
        
// bool compare(pair<long long int, long int> a, pair<long long int, long int> b) {
//     return (a.first != b.first) ? a.first > b.first : a.second < b.second;
// }

int main() {
    cin >> n >> x;
    if (x == 0) {
        multiset<long long int> prefixSumSet;
        prefixSumSet.insert(0);
        for (long int i = 0; i < n; i++) {
            long int a;
            cin >> a;
            prefixSum[i+1] = a+prefixSum[i];
            prefixSumSet.insert(prefixSum[i+1]);
        }
        long long int ans = 0;
        auto iterator = prefixSumSet.begin();
        while (iterator != prefixSumSet.end()) {
            long int count = prefixSumSet.count(*iterator);
            ans += count*(count-1)/2;
            iterator = prefixSumSet.upper_bound(*iterator);
        }
        cout << ans;
        return 0;
    }
    set<pair<long long int, long int>, CustomComp> prefixSumSet;
    prefixSumSet.insert({0, 0});
    p = n+1;
    for (long int i = 0; i < n; i++) {
        long int a;
        cin >> a;
        prefixSum[i+1] = a+prefixSum[i];
        prefixSumSet.insert({prefixSum[i+1], i+1});
    }
    // sort(prefixSum, prefixSum+p, [](pair<long long int, long int> a, pair<long long int, long int> b) {
    //     return (a.first != b.first) ? a.first > b.first : a.second < b.second;
    // });
    auto iterator = prefixSumSet.begin();
    long long int ans = 0;
    while (iterator != prefixSumSet.end()) {
        long long int curSum = (*iterator).first;
        // cout << curSum << " ";
        // cout << (*iterator).first << "|" << (*iterator).second << " ";
        // iterator++;
        long long int biggerSum = curSum+x;
        auto biggerIterator = prefixSumSet.lower_bound({biggerSum, MAX_N+1});
        long int streak = 0;
        // cout << (*iterator).first << "|" << (*iterator).second << "|" << biggerSum << " : ";
        while (iterator != prefixSumSet.end() && (*iterator).first == curSum) {
            // cout << (*biggerIterator).first << "|" << (*biggerIterator).second << " ";
            if (
                biggerIterator != prefixSumSet.end()
                && (*biggerIterator).first == biggerSum
                && (*biggerIterator).second > (*iterator).second
            ) {
                streak++;
                biggerIterator++;
            }else {
                ans += streak;
                iterator++;
            }
        }
        // cout << "\n";
        
        // iterator = prefixSumSet.upper_bound({curSum, -MAX_SUM-1});
    }

    // cout << "\n---\n";
    cout << ans;

    return 0;
}