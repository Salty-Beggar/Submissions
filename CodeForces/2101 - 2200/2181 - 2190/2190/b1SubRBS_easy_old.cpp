
#include <iostream>
using namespace std;

int t;
const long int MAX_N = 200000;
long int n, closeArr[MAX_N][2], openArr[MAX_N], barrierArr[MAX_N], dp[MAX_N];
/*
For close Arr:
[i][0] - Default, right to left order.
[i][1] - Inverse, left to right order.
Both are inclusive.
*/
string sequence;

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> sequence;

        long int closeAmount = 0;
        long int openAmount = 0;
        long int curBarriers = 0;
        for (long int i = 0; i < n; i++) {
            char curChar = sequence[i];
            if (curChar == '(') {
                openAmount++;
                openArr[i] = openAmount;

                closeArr[i][0] = n/2 - closeAmount;
                closeArr[i][1] = closeAmount;
            }else {
                closeArr[i][0] = n/2 - closeAmount;
                closeAmount++;
                closeArr[i][1] = closeAmount;

                openArr[i] = openAmount;
            }

            curChar = sequence[n-1-i];
            if (curChar == ')') {
                curBarriers++;
                barrierArr[n-1-i] = curBarriers;
            }else {
                curBarriers--;
                barrierArr[n-1-i] = barrierArr[n-i];
            }
        }

        long int count = 0;
        long int ans = 0;
        for (long int i = n-1; i >= 0; i--) {
            char curChar = sequence[i];
            count += (curChar == ')') ? 1 : -1;
            if (count == 0) {
                long int mainPivot = openArr[i]-1;
                long int lm = i;
                long int rm = n;
                long int ansIndex = i;
                cout << "\nStarted at " << i << " ~ ";
                while (lm != rm-1) {
                    long int midm = (lm+rm+1)/2;

                    #pragma region Nested BS

                    long int l = lm;
                    long int r = rm;
                    while (l != r-1) {
                        long int mid = (l+r+1)/2;
                        if (openArr[mid-1]-mainPivot >= closeArr[mid-1][0]) {
                            r = mid;
                        }else {
                            l = mid;
                            ansIndex = l;
                        }
                        cout << "\n" << l << " " << r << " " << openArr[mid-1]-mainPivot << " " << closeArr[mid-1][0] << " ";
                    }
                    cout << " && \n";

                    #pragma endregion
                    
                    cout << ansIndex << " | ";

                    if (min(openArr[ansIndex]-mainPivot, closeArr[ansIndex][0]) < barrierArr[i]+1) {
                        lm = midm;
                    }else {
                        rm = midm;
                    }
                    cout << min(openArr[ansIndex]-mainPivot, closeArr[ansIndex][0]) << " ||| ";
                }
                if (openArr[ansIndex]-mainPivot <= barrierArr[i]) {

                }else {
                    ans = max(ans, i+min(openArr[ansIndex]-mainPivot, closeArr[ansIndex][0])*2);
                }
            }
        }
        cout << "Ans: " << ans << "\n";
    }
}