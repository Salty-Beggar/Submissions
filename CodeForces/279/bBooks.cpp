
#include <iostream>
using namespace std;

const long int MAX_N = 100000;
long int n, t, arr[MAX_N];

int main() {
    cin >> n >> t;
    for (long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long int maxLength = 0;
    long int r = 0;
    long int tSum = 0;
    for (long int i = 0; i < n; i++) {
        while (r != n && tSum <= t) {
            tSum += arr[r];
            r++;
        }
        maxLength = max(maxLength, r-i-(tSum > t));
        tSum -= arr[i];
    }
    cout << maxLength;
}