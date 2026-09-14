
#include <bits/stdc++.h>
using namespace std;

const long long MAX_HW = 500000;
long long h, w, k;
bool bombed_lines[MAX_HW][2];
// 0 - Rows | 1 - Columns
vector<long long> matrix[MAX_HW];
// 0 - Initially empty cell | 1 - Bomb cell | 2 - Visited empty cell

struct coord {
    public:
    long long x, y;
    coord(long long x, long long y) : x(x), y(y) {}
    vector<coord> children() {
        vector<coord> new_children;
        if (x-1 >= 0 && matrix[x-1][y] != 1) new_children.push_back(coord(x-1, y));
        if (y-1 >= 0 && matrix[x][y-1] != 1) new_children.push_back(coord(x, y-1));
        if (x+1 < h && matrix[x+1][y] != 1) new_children.push_back(coord(x+1, y));
        if (y+1 < w && matrix[x][y+1] != 1) new_children.push_back(coord(x, y+1));
        return new_children;
    }
    bool visited() {
        return matrix[x][y] != 0;
    }
    void visit() {
        matrix[x][y] = 2;
    }
};

int main() {
    cin >> h >> w >> k;

    for (long long i = 0; i < h; i++) {
        string curr_row;
        cin >> curr_row;
        long long j = 0;
        for (char cell : curr_row) {
            matrix[i].push_back(
                cell == '.'
                    ? 0
                    : 1
            );
            if (cell == '#') {
                bombed_lines[i][0] = true;
                bombed_lines[j][1] = true;
            }
            j++;
        }
    }

    queue<coord> bfs;
    for (long long i = 0; i < h; i++) {
        for (long long j = 0; j < w; j++) {
            if (!bombed_lines[i][0] && !bombed_lines[j][1]) {
                matrix[i][j] = 2;
                bfs.push(coord(i, j));
            }
        }
    }

    long long ans = 0;
    while (k >= 0 && !bfs.empty()) {
        long long curr_layer = bfs.size();
        for (long long i = 0; i < curr_layer; i++) {
            coord top_coord = bfs.front();
            bfs.pop();
            ans++;
            for (coord child : top_coord.children()) {
                if (!child.visited()) {
                    bfs.push(child);
                    child.visit();
                }
            }
        }
        k--;
    }

    cout << ans;
    return 0;
}  
