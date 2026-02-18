
#include <iostream>
using namespace std;

const long int MAX_N = 200000, MAX_LOGN = 18;
long int n, q, binLift[MAX_N][MAX_LOGN];

int main() {
    cin >> n >> q;
    for (long int i = 1; i < n; i++) {
        long int x;
        cin >> x; x--;
        binLift[i][0] = x;
    }
    binLift[0][0] = -1;
    for (long int j = 1; j < MAX_LOGN; j++) {
        for (long int i = 0; i < n; i++) {
            long int _next = binLift[i][j-1];
            if (_next == -1) binLift[i][j] = -1;
            else binLift[i][j] = binLift[_next][j-1];
        }
    }
    for (long int i = 0; i < q; i++) {
        long int u, v;
        cin >> u >> v;
        u--;
        long int curBoss = u;
        for (long int j = 0; j < MAX_LOGN; j++) {
            long int curBit = 1<<j;
            if ((curBit & v) != 0) {
                curBoss = binLift[curBoss][j];
                if (curBoss == -1) break;
            }
        }
        cout << ((curBoss == -1) ? -1 : curBoss+1) << "\n";
    }
}