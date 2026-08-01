
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n;

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        cout << ((n%2 == 1) ? n-1 : n) << " ";
        for (long int i = 2; i < n; i++) {
            cout << (i^1) << " ";
        }
        cout << 1 << "\n";
    }
}
