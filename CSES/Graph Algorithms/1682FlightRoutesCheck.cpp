
#include <iostream>
#include <vector>
using namespace std;

const long long MAX_N = 100000;
long long n, m;
bool visited[MAX_N];
vector<long long> adj_list[MAX_N], adj_list_inv[MAX_N];

void from_root(long long node) {
    visited[node] = true;
    for (long long child : adj_list[node]) {
        if (!visited[child]) {visited[child] = true; from_root(child);}
    }
}

void into_root(long long node) {
    visited[node] = true;
    for (long long child : adj_list_inv[node]) {
        if (!visited[child]) {visited[child] = true; into_root(child);}
    }
}

int main() {
    cin >> n >> m;
    
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
        adj_list_inv[v].push_back(u);
    }

    from_root(0);
    for (long long i = 1; i < n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << 1 << " " << i+1;
            return 0;
        }
        visited[i] = false;
    }

    into_root(0);
    for (long long i = 1; i < n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << i+1 << " " << 1;
            return 0;
        }
        visited[i] = false;
    }

    cout << "YES";

    return 0;
}
