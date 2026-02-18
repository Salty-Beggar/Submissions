
#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX_N = 200000, MAX_LOGN = 19;
long int n, q;
long long int heap[MAX_N][MAX_LOGN];

int main() {
    cin >> n >> q;
    for (long int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        heap[i][0] = x;
    }
    for (long int j = 1; j < MAX_LOGN; j++) {
        long int diff = 1<<(j-1);
        for (long int i = 0; i < n; i++) {
            long int iPrev = (i + diff)%n;
            heap[i][j] = min(heap[i][j-1], heap[iPrev][j-1]);
        }
    }

    for (long int i = 0; i < q; i++) {
        long int a, b;
        cin >> a >> b;
        a--;
        b--;
        long int diff = b-a+1;
        long int curIndex = a;
        long long int curMin = heap[a][0];
        for (long int j = MAX_LOGN-1; j >= 0; j--) {
            long int curBit = 1L<<j;
            if ((diff & curBit) != 0L) {
                curMin = min(curMin, heap[curIndex][j]);
                curIndex += curBit;
                curIndex %= n;
            }
        }
        cout << curMin << "\n";
    }

    return 0;
}