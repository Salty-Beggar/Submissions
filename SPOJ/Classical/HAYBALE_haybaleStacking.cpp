
#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = 1000000;
long int n, k, diffArr[MAX_N+1], arr[MAX_N];

int main() {
    cin >> n >> k;
    for (long int i = 0; i < k; i++) {
        long int l, r;
        cin >> l >> r;
        l--;
        diffArr[l]++;
        diffArr[r]--;
    }
    long int sum = 0;
    for (long int i = 0; i < n; i++) {
        sum += diffArr[i];
        arr[i] = sum;
    }
    sort(arr, arr+n);
    cout << arr[n/2];
    return 0;
}