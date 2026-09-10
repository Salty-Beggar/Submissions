
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const long long MAX_NM = 500;
long long n, m, matrix[MAX_NM][MAX_NM];
long long is_target[MAX_NM][MAX_NM];
// 01 - Whether or not it's a terget 10 - Whether or not it has been visited.
struct coord {
    public:
    long long x, y;
    coord(long long x, long long y) : x(x), y(y) {}
    operator long long() const {
        if (x < 0 || x >= n || y < 0 || y >= m) return -1;
        return matrix[x][y];
    }
    operator bool() const {
        return !(x < 0 || x >= n || y < 0 || y >= m);
    }
    bool operator <(const coord& other) const {
        return x < other.x;
    }
    long long operator-(const long long other) {
        return matrix[x][y] - other;
    }
    long long operator-(const coord other) {
        return matrix[x][y] - (long long)other;
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
    vector<coord> children() const {
        return {up(), down(), right(), left()};
    }
    bool is_visited() {
        return (is_target[x][y] & 2) != 0;
    }
    bool this_is_target() {
        return (is_target[x][y] & 1) != 0;
    }
    void visit() {
        is_target[x][y] |= 2;
    }
};
priority_queue<pair<long long, coord>, vector<pair<long long, coord>>, greater<pair<long long, coord>>> choice_pqueue;

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    long long targ_n = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cin >> is_target[i][j];
            if (is_target[i][j]) {
                if (targ_n == 0) {
                    coord new_coord = coord(i, j);
                    choice_pqueue.push(make_pair(0, new_coord));
                }
                targ_n++;
            }
        }
    }
    long long ans = 0;
    while (!choice_pqueue.empty()) {
        auto curr_choice = choice_pqueue.top();
        choice_pqueue.pop();
        coord curr_c_coord = curr_choice.second;
        if (curr_c_coord.is_visited()) continue;
        long long curr_c_weight = curr_choice.first;
        ans = max(ans, curr_c_weight);
        // cout << curr_c_coord.x << " " << curr_c_coord.y << "|" << curr_c_weight << "|" << (long long)curr_c_coord << "\n";
        curr_c_coord.visit();
        if (curr_c_coord.this_is_target()) {
            targ_n--;
            if (targ_n == 0) break;
        }
        for (auto child : curr_c_coord.children()) {
            if (!child) continue;
            choice_pqueue.push(make_pair(abs(child - curr_c_coord), child));
        }
    }
    cout << ans << "\n";
    return 0;
}
