
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n;

int main() {
    cin >> t;
    for (; t > 0; t--) {
        cin >> n;
        long int maxOdd = 0;
        long int oddCount = 0;
        long int minEven = -1;
        long long int evenSum = 0;
        long int evenCount = 0;
        vector<long int> evenList;
        for (long int i = 0; i < n; i++) {
            long int a;
            cin >> a;
            if (a%2 == 0) {
                evenSum += a;
                minEven = (minEven == -1) ? a : min(a, minEven);
                evenCount++;
                evenList.push_back(a);
            } else {
                maxOdd = max(maxOdd, a);
                oddCount++;
            }
        }
        long long int overloadValue = maxOdd+evenSum-minEven;
        if (minEven == -1) overloadValue = 0;

        if (maxOdd == 0) {
            for (long int i = 0; i < n; i++) {
                cout << 0 << " ";
            }
            cout << "\n";
            continue;
        }

        sort(evenList.begin(), evenList.end());
        reverse(evenList.begin(), evenList.end());

        cout << maxOdd << " ";
        long long int curEvenSum = 0;
        for (long int i = 0; i < evenCount; i++) {
            curEvenSum += evenList[i];
            cout << maxOdd+curEvenSum << " ";
        }
        bool isOddOdd = true;
        for (long int i = evenCount+1; i < n; i++) {
            if (i == n-1 && oddCount%2 == 0) cout << 0 << " ";
            else if (isOddOdd) cout << overloadValue << " ";
            else cout << maxOdd+evenSum << " ";
            isOddOdd = !isOddOdd;
        }
        
        cout << "\n";
    }
    return 0;
}
