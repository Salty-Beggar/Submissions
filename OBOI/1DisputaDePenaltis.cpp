// Y5x7XXd

#include <bits/stdc++.h>
using namespace std;

long long n, v1, p1, v2, p2;

int main() {
    cin >> n >> v1 >> v2 >> p1 >> p2;
    if (n - p1 > v2) cout << "S\n";
    else cout << "N\n";
    if (n - p2 > v1) cout << "S\n";
    else cout << "N\n";
    return 0;
}
