
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 500;
int n;
long m, q;
long long adjMatrix[MAX_N][MAX_N];

int main() {
    cin >> n >> m >> q;
    for (long i = 0; i < m; i++) {
        int u, v;
        long w;
        cin >> u >> v >> w;
        u--;
        v--;
        if (adjMatrix[u][v] == 0) {
            adjMatrix[u][v] = w;
            adjMatrix[v][u] = w;
        }else {
            adjMatrix[u][v] = min((long long) w, adjMatrix[u][v]);
            adjMatrix[v][u] = adjMatrix[u][v];
        }
    }
    for (long k = 0; k < n; k++) {
        for (long i = 0; i < n; i++) {
            for (long j = 0; j < n; j++) {
                if (i == j) continue;
                if (adjMatrix[i][k] == 0) continue;
                if (adjMatrix[j][k] == 0) continue;
                long long mediatedCost = adjMatrix[i][k] + adjMatrix[k][j];
                if (adjMatrix[i][j] == 0 || mediatedCost < adjMatrix[i][j]) {
                    adjMatrix[i][j] = mediatedCost;
                    adjMatrix[j][i] = mediatedCost;
                }
            }
        }
    }
    for (long int i = 0; i < q; i++) {
        long u, v;
        cin >> u >> v;
        u--; v--;
        cout << ((u == v) ? 0 : (((adjMatrix[u][v] == 0) ? -1 : adjMatrix[u][v]))) << "\n";
    }
    return 0;
}