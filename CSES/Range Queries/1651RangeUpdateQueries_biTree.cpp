
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
long int n, q;
long long int biTree[MAX_N+1];

long long int query(long int index) {
    long long int sum = 0;
    for (long int i = index+1; i > 0; i -= i&(-i)) {
        sum += biTree[i-1];
    }
    return sum;
}

void update(long int index, long long int value) {
    //biTree[0] += value;
    for (long int i = index+1; i <= n; i += i&(-i)) {
        biTree[i-1] += value;
    }
}

void updateRange(long int l, long int r, long long int value) {
    update(l, value);
    update(r, -value);
}

int main() {
    cin >> n >> q;
    for (long int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        updateRange(i, i+1, x);
    }
    /*for (long int i = 0; i < n; i++) {
        cout << query(i) << " ";
    }
    cout << "\n";*/

    for (long int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            long int l, r;
            long long int x;
            cin >> l >> r >> x;
            updateRange(l-1, r, x);
        }else {
            long int index;
            cin >> index;
            cout << query(index-1) << "\n";
        }
    }
    return 0;
}