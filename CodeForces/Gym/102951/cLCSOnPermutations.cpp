
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MAX_N = 100000;
long long n, pos_arr[MAX_N], arr[MAX_N];

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        x--;
        pos_arr[x] = i;
    }
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        x--;
        arr[i] = pos_arr[x];
    }

    vector<long long> lis;
    for (long long i = 0; i < n; i++) {
        long long value = arr[i];
        auto it = upper_bound(lis.begin(), lis.end(), value);
        if (it == lis.end()) {
            lis.push_back(value);
        }else {
            *it = value;
        }
    }

    cout << lis.size();
}