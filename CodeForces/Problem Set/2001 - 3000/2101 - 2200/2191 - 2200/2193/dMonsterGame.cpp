
#include <algorithm>
#include <iostream>
using namespace std;

int t;
const long int MAX_N = 200000;
long int n, swordArr[MAX_N], monsterArr[MAX_N];

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        for (long int i = 0; i < n; i++) {
            cin >> swordArr[i];
        }
        for (long int i = 0; i < n; i++) {
            cin >> monsterArr[i];
        }
        sort(swordArr, swordArr+n);
        reverse(swordArr, swordArr+n);
        long long int ans = 0;
        long int monsterIndex = 0;
        for (long int i = 0; i < n; i++) {
            monsterArr[monsterIndex]--;
            if (monsterArr[monsterIndex] == 0) {
                monsterIndex++;
                ans = max(ans, (long long int) (((long long int)monsterIndex)*((long long int)swordArr[i])));
            }
        }
        cout << ans << "\n";
    }
}
