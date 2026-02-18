
#include <algorithm>
#include <tuple>
#include <vector>
#include <iostream>
using namespace std;

typedef tuple<long long int, long long int, long long int, long long int, long long int> jump;
long int t;
long long int n;
long long int x;
vector<jump> jumps, jumps2;

bool comp(jump& a, jump& b) {
    return get<3>(a) > get<3>(b);
}

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> x;
        jumps.clear();
        jumps2.clear();
        for (long long int i = 0; i < n; i++) {
            long long int a, b, c;
            cin >> a >> b >> c;
            x -= (b-1)*a;
            jumps.push_back({a, b, c, b*a-c, (b-1)*a});
            // jumps2.push_back({a, b, c, (b-1)*a});
        }
        sort(jumps.begin(), jumps.end(), comp);
        // sort(jumps2.begin(), jumps2.end(), comp);
        
        
        if (x <= 0) cout << 0 << "\n";
        else {
            if (get<3>(jumps[0]) > 0) cout << (x-1)/get<3>(jumps[0])+1 << "\n";
            else cout << -1 << "\n";
        }
    }
    return 0;
}
