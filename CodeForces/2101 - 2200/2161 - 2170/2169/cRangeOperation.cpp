
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n, arr[MAX_N], dp[MAX_N][2]; /*
0 - l
1 - r
*/

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        for (long int i = 0; i < n; i++) {
            cin >> arr[i];
            long int curL = 2*(i+1)-2-arr[i];
            dp[i][0] = (i == 0 || dp[i-1][0] < 0) ? curL : dp[i-1][0]+curL;
            dp[i][1] = 2*(i+1)-arr[i];
        }
        long int maxSum = 0;
        long int rSub = 0;
        for (long int i = n-1; i >= 0; i--) {
            rSub += dp[i][1];
            maxSum = max(maxSum, dp[i][0] - rSub);
        }
    }
    return 0;
}