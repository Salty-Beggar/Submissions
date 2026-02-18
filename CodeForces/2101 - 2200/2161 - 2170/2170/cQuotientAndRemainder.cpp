
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n;
long long int k, qArr[MAX_N], rArr[MAX_N];
// multiset<long long int> qSet, rSet;

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> k;
        for (long int i = 0; i < n; i++) {
            cin >> qArr[i];
        }
        for (long int i = 0; i < n; i++) {
            cin >> rArr[i];
        }
        sort(qArr, qArr+n);
        sort(rArr, rArr+n);
        reverse(rArr, rArr+n);
        // for (long int i = 0; i < n; i++) {
        //     cout << qArr[i] << " ";
        // }
        // cout << "\n";
        // for (long int i = 0; i < n; i++) {
        //     cout << rArr[i] << " ";
        // }
        // cout << "\n";
        long int qPointer = 0;
        long int rPointer = 0;
        long int ans = 0;
        while (qPointer != n && rPointer != n) {
            long long int curQ, curR;
            curQ = qArr[qPointer];
            curR = rArr[rPointer];
            if (curQ*(curR+1)+curR <= k) {
                ans++;
                qPointer++;
                rPointer++;
            }else {
                rPointer++;
            }
        }
        cout << ans << "\n";
    }
}

