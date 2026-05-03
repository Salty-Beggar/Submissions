
#include <iostream>
#include <cstdio>

using namespace std;

int a, b, c, d;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    cin >> a >> b >> c >> d;
    cout << (b-a+d-c) - max(0, min(b, d) - max(a, c));
    return 0;
}