
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct coord {
    public:
        long long x;
        long long y;
    coord(long long x, long long y) : x(x), y(y) {}
};

long long n;
vector<coord> cows;
vector<long long> cows_x, cows_y, cow_left_most, cow_right_most, cow_upper_most, cow_lower_most;

int main() {
    cin >> n;
    set<long long> cows_x_set, cows_y_set;
    for (long long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        cows.push_back(coord(x, y));
        cows_x_set.insert(x);
        cows_y_set.insert(y);
    }
    for (auto x : cows_x_set) {
        cows_x.push_back(x);
        cow_left_most.push_back(0);
        cow_right_most.push_back(cows_x_set.size());
    }
    for (auto y : cows_y_set) {
        cows_y.push_back(y);
        cow_bottom_most.push_back(0);
        cow_upper_most.push_back(cows_y_set.size());
    }
    
    for (auto &position : cows) {
        position.x = binary_search(cows_x.begin(), cows_x.end(), position.x);
        position.y = binary_search(cows_y.begin(), cows_y.end(), position.y);
    }

    

    return 0;
}
