
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct cow {
    public:
        long long x, y, power;
};

const long long MAX_N = 200;
long long n, visited_cows[MAX_N];
cow cows[MAX_N];
vector<long long> adj_list[MAX_N];

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> cows[i].x >> cows[i].y >> cows[i].power;
        visited_cows[i] = -1;
    }
    
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            if (i == j) continue;
            // if (cows[i].power < cows[j].power) continue;
            long long delta_x = cows[i].x - cows[j].x;
            long long delta_y = cows[i].y - cows[j].y;
            if (delta_x*delta_x+delta_y*delta_y <= cows[i].power*cows[i].power) {
                adj_list[i].push_back(j);
            }
        }
    }
    
    long long max_span = 0;
    for (long long i = 0; i < n; i++) {
        stack<long long> cow_dfs;
        cow_dfs.push(i);
        long long curr_span = 0;
        while (!cow_dfs.empty()) {
            long long curr_cow_index = cow_dfs.top();
            cow_dfs.pop();
            if (visited_cows[curr_cow_index] == i) continue;
            curr_span++;
            visited_cows[curr_cow_index] = i;
            cow curr_cow = cows[curr_cow_index];
            for (const long long child : adj_list[curr_cow_index]) {
                cow_dfs.push(child);
            }
        }
        max_span = max(curr_span, max_span);
    }
    
    cout << max_span << "\n";

    return 0;
}