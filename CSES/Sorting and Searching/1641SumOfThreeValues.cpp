
#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = 5000, MAX_N2 = 25000000;
long int n, x, arr[MAX_N], arrSquared[MAX_N2];

int main() {
    cin >> n >> x;
    for (long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    long int r = 1;
    for (long int i = 0; i < n; i++) {
        // RIGHT_NOW: You can do the solution in N²log(N²) time, however try finding a NlogN solution.
    }
    return 0;
}