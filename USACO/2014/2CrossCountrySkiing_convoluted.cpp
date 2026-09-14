
#include <iostream>
#include <cstdio>
#include <functional>
#include <queue>
using namespace std;

const long long MAX_NM = 500, MAX_VALUE = 1000000000;
long long first_true(function<bool(long long)> func) {
    long long l = -1, r = MAX_VALUE;
    while (l != r-1) {
        long long mid = (l+r)/2;
        if (func(mid)) {
            r = mid;
        }else {
            l = mid;
        }
    }
    return r;
}
long long n, m, matrix[MAX_NM][MAX_NM];

struct coord {
    public:
    long long x, y;
    coord() : x(0), y(0) {}
    coord(long long x, long long y) : x(x), y(y) {}
    operator long long() const {
        if (x < 0 || x >= n || y < 0 || y >= m) return -1;
        return matrix[x][y];
    }
    coord left() const {
        return coord(x-1, y);
    }
    coord right() const {
        return coord(x+1, y);
    }
    coord up() const {
        return coord(x, y-1);
    }
    coord down() const {
        return coord(x, y+1);
    }
};

coord targets[MAX_NM*MAX_NM];

int main() {
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    long long targ_n = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            long long is_target;
            cin >> is_target;
            if (is_target) {
                targets[targ_n] = coord(i, j);
                targ_n++;
            }
        }
    }

    return 0;
    cout << first_true([targ_n](long long value) {
        priority_queue<pair<long long, coord>> choice_pqueue;
        for (long long i = 0; i < targ_n; i++) {
            choice_pqueue.push({-1, targets[i]});
        } 

        while (!choice_pqueue.empty()) {
            auto curr_choice = choice_pqueue.top();
            choice_pqueue.pop();
            long long curr_c_diff = curr_choice.first;
            coord curr_c_coord = curr_choice.second;

        }
        return false;
    });
    return 0;
}