
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

const long long int MAX_N = 10000, MAX_L = 10000, PRECISION_BASE = 6;
const long long int PRECISION = 1000000, MAX_A = 10000000;
const long long int MAX_VALUE = MAX_A*PRECISION;
long long int n, k;
long long int arr[MAX_N];

int main() {
    cin >> n >> k;
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] *= PRECISION;
    }
    long long int l = PRECISION/MAX_L, r = MAX_VALUE+1;
    while (l+1 < r) {
        long long int mid = (l+r)/2;
        long long int curPieces = 0;
        for (long long int i = 0; i < n; i++) {
            curPieces += arr[i]/mid;
        }
        if (curPieces >= k) {
            l = mid;
        }else {
            r = mid;
        }
    }
    cout << l/PRECISION;
    l %= PRECISION;
    cout << ".";
    // cout << l << "\n";
    if (l != 0) {
        for (long long int i = 0; i < PRECISION_BASE; i++) {
            if (l / ((long long int)pow(10, i)) == 0) cout << "0";
        }
        while (l%10 == 0) l /= 10;
        cout << l;
    } else {
        cout << "0";
    }
    return 0;
}
