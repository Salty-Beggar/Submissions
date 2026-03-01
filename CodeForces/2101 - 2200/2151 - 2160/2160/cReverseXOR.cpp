
#include <iostream>
using namespace std;

int t;
long int n;

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        if (n == 0) {
            cout << "YES\n";
            continue;
        }
        while ((n&1) == 0) {
            n >>= 1;
        }
        int bitSize = 0;
        for (int i = 0; (1<<i) <= n; i++) {
            bitSize = i+1;
        }
        if (bitSize%2 == 1 && (n&(1<<(bitSize/2))) != 0) {
            cout << "NO\n";
            continue;
        }
        bool isPalindrome = true;
        // cout << bitSize << "|" << n << "\n";
        for (long int i = 0; i < bitSize/2; i++) {
            long int biggerBit = 1<<(bitSize-i-1);
            long int smallerBit = 1<<(i);
            if (((n&biggerBit) != 0) ^ ((n&smallerBit) != 0)) {
                // cout << biggerBit << "|" << smallerBit << " ";
                cout << "NO\n";
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome) cout << "YES\n";
    }
    return 0;
}
