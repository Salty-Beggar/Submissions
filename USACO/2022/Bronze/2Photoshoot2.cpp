
#include <iostream>

const long int MAX_N = 100000;
long int n, srcArr[MAX_N], targArr[MAX_N];
bool visited[MAX_N+1];

using namespace std;

int main() {
    cin >> n;
    for (long int i = 0; i < n; i++) {
        cin >> srcArr[i];
    }
    for (long int i = 0; i < n; i++) {
        cin >> targArr[i];
    }
    long int srcPointer = 0;
    long int targPointer = 0;
    long int ans = n;
    while (targPointer != n) {
        visited[targArr[targPointer]] = true;
        // cout << targArr[targPointer] << " " << srcArr[srcPointer] << "\n";
        if (srcArr[srcPointer] != targArr[targPointer]) {
            targPointer++;
            continue;
        }
        targPointer++;
        // cout << targPointer << ": ";
        // for (long int i = 0; i < n; i++) {
        //     cout << visited[i] << " ";
        // }
        // cout << "\n";
        // cout << "shwa ";
        while (visited[srcArr[srcPointer]]) {
            // cout << "la ";
            srcPointer++;
            if (srcPointer == n) break;
        }
        // cout << " :" << srcPointer << "\n";
        ans--;
    }
    cout << ans;
    return 0;
}