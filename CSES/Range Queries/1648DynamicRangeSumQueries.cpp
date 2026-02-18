
#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX_N = 200000, MAX_LOGN = 18;
long int n, q;
long long int arr[MAX_N], binIT[MAX_N]; // Binary Indexed Tree

void update(long int index, long long int value) {
    long long int diff = value-arr[index];
    arr[index] = value;
    for (long int i = index+1; i <= n; i += i&(-i)) {
        binIT[i-1] += diff;
    }
}

long long int query(long int index) {
    long long int sum = 0;
    for (long int i = index+1; i > 0; i -= i&(-i)) {
        sum += binIT[i-1];
    }
    return sum;
}


int main() {
    cin >> n >> q;
    for (long int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        update(i, x);
    }
    for (long int i = 0; i < q; i++) {
        long int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            update(a-1, b);
        }else {
            if (a != 1) cout << query(b-1) - query(a-2);
            else cout << query(b-1);
            cout << "\n";
        }
    }
    return 0;
}