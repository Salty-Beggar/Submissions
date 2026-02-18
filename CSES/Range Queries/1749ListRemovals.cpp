
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
long int n, arr[MAX_N], biTree[MAX_N+1]; // Bit's indexes are 1-indexed.

long int query(long int index) {
    long int sum = 0;
    for (long int i = index+1; i > 0; i -= i&(-i)) {
        sum += biTree[i-1];
    }
    return sum;
}

long int boundSearch(long int value) {
    long int l = 0, r = n+1;
    while (l != r-1) {
        long int mid = (l+r+1)/2;
        if (value > query(mid-1)) {
            r = mid;
        }else {
            l = mid;
        }
    }
    return l; // The position just after the last occurrence of value.
}

void update(long int index, long int value) {
    for (long int i = index+1; i <= n; i += i&(i&-i)) {
        biTree[i-1] += value;
    }
}

void updateRange(long int l, long int r, long int value) {
    update(l, value);
    update(r, -value);
}

int main() {
    cin >> n;
    for (long int i = 0; i < n; i++) {
        long int x;
        cin >> arr[i];
        updateRange(n-1-i, n-i, i+1);
    }
    /*for (long int i = 0; i < n; i++) {
        cout << query(i) << " ";
    }
    cout << "\n\n";*/
    for (long int i = 0; i < n; i++) {
        long int index;
        cin >> index;
        long int q = boundSearch(index);
        cout << arr[n-q] << " ";
        updateRange(0, q, -1);
        /*for (long int i = 0; i < n; i++) {
            cout << query(i) << " ";
        }
        cout << "\n";*/
    }
}