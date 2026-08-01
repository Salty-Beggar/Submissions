
#include <iostream>
using namespace std;

const long int MAX_N = 200000, MAX_M = 500000, MAX_STR = 500000;
long int n, m;
long long int letterAmountsWord[MAX_N][26], letterAmountsTotal[26], letterAmountsTotalWord[26];

int main() {
    cin >> n >> m;
    //long int letterAmounts[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (long int i = 0; i < n; i++) {
        string newSign;
        cin >> newSign;
        for (long int j = 0; j < newSign.size(); j++) {
            char curChar = newSign[j];
            letterAmountsWord[i][curChar-'A']++;
            letterAmountsTotalWord[curChar-'A']++;
            letterAmountsTotal[curChar-'A'] += m;
        }
    }
    for (long int i = 0; i < n; i++) {
        long long int letterAmountsCur[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        bool notPossible = false;
        for (long int j = 0; j < 26; j++) {
            letterAmountsCur[j] = letterAmountsTotal[j] - (m+1)*letterAmountsWord[i][j];
            // cout << (char) (j+'A') << "|" << letterAmountsTotal[j] << "|" << letterAmountsWord[i][j] << "\n";
            if (letterAmountsCur[j] < 0) {
                cout << -1 << " ";
                notPossible = true;
                break;
            }
        }
        if (notPossible) continue;
        long int l = 0, r = m+1;
        while (l != r-1) {
            long int mid = (l+r)/2;
            bool canIncrease = true;
            for (long int j = 0; j < 26; j++) {
                if (letterAmountsCur[j] - (letterAmountsTotalWord[j]-letterAmountsWord[i][j])*mid < 0) {
                    canIncrease = false;
                    break;
                }
                // for (long int z = 0; z < n; z++) {
                //     if (letterAmountsCur[j] - letterAmountsWord[z][j]*mid < 0) {
                //         canIncrease = false;
                //         break;
                //     }
                // }
                // if (!canIncrease) break;
            }
            if (canIncrease) {
                l = mid;
            }else {
                r = mid;
            }
        }
        cout << l << " ";
    }
}
