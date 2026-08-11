
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long MAX_N = 100000;
long long n, m, flight_status[MAX_N];
// -1 Root doesn't reach. | 0 Root and node reaches themselves. | 1 Node doesn't reach root.
vector<long long> adj_list[MAX_N];
queue<long long> pendent_cities;

void solve(long long curr_index) {
    flight_status[curr_index] = 2;
    for (const long long child : adj_list[curr_index]) {
        if (child == 0 || flight_status[child] == 0) {
            flight_status[curr_index] = 0;
            continue;
        }
        if (flight_status[child] == 2) {
            pendent_cities.push(curr_index);
            return;
        }
        if (flight_status[child] == -1) {
            solve(child);
        }
    }
    if (flight_status[curr_index] == 2) flight_status[curr_index] = 1;
}

int main() {
    // RIGHT_NOW: Make the pendent status work correctly.
    cin >> n >> m;
    for (long long i = 0; i < m; i++) {
        flight_status[i] = -1;
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
    }

    solve(0);
    while (!pendent_cities.empty()) {
        solve(pendent_cities.back());
        pendent_cities.pop();
    }

    for (long long i = 1; i < n; i++) {
        if (flight_status[i] == -1) {
            cout << "NO\n";
            cout << 1 << " " << i+1;
            return 0;
        }else if (flight_status[i] == 1) {
            cout << "NO\n";
            cout << i+1 << " " << 1;
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
