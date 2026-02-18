
#include <iostream>
using namespace std;

const int MAX_N = 5000;
int t, balls[MAX_N][3], ballsPossibilities[MAX_N][2];

int main() {
    for (cin >> t; t > 0; t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> balls[i][0];
            ballsPossibilities[i][0] = true;
        }
        for (int i = 0; i < n; i++) {
            cin >> balls[i][1];
            ballsPossibilities[i][1] = true;
        }
        for (int i = 0; i < n; i++) {
            cin >> balls[i][2];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (balls[(i+j)%n][0] >= balls[i][1]) {
                    ballsPossibilities[j][0] = false;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (balls[(i+j)%n][1] >= balls[i][2]) {
                    ballsPossibilities[j][1] = false;
                }
            }
        }

        long int countAB = 0;
        for (int i = 0; i < n; i++) {
            if (ballsPossibilities[i][0])
                countAB++;
        }
        long long int ans = 0;
        for (int i = 0; i < n; i++) {
            if (ballsPossibilities[i][1])
                ans += countAB;
        }
        ans *= n;
        cout << ans << "\n";
    }
    return 0;
}