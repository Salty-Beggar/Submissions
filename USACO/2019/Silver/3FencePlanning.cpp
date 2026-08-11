
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
    void operator=(const cow& _cow) {
        x1 = min(x1, _cow.x);
        y1 = min(y1, _cow.y);
        x2 = max(x2, _cow.x);
        y2 = max(y2, _cow.y);
    }
    long long operator()() {
        return 2*(x2-x1)+2*(y2-y1);
    }
};

long long n, m, monarch[MAX_N];
cow cows[MAX_N];
vector<long long> adj_list[MAX_N];

int main() {
    cin >> n >> m;
    
    for (long long i = 0; i < n; i++) {
        cin >> cows[i].x >> cows[i].y;
    }
    
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    
    
    return 0;
}