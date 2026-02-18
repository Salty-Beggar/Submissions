
#include <iostream>
#include <numeric>
using namespace std;

long int w, h, d, n;
long int w2, h2, d2;

int main() {
    cin >> w >> h >> d >> n;
    w2 = w;
    h2 = h;
    d2 = d;

    w2 /= gcd(w, n);
    n /= gcd(w, n);

    h2 /= gcd(h, n);
    n /= gcd(h, n);

    d2 /= gcd(d, n);
    n /= gcd(d, n);

    if (n != 1) cout << "-1";
    else cout << w/w2-1 << " " << h/h2-1 << " " << d/d2-1;
}