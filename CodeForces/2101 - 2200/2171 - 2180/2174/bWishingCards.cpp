
// https://codeforces.com/problemset/problem/2174/B
// NOT SOLVED

#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = 100000;
const long int MAX_K = 360;

long int t, n, k;
int arr[MAX_N];
long int dp[MAX_N][MAX_K+1][4];
// 0: The value itself. 1: The index after the value where there's an increase. 2: The index the first increase is at. 3: The value of the item at that position.

void solve() {
    for (long int i = 0; i < n; i++) {
        dp[i][0][0] = 0;
        dp[i][0][1] = n;
        dp[i][0][2] = n;
        dp[i][0][3] = 0;
    }
    for (int j = 1; j <= k; j++) {
        for (long int i = 0; i < n; i++) {
            int curItem = arr[n-1-i];
            if (i == 0) {
                /*cout << curItem << "\n";
                cout << j << "\n";*/
                dp[0][j][0] = min(curItem, j);
                //cout << dp[0][j][0] << "\n";
                dp[0][j][1] = n;
                dp[0][j][2] = n-1-i;
                dp[0][j][3] = min(curItem, j);
            }else {
                long int prevKItem[] = {dp[i][j-1][0], dp[i][j-1][1], dp[i][j-1][2], dp[i][j-1][3]};
                long int prevIValue[] = {dp[i-1][j][0], dp[i-1][j][1], dp[i-1][j][2], dp[i-1][j][3]};
                long int addedValue = (prevKItem[3] < curItem) ? prevKItem[1] -n+1+i : 0;
                long int addedIValue = (curItem != 0) ? prevIValue[2] - n+1+i : 0;
                /*cout << addedValue << "\n";
                cout << prevKItem[0] << "\n";
                cout << prevKItem[1] << "\n";*/
                if (prevKItem[0]+addedValue >= prevIValue[0]+addedIValue) {
                    if (prevKItem[3] < curItem) {
                        dp[i][j][0] = prevKItem[0]+addedValue;
                        dp[i][j][1] = (arr[prevKItem[1]] == prevKItem[3]+1)
                            ? dp[prevKItem[1]][j-1][1] 
                            : prevKItem[1];
                        dp[i][j][2] = n-1-i;
                        dp[i][j][3] = prevKItem[3]+1;
                    }else {
                        dp[i][j][0] = prevKItem[0];
                        dp[i][j][1] = prevKItem[1];
                        dp[i][j][2] = n-1-i;
                        dp[i][j][3] = prevKItem[3];
                    }
                }else {
                    if (curItem != 0) {
                        dp[i][j][0] = prevIValue[0]+addedIValue;
                        if (prevIValue[3] == 0) {
                            prevIValue[0] = dp[prevIValue[2]][j][0];
                            prevIValue[1] = dp[prevIValue[2]][j][1];
                            prevIValue[2] = dp[prevIValue[2]][j][2];
                            prevIValue[3] = dp[prevIValue[2]][j][3];
                        }
                        
                        if (prevIValue[3] == 1) {
                            dp[i][j][1] = prevIValue[1];
                        }else {
                            dp[i][j][1] = prevIValue[2];
                        }
                        dp[i][j][2] = n-i-1;
                        dp[i][j][3] = 1;
                    }else {
                        dp[i][j][0] = prevIValue[0];
                        dp[i][j][1] = prevIValue[2];
                        dp[i][j][2] = prevIValue[2];
                        dp[i][j][3] = 0;
                    }
                }
            }
            /*cout << dp[0][1][0] << "\n";
            cout << dp[0][2][0] << "\n";*/
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << dp[i][j][0] << " ";
        }
        cout << "\n";
    }
    //cout << dp[n-1][k][0] << "\n";
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        for (long int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        solve();
    }
    
    return 0;
}