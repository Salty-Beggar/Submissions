
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
int t, points[MAX_N][2];
long int n;

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        long int ajisaiPoints = 0;
        for (long int i = 0; i < n; i++) {
            cin >> points[i][0];
            ajisaiPoints ^= points[i][0];
        }
        long int maiPoints = 0;
        for (long int i = 0; i < n; i++) {
            cin >> points[i][1];
            maiPoints ^= points[i][1];
        }
        if (ajisaiPoints == maiPoints) {
            cout << "Tie\n";
            continue;
        }else {
            for (long int i = n-1; i >= 0; i--) {
                if (points[i][0] != points[i][1]) {
                    if (i%2 == 1) cout << "Mai\n";
                    else cout << "Ajisai\n";
                    break;
                }
            }
        }
    }
}