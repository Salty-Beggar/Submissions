
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
long int n, q, sums[MAX_N];

int main() {
    cin >> n >> q;
    long int curSum = 0;
    for (long int i = 0; i < n; i++) {
        long int x;
        cin >> x;
        curSum ^= x;
        sums[i] = curSum;
    }
    for (long int i = 0; i < q; i++) {
        long int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == 0) cout << sums[r];
        else cout << (sums[r] ^ sums[l-1]);
        cout << "\n";
    }
}