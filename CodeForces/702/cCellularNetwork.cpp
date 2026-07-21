
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const long int MAX_NM = 100000;
long int n, m, cities[MAX_NM];
set<long int> towers;
set<long int, greater<long int>> towers_rev;

int main() {
    cin >> n >> m;
    for (long int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for (long int i = 0; i < m; i++) {
        long int position;
        cin >> position;
        towers.insert(position);
        towers_rev.insert(position);
    }

    long int radius = 0;
    for (long int i = 0; i < n; i++) {
        long int city = cities[i];
        auto r_iterator = towers.upper_bound(city);
        auto l_iterator = towers_rev.lower_bound(city);
        if (r_iterator == towers.end()) {
            radius = max(radius, city - (*l_iterator));
            continue;
        }else if (l_iterator == towers_rev.end()) {
            radius = max(radius, (*r_iterator) - city);
            continue;
        }
        long int r_tower_pos = *r_iterator;
        long int l_tower_pos = *l_iterator;
        // cout << city << " - " << l_tower_pos << " " << r_tower_pos << "\n";
        if (r_tower_pos - city < city - l_tower_pos) {
            radius = max(radius, r_tower_pos - city);
        }else {
            radius = max(radius, city - l_tower_pos);
        }
    }

    cout << radius;

    return 0;
}
