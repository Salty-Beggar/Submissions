
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

const long long MAX_N = 20;

long long n, arr[MAX_N][MAX_N];
bool is_visited[MAX_N][MAX_N], is_blocked[MAX_N][MAX_N];

struct coord {
    public:
    long long x, y;
    coord() : x(-1), y(-1) {}
    coord(long long x, long long y) : x(x), y(y) {}
    vector<coord> children() {
        vector<coord> new_children;
        if (x-1 >= 0) new_children.push_back(coord(x-1, y));
        if (x+1 < n) new_children.push_back(coord(x+1, y));
        if (y-1 >= 0) new_children.push_back(coord(x, y-1));
        if (y+1 < n) new_children.push_back(coord(x, y+1));
        return new_children;
    }
    long long color() {
        return arr[x][y];
    }
    bool was_visited() {
        return is_visited[x][y];
    }
    bool in_bounds(long long x1, long long y1, long long x2, long long y2) {
        return x >= x1 && y >= y1 && x < x2 && y < y2;
    }
    void visit() {
        is_visited[x][y] = true;
    }
    coord left() const {
        return coord(x-1, y);
    }
    coord right() const {
        return coord(x+1, y);
    }
    coord down() const {
        return coord(x, y-1);
    }
    coord up() const {
        return coord(x, y+1);
    }
};

struct rect {
    public:
    coord coord_1, coord_2;
    rect(coord coord_1, coord coord_2) : coord_1(coord_1), coord_2(coord_2) {}
    long long area() const {
        return (coord_2.x - coord_1.x) * (coord_2.y - coord_1.y);
    }
    bool empty() const {
        return area() == 0;
    }  
    rect thin() const {
        return rect(coord_1, coord_2.left());
    }
    rect squash() const {
        return rect(coord_1, coord_2.up());
    }
    rect right() const {
        return rect(coord_1.right(), coord_2.right());
    }
    rect down() const {
        return rect(coord_1.down(), coord_2.down());
    }
};

void print_arr(long long x1, long long y1, long long x2, long long y2) {
    for (long long x = 0; x < n; x++) {
        for (long long y = 0; y < n; y++) {
            if (x < x1 || x >= x2 || y < y1 || y >= y2) {
                cout << '.';
            }else {
                cout << ((char) (arr[x][y] + 'A'));
            }
        }
        cout << "\n";
    }
    cout << "\n";
    // for (long long x = x1; x < x2; x++) {
    //     for (long long y = y1; y < y2; y++) {
    //         cout << ((char) (arr[x][y] + 'A'));
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
}

