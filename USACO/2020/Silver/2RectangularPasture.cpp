
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const long long MAX_N = 2500;

long long n, cows[MAX_N][2];
// 0 - X coordenate. 1 - Y coordenate. It's later compressed in the code.
long long prefix_sum[MAX_N+1][MAX_N+1];

set<pair<long long, long long>> x_coords, y_coords;
// 0 - Coordenate itself. 1 - The index of the cow

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        x_coords.insert({x, i});
        y_coords.insert({y, i});
    }

    for (pair<long long, long long> x_coord : x_coords) {
        cows[x_coord.second][0] = x_coord.first;
    }
    for (pair<long long, long long> y_coord : y_coords) {
        cows[y_coord.second][1] = y_coord.first;
    }

    return 0;
}
