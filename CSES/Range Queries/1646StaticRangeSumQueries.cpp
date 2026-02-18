
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
long int n, q;
long long int arr[MAX_N];
long long int sum[MAX_N];

int main() {
    cin >> n >> q;
    for (long int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        arr[i] = x;
    }
    long long int curSum = 0;
    for (long int i = 0; i < n; i++) {
        curSum += arr[i];
        sum[i] = curSum;
    }

    for (long int i = 0; i < q; i++) {
        long int a, b;
        cin >> a >> b;
        a--; b--;
        if (a != 0) cout << sum[b] - sum[a-1];
        else cout << sum[b];
        cout << "\n";
    }
}