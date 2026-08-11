
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const long long MAX_N = 100000, MAX_XY = 100000000;

struct cow {
    public:
        long long x, y;
};

struct span {
    public:
        long long x1, y1, x2, y2;
    span() : x1(MAX_XY+1), y1(MAX_XY+1), x2(-1), y2(-1) {}
    void enlarge(const cow& _cow) {
        x1 = min(x1, _cow.x);
        y1 = min(y1, _cow.y);
        x2 = max(x2, _cow.x+1);
        y2 = max(y2, _cow.y+1);
    }
    void enlarge(const span& other) {
        x1 = min(x1, other.x1);
        y1 = min(y1, other.y1);
        x2 = max(x2, other.x2);
        y2 = max(y2, other.y2);
    }
    explicit operator long long() const {
        return 2*(x2-x1-1)+2*(y2-y1-1);
    }
};

long long n, m, monarch[MAX_N];
cow cows[MAX_N];
span cow_spans[MAX_N];
vector<long long> adj_list[MAX_N];

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    cin >> n >> m;
    
    for (long long i = 0; i < n; i++) {
        monarch[i] = -1;
        cin >> cows[i].x >> cows[i].y;
    }
    
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    long long min_perimeter = MAX_XY*4;
    for (long long i = 0; i < n; i++) {
        if (monarch[i] == -1) {
            monarch[i] = i;
            stack<long long> cow_dfs;
            cow_dfs.push(i);
            while (!cow_dfs.empty()) {
                long long curr_cow_index = cow_dfs.top();
                cow_dfs.pop();
                cow curr_cow = cows[curr_cow_index];
                cow_spans[i].enlarge(curr_cow);
                for (const auto child : adj_list[curr_cow_index]) {
                    if (monarch[child] == -1) {
                        cow_dfs.push(child);
                        monarch[child] = i;
                    }else if (monarch[child] != i) {
                        cow_spans[i].enlarge(
                            cow_spans[monarch[child]]
                        );
                    }
                }
            }
            min_perimeter = min(min_perimeter, (long long) cow_spans[i]);
        }
    }

    cout << min_perimeter;
    
    return 0;
}