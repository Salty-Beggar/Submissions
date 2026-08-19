
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const long long MAX_N = 100;
long long n, k, r;
bool is_visited[MAX_N][MAX_N];

struct coord {
    public:
    long long x, y;
    vector<coord> adj_list;
    coord() : x(0), y(0) {}
    coord(long long x, long long y) : x(x), y(y) {
        if (x >= 0) adj_list.push_back(coord(x-1, y));
        if (y >= 0) adj_list.push_back(coord(x, y-1));
        if (x < n) adj_list.push_back(coord(x+1, y));
        if (y < n) adj_list.push_back(coord(x, y+1));
    }
    void block_left() {
        for (auto child : adj_list) {
            if (child.x == x-1) {
                // RIGHT_NOW: Think of a way to store the blocks conveniently.
            }
        }
    }
}

coord arr[MAX_N][MAX_N];

int main() {
    cin >> n >> k >> r;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            arr[i][j] = coord(i, j);
        }
    }

    for (long long i = 0; i < r; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        else if (y1 > y2) swap(y1, y2);
        if (x1 != x2) {

        }
    }
}
