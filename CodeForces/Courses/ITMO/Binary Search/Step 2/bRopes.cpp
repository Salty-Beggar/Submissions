
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 10000, PRECISION_BASE = 6;
const long long int PRECISION = 1000000;
const long long int MAX_VALUE = MAX_N*PRECISION;
int n, k;
long long int arr[MAX_N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] *= PRECISION;
    }
    // sort(arr, arr+n);
    long long int l = PRECISION/MAX_N, r = MAX_VALUE+1;
    while (l+1 < r) {
        long long int mid = (l+r)/2;
        long long int curPieces = 0;
        for (int i = 0; i < n; i++) {
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
    if (l != 0) {
        for (long int i = 0; i < PRECISION_BASE; i++) {
            if (l / pow(10, i) == 0) cout << "0";
        }
        while (l%10 == 0) l /= 10;
        cout << l;
    } else {
        cout << "0";
    }
    return 0;
}
