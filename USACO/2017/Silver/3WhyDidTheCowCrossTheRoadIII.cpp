
#include <bits/stdc++.h>
using namespace std;

const long long MAX_NK = 100;
long long n, k, r;
bool is_cow[MAX_NK][MAX_NK], is_blocked[MAX_NK][MAX_NK][4], is_visited[MAX_NK][MAX_NK];
// 0 - Down, 1 - Right, 2 - Up, 3 - Left.

struct coord {
    public:
    coord() : x(-1), y(-1) {}
    coord(long long x, long long y) : x(x), y(y) {}
    long long x, y;
    bool visited() {
        return is_visited[x][y];
    }
    bool cow() {
        return is_cow[x][y];
    }
    bool blocked(long long dir) {
        return is_blocked[x][y][dir];
    }
    void visit() {
        is_visited[x][y] = true;
    }
    void block(long long dir) {
        is_blocked[x][y][dir] = true;
    }
    vector<coord> children() {
        vector<coord> new_children;
        if (x-1 >= 0 && !blocked(3)) new_children.push_back(coord(x-1, y));
        if (y-1 >= 0 && !blocked(0)) new_children.push_back(coord(x, y-1));
        if (x+1 < n && !blocked(1)) new_children.push_back(coord(x+1, y));
        if (y+1 < n && !blocked(2)) new_children.push_back(coord(x, y+1));
        return new_children;
    }
};
coord cows[MAX_NK];

void print_matrix() {
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            cout << is_visited[i][j];
        }
        cout << "\n";
    }
        cout << "\n";
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin >> n >> k >> r;
    
    for (long long i = 0; i < r; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (x1 != x2) {
            long long y = y1;
            is_blocked[x1][y][1] = true;
            is_blocked[x2][y][3] = true;
        }else {
            long long x = x1;
            is_blocked[x][y1][2] = true;
            is_blocked[x][y2][0] = true;
        }
    }
    for (long long i = 0; i < k; i++) {
        long long x, y;
        cin >> x >> y;
        x--; y--;
        is_cow[x][y] = true;
        cows[i] = coord(x, y);
    }

    long long distant_cow_pair_amount = 0;
    long long other_cow_amount = k;
    for (long long i = 0; i < k; i++) {
        coord curr_cow = cows[i];
        if (!curr_cow.visited()) {
            long long curr_cow_amount = 1;
            curr_cow.visit();
            stack<coord> dfs;
            dfs.push(curr_cow);
            // cout << "Started\n";
            //     print_matrix();
            while (!dfs.empty()) {
                coord top_cow = dfs.top();
                dfs.pop();
                for (coord child : top_cow.children()) {
                    if (child.visited()) continue;
                // print_matrix();
                    if (child.cow()) curr_cow_amount++;
                    child.visit();
                    dfs.push(child);
                }
            }
            other_cow_amount -= curr_cow_amount;
            distant_cow_pair_amount += curr_cow_amount * other_cow_amount;
        }
    }
    
    cout << distant_cow_pair_amount << "\n";
}