
#include <iostream>
using namespace std;

const long int MAX_N = 200000, LI_BITMASK = 16777215;
int t;
long int n, arrA[MAX_N], arrB[MAX_N];

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        long int validRowsBitmask = 0;
        long int advantageBitmask = 0; /*
        For a valid row:
            0 - Ajisai
            1 - Mai
        */
        long int aBitmask = 0;
        long int bBitmask = 0;

        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
            arrA[i] = x;
            aBitmask = aBitmask^arrA[i];
        }
        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
            arrB[i] = x;
            bBitmask = bBitmask^arrB[i];
            long int diffParityBitmasks = arrA[i]^arrB[i];
            validRowsBitmask = validRowsBitmask|diffParityBitmasks;
            if ((i%2) == 0) { // Ajisai's turn
                advantageBitmask = advantageBitmask&(LI_BITMASK^diffParityBitmasks);
            }else { // Mai's turn
                advantageBitmask = advantageBitmask|diffParityBitmasks;
            }
        }
        validRowsBitmask = validRowsBitmask&(aBitmask^bBitmask);
        if (validRowsBitmask == 0) {
            cout << "Tie\n";
            continue;
        }
        bool bamn = false;
        for (long int i = 30; i >= 0; i--) {
            long int curBit = 1<<i;
            if ((validRowsBitmask&curBit) != 0) {
                if ((advantageBitmask&curBit) == 0) { // Ajisai won
                    cout << "Ajisai\n";
                    break;
                }else { // Mai won
                    cout << "Mai\n";
                    break;
                }
            }
        }
    }
}
