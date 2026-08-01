
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n;
string brackets;
long int dp[MAX_N][2];

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> brackets;
        // long int curStack = 0;
        // long int curSize = 0;
        // for (long int i = n-1; i >= 0; i--) {
        //     char curChar = brackets[i];

        //     if (curChar == ')') {
        //         if (i != n-1 && brackets[i+1] == '(') {
        //             if (curStack != 0) {
        //                 dp[i][0] = curSize+1;
        //             }
        //         }
        //     }else {
        //         curStack--;
        //         curSize += 2;
        //     }
        // }

        // curStack = 0;
        // curSize = 0;
        // long int ans = dp[0][0];
        // for (long int i = 0; i < n; i++) {
        //     char curChar = brackets[i];

        //     if (curChar == '(') {
        //         curStack++;
        //     }else {
        //         curStack--;
        //         curSize += 2;
        //     }
        // }

        long int _index = n;
        long int _extraStacks = 0;
        long int curStacks = 0;
        for (long int i = n-1; i >= 0; i--) {
            char curChar = brackets[i];
            if (curChar == '(') {
                _index = i;
                curStacks--;
                _extraStacks = curStacks;
            }else {
                curStacks++;
                dp[i][0] = _index;
                dp[i][1] = _extraStacks;
            }
        }

        long int ans = 0;
        curStacks = 0;
        for (long int i = 0; i < n; i++) {
            char curChar = brackets[i];
            if (curChar == ')') {
                long int curSize = n-dp[i][0];
                // cout << i << "\n";
                // cout << dp[i][1] << "|" << curStacks << "|" << curSize << "\n";
                if ((curSize-dp[i][1])/2 - (curStacks - dp[i][1]) >= 1) {
                    ans = max(ans, i + curSize+dp[i][1]-curStacks);
                }
                curStacks--;
            }else {
                curStacks++;
            }
        }
        cout << ((ans == 0) ? -1 : ans) << "\n";
    }
    return 0;
}