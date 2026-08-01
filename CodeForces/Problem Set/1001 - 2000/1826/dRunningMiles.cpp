
#include <iostream>
using namespace std;

const long int MAX_N = 100000;
long int t, n, arr[MAX_N], lMax[MAX_N], rMax[MAX_N];

int main() {
    cin >> t;
    for (; t > 0; t--) {
        cin >> n;
        for (long int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        lMax[0] = 0;
        rMax[n-1] = 0;
        for (long int i = 1; i < n; i++) {
            lMax[i] = max(arr[i-1]-1, lMax[i-1]-1);
        }
        for (long int i = n-2; i >= 0; i--) {
            rMax[i] = max(arr[i+1]-1, rMax[i+1]-1);
        }
        long int ans = 0;
        for (long int i = 1; i < n-1; i++) {
            ans = max(ans, lMax[i]+rMax[i]+arr[i]);
        }
        cout << ans;
        cout << "\n";
    }
    return 0;
}