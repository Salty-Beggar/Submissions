
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n, arr[MAX_N];
long long int prefixSum[MAX_N+1];

long long int query(long int l, long int r) { // [l, r[
    return prefixSum[r] - prefixSum[l];
}

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        prefixSum[0] = 0;
        for (long int i = 0; i < n; i++) {
            cin >> arr[i];
            prefixSum[i+1] = arr[i];
            prefixSum[i+1] += prefixSum[i];
        }

        long long int ans = 0;
        for (long int i = 0; i < n; i++) {
            long int curItem = arr[i];
            long int l = i;
            long int r = n;
            while (l != r-1) {
                long int mid = (l+r)/2;
                
            }
        }
        
        cout << ans << "\n";
    }
}
