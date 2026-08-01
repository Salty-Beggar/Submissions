
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const long int MAX_N = 100000;
int t;
long int n, x;
deque<long int> prices;
vector<long int> pricesOrder;

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> x;
        prices.clear();
        pricesOrder.clear();
        for (long int i = 0; i < n; i++) {
            long int a;
            cin >> a;
            prices.push_back(a);
        }
        sort(prices.begin(), prices.end());
        long long int curSum = 0;
        long long int maxLoyalty = 0;
        for (long int i = 0; i < n; i++) {
            long int curBiggest = prices.back();
            long int curSmallest = prices.front();
            if ((curSum+curBiggest)/x != curSum/x) {
                prices.pop_back();
                pricesOrder.push_back(curBiggest);
                curSum += curBiggest;
                maxLoyalty += curBiggest;
                continue;
            }
            prices.pop_front();
            pricesOrder.push_back(curSmallest);
            curSum += curSmallest;
        }
        cout << maxLoyalty << "\n";
        for (long int i = 0; i < n; i++) {
            cout << pricesOrder[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}