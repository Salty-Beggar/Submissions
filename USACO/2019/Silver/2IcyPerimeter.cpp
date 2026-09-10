
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

const long long MAX_N = 1000;
long long n;
bool visited[MAX_N+2][MAX_N+2], is_wall[MAX_N+2][MAX_N+2];

struct coord {
    public:
    long long x, y;
    coord(long long x, long long y) : x(x), y(y) {}
    operator bool() const {
        return visited[x][y];
    }
};

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    for (long long i = 0; i < n+2; i++) {
        for (long long j = 0; j < n+2; j++) {
            if (i == 0 || i == n+1 || j == 0 || j == n+1) {
                is_wall[i][j] = true;
                continue;
            }
            char cell;
            cin >> cell;
            is_wall[i][j] = cell == '.';
        }
    }
    n += 2;
    // for (long long i = 0; i < n; i++) {
    //     for (long long j = 0; j < n; j++) {
    //         cout << (is_wall[i][j] ? '.' : '#');
    //     }
    //     cout << "\n";
    // }

    pair<long long, long long> max_ice = {0, 0};
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            if (is_wall[i][j] || visited[i][j]) continue;
            visited[i][j] = true;
            long long curr_area = 0;
            long long curr_perimeter = 0;
            stack<coord> dfs;
            dfs.push(coord(i, j));
            while (!dfs.empty()) {
                curr_area++;
                coord top_coord = dfs.top();
                long long x = top_coord.x;
                long long y = top_coord.y;
                dfs.pop();
                if (is_wall[x+1][y]) {
                    curr_perimeter++;
                }else if (!visited[x+1][y]) {
                    visited[x+1][y] = true;
                    dfs.push(coord(x+1, y));
                }
                if (is_wall[x-1][y]) {
                    curr_perimeter++;
                }else if (!visited[x-1][y]) {
                    visited[x-1][y] = true;
                    dfs.push(coord(x-1, y));
                }
                if (is_wall[x][y+1]) {
                    curr_perimeter++;
                }else if (!visited[x][y+1]) {
                    visited[x][y+1] = true;
                    dfs.push(coord(x, y+1));
                }
                if (is_wall[x][y-1]) {
                    curr_perimeter++;
                }else if (!visited[x][y-1]) {
                    visited[x][y-1] = true;
                    dfs.push(coord(x, y-1));
                }
            }
            pair<long long, long long> curr_ice = {curr_area, curr_perimeter};
            if (curr_ice.first == max_ice.first) {
                if (curr_ice.second < max_ice.second) {
                    max_ice = curr_ice;
                }
                continue;
            }
            max_ice = max(max_ice, curr_ice);
        }
    }

    cout << max_ice.first << " " << max_ice.second;

    return 0;
}
