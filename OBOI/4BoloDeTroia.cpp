// Y5x7XXd

#include <iostream>
#include <algorithm>
using namespace std;

struct layer {
    public:
    long long a, b, c;
    layer() : a(0ll), b(0ll), c(0ll) {}
    layer(long long a, long long b, long long c) : a(a), b(b), c(c) {}
};

const long long MAX_N = 200000;
long long n;
layer layers[MAX_N];

int main() {
    cin >> n;
    long long a_max = 0;
    for (long long i = 0; i < n; i++) {
        long long a, b;
        cin >> b >> a;
        layers[i] = layer(a, b, a-b);
        a_max = max(a_max, a);
    }

    sort(layers, layers+n, [&](const layer& x, const layer& y) { return x.c > y.c; });
    long long curr_ans = layers[0].a;
    long long prev_c = layers[0].c;
    for (long long i = 1; i < n; i++) {
        curr_ans += layers[i].a - prev_c;
        prev_c = layers[i].c;
    }

    cout << max(curr_ans, a_max);

    return 0;
}
