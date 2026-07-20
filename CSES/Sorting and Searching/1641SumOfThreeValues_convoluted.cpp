
#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX_N = 5000;
const long long int MAX_N2 = 24995000;
long int n, stackArr[MAX_N];
long long int x, n2;
pair<long long int, long int> arr[MAX_N];
pair<long long int, pair<long int, long int>> pairArr[MAX_N2];

long long int getPairSum(long int index) {
    return arr[index].first+arr[stackArr[index]].first;
}

int main() {
    cin >> n >> x;
    for (long int i = 0; i < n; i++) {
        long long int a;
        cin >> a;
        arr[i] = {a, i};
    }
    sort(arr, arr+n);
    n2 = n*(n-1)/2;
    long int j = 1;
    for (long long int i = 0; i < n2; i++) {
        long long int curPairSum = getPairSum(j);
        pairArr[i] = {curPairSum, {arr[j].second, arr[stackArr[j]].second}};
        stackArr[j]++;
        if (stackArr[j] == j) {
            j++;

        }
        while (
            (stackArr[j-1] != j-1 && getPairSum(j-1) <= getPairSum(j)) ||
            (j < n-1 && getPairSum(j+1) < getPairSum(j))
        ) {
            long int add = 0;
            if ((stackArr[j-1] != j-1 && getPairSum(j-1) <= getPairSum(j))) {
                add = -1;
            }
            if (j < n-1 && getPairSum(j+1) < getPairSum(j+add)) {
                add = 1;
            }
            j += add;
        }
    }
    cout << is_sorted(pairArr, pairArr+n2) << "\n";
    // for (long long int i = 0; i < n2; i++) {
    //     cout << pairArr[i].first << " ";
    // }
    // cout << "\n";
    long long int r = n2-1;
    for (long int i = 0; i < n; i++) {
        while (arr[i].first+pairArr[r].first > x) {
            r--;
            if (r < 0) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
        if (
            arr[i].first+pairArr[r].first == x &&
            arr[i].second != pairArr[r].second.first &&
            arr[i].second != pairArr[r].second.second
        ) {
            cout << arr[i].second+1 << " " << pairArr[r].second.first+1 << " " << pairArr[r].second.second+1;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}