
#include <iostream>
#include <cstdio>

using namespace std;

long int a1, b1, c1, a2, b2, c2;

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    cin >> a1 >> a1 >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    cout << a2-a1+b2-b1+c2-c1 << "\n";
    cout << b2-b1+c2-c1 << "\n";
    cout << c2-c1 << "\n";
    return 0;
}