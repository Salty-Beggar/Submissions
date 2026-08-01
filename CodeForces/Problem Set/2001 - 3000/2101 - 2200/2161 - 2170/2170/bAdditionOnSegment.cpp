
#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n;

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        long long int nonZeroAmount = 0;
        long long int totalSum = 0;
        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
            if (x != 0) nonZeroAmount++;
            totalSum += x;
        }
        cout << min(nonZeroAmount, totalSum-n+1) << "\n";
    }
}
