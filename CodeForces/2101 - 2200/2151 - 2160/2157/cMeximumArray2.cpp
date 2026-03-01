
#include <iostream>
using namespace std;

const int MAX_N = 100;
int t, n, k, q, hasMinTuple[MAX_N+1], hasMEXTuple[MAX_N+1];

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> k >> q;
        for (int i = 0; i < n; i++) {
            hasMinTuple[i] = 0;
            hasMEXTuple[i] = 0;
        }
        for (int i = 0; i < q; i++) {
            int type, l, r;
            cin >> type >> l >> r;
            l--;
            if (type == 1) {
                hasMinTuple[l]++;
                hasMinTuple[r]--;
            }else {
                hasMEXTuple[l]++;
                hasMEXTuple[r]--;
            }
        }
        int hasMinStack = 0;
        int hasMEXStack = 0;
        int meximumArr[n];
        int mexValue = 0;
        for (int i = 0; i < n; i++) {
            hasMinStack += hasMinTuple[i];
            hasMEXStack += hasMEXTuple[i];
            if (hasMinStack != 0 && hasMEXStack != 0) {
                meximumArr[i] = k+1;
            }else if (hasMinStack != 0) {
                meximumArr[i] = k;
            }else {
                meximumArr[i] = mexValue;
                mexValue++;
                mexValue %= k;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << meximumArr[i] << " ";
        }
        cout << "\n";
    }
}
