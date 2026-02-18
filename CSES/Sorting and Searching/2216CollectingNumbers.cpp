
#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = // Por esse número;
bool pickedNumbers[MAX_N];
int main() {
    long long  int n;
    cin >> n;
    long long int cycleAmnt = 0;
    for (long long int i = 0; i < n; i++) {
        long long int value;
        cin >> value;
        if (value == 1 || !pickedNumbers[value-2]) {
            cycleAmnt++;
        }
        pickedNumbers[value-1] = true;
    }
    cout << cycleAmnt;
    return 0;
}