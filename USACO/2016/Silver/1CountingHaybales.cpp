
#include <iterator>
#include <cstdio>
#include <iostream>
#include <set>
#include<vector>
using namespace std;

const long int MAX_N = 100000, MAX_VALUE = 1000000000;
long int n, q;
multiset<long int> haybales;
set<pair<long int, long int>> haybalesPair;

int main() {

    vector<long int> vec = {1, 5, 6, 7, 10, 11};
    cout << *lower_bound(vec.begin(), vec.end(), 3) << "\n";

    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    cin >> n >> q;
    for (long int i = 0; i < n; i++) {
        long int value;
        cin >> value;
        haybales.insert(value);
    }
    long int index = 0;
    haybalesPair.insert({0, index++});
    for (long int haybale : haybales) {
        haybalesPair.insert({haybale, index++});
    }
    haybalesPair.insert({MAX_VALUE+1, index});
    for (long int i = 0; i < q; i++) {
        long int l, r;
        cin >> l >> r;
        auto l_iterator = haybalesPair.lower_bound({l, 0});
        auto r_iterator = haybalesPair.upper_bound({r, MAX_VALUE+1});
        cout << ((*r_iterator).second - (*l_iterator).second) << "\n";
    }
}