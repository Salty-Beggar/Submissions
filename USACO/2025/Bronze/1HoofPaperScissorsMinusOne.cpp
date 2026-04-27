
#include <string>
#include <iostream>

using namespace std;

const int MAX_N = 3000;
int n, m, symbols[MAX_N][MAX_N], symbolWins[MAX_N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string curString;
        cin >> curString;
        for (int j = 0; j <= i; j++) {
            int curValue = (curString[j] == 'D') ? 0 : (curString[j] == 'W' ? 1 : -1);

            symbols[i][j] = -curValue;
            symbols[j][i] = curValue;
            if (curValue == -1) symbolWins[i]++;
            else if (curValue == 1) symbolWins[j]++;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (a==b) cout << symbolWins[a]*n+(symbolWins[a]*n-symbolWins[a]);
        else {
            int commonOnes = 0;
            for (int i = 0; i < n; i++)
                if (symbols[a][i] == 1 && symbols[b][i] == 1) commonOnes++;
            /* cout << symbolWins[a] << " " << symbolWins[b] << " " << commonOnes << "\n"; */

            /* cout << (((symbolWins[a])*(symbolWins[b]))-doubleCounted); */
            /* cout << commonOnes*n; */
            cout << commonOnes*n+(commonOnes*n-commonOnes);
        }
        cout << "\n";
    }

}