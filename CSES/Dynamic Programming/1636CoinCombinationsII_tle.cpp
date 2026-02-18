
#include <iostream>
#include <algorithm>
using namespace std;

// Aplicar o algoritmo que você descobriu, com 2 estados: x e n, no qual, em dp[x][n], você sabe todas as combinações (ordenadas) de como compor x, somente com moedas abaixo do valor coins[n].

const long int MODULO = 1000000007;
const int MAX_N = 100;
const long int MAX_X = 1000000;

int n;
long int dp[MAX_N][MAX_X+1];
long int x, coins[MAX_N];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        dp[i][coins[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (i-1 >= 0) dp[i][j] += dp[i-1][j];
            if (dp[i][j] >= MODULO) dp[i][j] %= MODULO;
            long int c = coins[i];
            if (j - c > 0) {
                dp[i][j] += dp[i][j-c];
                if (dp[i][j] >= MODULO) dp[i][j] %= MODULO;
            }
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            cout << dp[j][i] << " ";
        }
        cout << "\n";
    }*/
    cout << dp[n-1][x];
    return 0;
}