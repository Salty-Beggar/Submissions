
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
long int n, arr[MAX_N];
long long int prefixSum[MAX_N+1];

int main() {
    cin >> n;
    for (long int i = 0; i < n; i++) {
        cin >> arr[i];
        prefixSum[i+1] = prefixSum[i]+arr[i];
        // cout << prefixSum[i+1] << " ";
    }
    // cout << "\n";
    long long int maxSum = -100000000000000;
    long long int minLSum = 0; // prefixSum[0]
    for (long int i = 1; i <= n; i++) {
        maxSum = max(maxSum, prefixSum[i] - minLSum);
        minLSum = min(minLSum, prefixSum[i]);
    }
    cout << maxSum;
    return 0;
}