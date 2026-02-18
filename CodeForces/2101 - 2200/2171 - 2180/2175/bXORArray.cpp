
#include <iostream>
using namespace std;

const long int MAX_L = 500001;
int t;
long int n, l, r;

int main() {
    cin >> t;
    for (; t > 0; t--) {
        cin >> n >> l >> r;
        l--;
        if (l == 0) l = MAX_L;
        for (long int i = 1; i <= n; i++) {
            long int iPrev = i-1;
            if (iPrev == r) iPrev = l;
            if (iPrev == 0) iPrev = MAX_L;
            cout << (((i == r) ? l : i) ^ iPrev) << " ";
        }
        cout << "\n";
    }
}
