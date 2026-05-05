
#include <iostream>

const int MAX_N = 1000;
int n, beauty[MAX_N][MAX_N];
long int beautyRows[MAX_N][2], beautyColumns[MAX_N][2];

using namespace std;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> beauty[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            beautyRows[i][j%2] += beauty[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            beautyColumns[j][i%2] += beauty[i][j];
        }
    }

    long int rowSum = 0;
    long int columnSum = 0;
    for (int i = 0; i < n; i++) {
        rowSum += max(beautyRows[i][0], beautyRows[i][1]);
        columnSum += max(beautyColumns[i][0], beautyColumns[i][1]);
    }

    cout << max(rowSum, columnSum);

}