
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MAX_N = 100000;
long long n;
vector<pair<long long, long long>> wires;

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long u, v;
        cin >> u >> v;
        wires.push_back({u, v});
    }
    sort(wires.begin(), wires.end(), greater<pair<int, int>>());
    vector<long long> lis;
    for (auto [_, value] : wires) {
        auto index = upper_bound(lis.begin(), lis.end(), value);
        if (index == lis.end()) {
            lis.push_back(value);
        }else {
            *index = value;
        }
    }
    cout << lis.size();
}
