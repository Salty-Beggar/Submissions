
#include <string>
#include <iostream>

using namespace std;

const int MAX_N = 3000;
int n, m, winMap[MAX_N][MAX_N];


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string curString;
        cin >> curString;
        for (int j = 0; j <= i; j++) {
            char curChar = curString[j];
            int curValue = (curChar == 'W') ? 1 : -1;
            if (curChar == 'D') curValue = 0;
            winMap[i][j] = curValue;
            winMap[j][i] = -curValue;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        long int ans = 0;
        long int usedHoofs = 1;
        for (int i = 0; i < n; i++) {
            if (winMap[i][a] == 1 && winMap[i][b] == 1) {
                ans += n*2-usedHoofs;
                usedHoofs += 2;
            }
        }
        cout << ans << "\n";
    }
}