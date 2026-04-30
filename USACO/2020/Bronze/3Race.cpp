
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
long int k;

int main()
{
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        long int x;
        cin >> x;
        if (x*(x+1)/2 >= k) {
            // v(v+1)/2 = k
            // v^2 + v - 2k = 0
            long int delta = ceil(sqrt(1+4*2*k));
            cout << (delta-1)/2;
        }else {
            long long int delta = k + x*(x+1)/2;
            long int v = floor(sqrt(delta));
            if (v*v == delta) v--;
            long int ans = 2*v-x-1;
            long int remain = k-v*v+x*(x+1)/2;
            long int topLeaps = (remain-1)/v;
            remain -= topLeaps*v;
            long int bottomLeaps = (remain == 1) ? 1 : 2;
            ans += topLeaps+bottomLeaps;
            cout << ans;
        }
        cout << "\n";
    }
    return 0;
}