int main() {
    // freopen("where.in", "r", stdin);
    // freopen("where.out", "w", stdout);
    cin >> n;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            char a;
            cin >> a;
            arr[i][j] = a-'A';
        }
    }

    long long pcl_amount = 0;
    for (long long z = 0; z <= n; z++) {
        for (long long k = 0; k <= z; k++) {
            long long i = n-z+k;
            long long j = n-k;
            for (long long i_pos = 0; i_pos < n-i+1; i_pos++) {
                for (long long j_pos = 0; j_pos < n-j+1; j_pos++) {
                    long long 
                        i1 = i_pos,
                        j1 = j_pos,
                        i2 = i_pos+i,
                        j2 = j_pos+j;

                    long long color_1 = -1, color_2 = -1;
                    long long color_1_amount = 0, color_2_amount = 0;
                    coord color_2_coord;
                    bool is_impossible = false;
                    bool is_contained = true;
                    for (long long x = i1; x < i2; x++) {
                        for (long long y = j1; y < j2; y++) {
                            is_visited[x][y] = false;
                            if (!is_blocked[x][y]) is_contained = false;
                            long long curr_color = arr[x][y];
                            if (color_1 == -1 || curr_color == color_1) {
                                color_1 = curr_color;
                                color_1_amount++;
                            }else if (color_2 == -1 || curr_color == color_2) {
                                color_2 = curr_color;
                                color_2_amount++;
                                color_2_coord = coord(x, y);
                            }else {
                                is_impossible = true;
                                break;
                            }
                        }
                        if (is_impossible) break;
                    }
                    if (is_contained || color_2 == -1 || is_impossible) continue;
                    stack<coord> dfs;
                    dfs.push(coord(i1, j1));
                    is_visited[i1][j1] = true;
                    while (!dfs.empty()) {
                        coord top_coord = dfs.top();
                        dfs.pop();
                        color_1_amount--;
                        for (auto child : top_coord.children()) {
                            if (!child.was_visited() && child.color() == color_1 && child.in_bounds(i1, j1, i2, j2)) {
                                child.visit();
                                dfs.push(child);
                            }
                        }
                    }
                    dfs.push(color_2_coord);
                    is_visited[color_2_coord.x][color_2_coord.y] = true;
                    while (!dfs.empty()) {
                        coord top_coord = dfs.top();
                        dfs.pop();
                        color_2_amount--;
                        for (auto child : top_coord.children()) {
                            if (!child.was_visited() && child.color() == color_2 && child.in_bounds(i1, j1, i2, j2)) {
                                child.visit();
                                dfs.push(child);
                            }
                        }
                    }
                    if (color_1_amount == 0 && color_2_amount == 0) continue;
                    if (color_1_amount == 0) {
                        // cout << color_1_amount << "\n" << color_2_amount << "\n";
                        print_arr(i1, j1, i2, j2);
                        for (long long x = i1; x < i2; x++) {
                            for (long long y = j1; y < j2; y++) {
                                is_blocked[x][y] = true;
                            }
                        }
                        pcl_amount++;
                    }else if (color_2_amount == 0) {
                        // cout << "Printing \n";
                        // cout << color_1_amount << "\n" << color_2_amount << "\n";
                        print_arr(i1, j1, i2, j2);
                        for (long long x = i1; x < i2; x++) {
                            for (long long y = j1; y < j2; y++) {
                                is_blocked[x][y] = true;
                            }
                        }
                        pcl_amount++;
                    }
                }
            }
        }
    }
    for (long long z = n-1; z >= 0; z--) {
        for (long long k = 0; k <= z; k++) {
            long long i = k;
            long long j = z-k;
            for (long long i_pos = 0; i_pos < n-i+1; i_pos++) {
                for (long long j_pos = 0; j_pos < n-j+1; j_pos++) {
                    long long 
                        i1 = i_pos,
                        j1 = j_pos,
                        i2 = i_pos+i,
                        j2 = j_pos+j;

                    long long color_1 = -1, color_2 = -1;
                    long long color_1_amount = 0, color_2_amount = 0;
                    coord color_2_coord;
                    bool is_impossible = false;
                    bool is_contained = true;
                    for (long long x = i1; x < i2; x++) {
                        for (long long y = j1; y < j2; y++) {
                            is_visited[x][y] = false;
                            if (!is_blocked[x][y]) is_contained = false;
                            long long curr_color = arr[x][y];
                            if (color_1 == -1 || curr_color == color_1) {
                                color_1 = curr_color;
                                color_1_amount++;
                            }else if (color_2 == -1 || curr_color == color_2) {
                                color_2 = curr_color;
                                color_2_amount++;
                                color_2_coord = coord(x, y);
                            }else {
                                is_impossible = true;
                                break;
                            }
                        }
                        if (is_impossible) break;
                    }
                    if (is_contained || color_2 == -1 || is_impossible) continue;
                    stack<coord> dfs;
                    dfs.push(coord(i1, j1));
                    is_visited[i1][j1] = true;
                    while (!dfs.empty()) {
                        coord top_coord = dfs.top();
                        dfs.pop();
                        color_1_amount--;
                        for (auto child : top_coord.children()) {
                            if (!child.was_visited() && child.color() == color_1 && child.in_bounds(i1, j1, i2, j2)) {
                                child.visit();
                                dfs.push(child);
                            }
                        }
                    }
                    dfs.push(color_2_coord);
                    is_visited[color_2_coord.x][color_2_coord.y] = true;
                    while (!dfs.empty()) {
                        coord top_coord = dfs.top();
                        dfs.pop();
                        color_2_amount--;
                        for (auto child : top_coord.children()) {
                            if (!child.was_visited() && child.color() == color_2 && child.in_bounds(i1, j1, i2, j2)) {
                                child.visit();
                                dfs.push(child);
                            }
                        }
                    }
                    if (color_1_amount == 0 && color_2_amount == 0) continue;
                    if (color_1_amount == 0) {
                        // cout << color_1_amount << "\n" << color_2_amount << "\n";
                        print_arr(i1, j1, i2, j2);
                        for (long long x = i1; x < i2; x++) {
                            for (long long y = j1; y < j2; y++) {
                                is_blocked[x][y] = true;
                            }
                        }
                        pcl_amount++;
                    }else if (color_2_amount == 0) {
                        // cout << "Printing \n";
                        // cout << color_1_amount << "\n" << color_2_amount << "\n";
                        print_arr(i1, j1, i2, j2);
                        for (long long x = i1; x < i2; x++) {
                            for (long long y = j1; y < j2; y++) {
                                is_blocked[x][y] = true;
                            }
                        }
                        pcl_amount++;
                    }
                }
            }
        }
    }

    cout << pcl_amount;

    return 0;
}
