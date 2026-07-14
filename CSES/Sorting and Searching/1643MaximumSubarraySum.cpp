
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
long int n, arr[MAX_N];

int main() {
    cin >> n;
    long int biggestValue = -1000000000;
    for (long int i = 0; i < n; i++) {
        cin >> arr[i];
        biggestValue = max(biggestValue, arr[i]);
    }
    if (biggestValue <= 0) {
        cout << biggestValue;
        return 0;
    }
    long long int maxSum = 0;
    long long int curSum = 0;
    for (long int i = 0; i < n; i++) {
        long int curItem = arr[i];
        curSum = max(curSum+curItem, 0ll);
        maxSum = max(maxSum, curSum);
    }
    cout << maxSum;
    return 0;
}