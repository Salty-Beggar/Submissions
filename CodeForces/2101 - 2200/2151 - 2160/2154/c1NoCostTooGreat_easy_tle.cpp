
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n;
bool sieve[MAX_N+1], valueExists[MAX_N+1][2];

int main() {
    for (cin >> t; t > 0; t--) {
        for (long int i = 0; i <= MAX_N; i++) {
            sieve[i] = false;
            valueExists[i][0] = false;
            valueExists[i][1] = false;
        }
        
        cin >> n;
        bool hasEven = false;
        bool doBreak2 = false;
        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
            valueExists[x][0] = true;
            if (x%2 == 1) valueExists[x+1][1] = true;
            else {
                if (hasEven) {
                    cout << 0 << "\n";
                    doBreak2 = true;
                    break;
                }
                hasEven = true;
            }
        }
        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
        }
        if (doBreak2) continue;
        bool doBreak = false;
        bool isAnsNot2 = false;
        int ans = 0;
        for (long int i = 2; i <= MAX_N; i++) {
            if (!sieve[i]) {
                bool hasAdded = false;
                bool hasDefault = false;
                for (long int j = i; j <= MAX_N; j += i) {
                    if (valueExists[j][1]) {
                        if (hasDefault) {
                            ans = 1;
                            isAnsNot2 = true;
                        }
                        hasAdded = true;
                    }
                    if (valueExists[j][0]) {
                        if (hasDefault) {
                            ans = 0;
                            doBreak = true;
                            isAnsNot2 = true;
                            break;
                        }else if (hasAdded) {
                            ans = 1;
                            isAnsNot2 = true;
                        }
                        hasDefault = true;
                    }
                }
                if (doBreak) break;
            }
        }
        if (isAnsNot2) {
            cout << ans << "\n";
        }else {
            cout << 2 << "\n";
        }
    }
}