
#include <iostream>
using namespace std;

const long int MAX_NMK = 100000;
long int n, m, k, arr[MAX_NMK], operations[MAX_NMK][3], operationIArr[MAX_NMK+1];
long long int intervalArr[MAX_NMK+1];
// The first one is for effects on the array.
// The second one if for how many times each operation is applied.

int main() {
    cin >> n >> m >> k;
    for (long int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (long int i = 0; i < m; i++) {
        cin 
            >> operations[i][0]
            >> operations[i][1]
            >> operations[i][2]
        ;
        operations[i][0]--;
    }
    for (long int i = 0; i < k; i++) {
        long int l, r;
        cin >> l >> r;
        l--;
        operationIArr[l]++;
        operationIArr[r]--;
    }
    long int curMultiplier = 0;
    for (long int i = 0; i < m; i++) {
        curMultiplier += operationIArr[i];
        long int curL = operations[i][0];
        long int curR = operations[i][1];
        long long int curValue = ((long long int)curMultiplier)*((long long int) operations[i][2]);
        intervalArr[curL] += curValue;
        intervalArr[curR] -= curValue;
    } 
    long long int curAdd = 0;
    for (long int i = 0; i < n; i++) {
        curAdd += intervalArr[i];
        cout << ((long long int) arr[i])+curAdd << " ";
    }
    cout << "\n";
    return 0;
}