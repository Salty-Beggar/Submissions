
#include <iostream>
using namespace std;

const long int MAX_N = 300000;
int t;
long int n, minProducts[MAX_N+1];
bool sieve[MAX_N+1];

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        for (long int i = 1; i <= n; i++) {
            minProducts[i] = 0;
            sieve[i] = false;
        }
        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
            minProducts[x] = 1;
        }
        #pragma region Erasthotenes Sieve

            long int curNumber = 2;
            for (long int i = 2; i <= n; i++) {
                if (!sieve[i] && minProducts[i] != 0) {
                    sieve[i] = true;
                    for (long int j = 1; j*i <= n; j++) {
                        if (j == 1) continue;
                        if (minProducts[j] != 0) {
                            long int newMin = minProducts[j]+1;
                            if (minProducts[j*i] == 0 || newMin < minProducts[j*i]) {
                                minProducts[j*i] = newMin;
                                sieve[j*i] = true;
                            }
                        }
                    }
                }
            }

        #pragma endregion

        for (long int i = 1; i <= n; i++) {
            cout << ((minProducts[i] == 0) ? -1 : minProducts[i]) << " ";
        }
        cout << "\n";
    }
}
