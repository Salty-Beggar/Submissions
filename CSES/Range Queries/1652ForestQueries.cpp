
#include <iostream>
using namespace std;

const long int MAX_N = 1000;
long int n, q, treeSums[MAX_N][MAX_N];

int main() {
    cin >> n >> q;
    for (long int i = 0; i < n; i++) {
        for (long int j = 0; j < n; j++) {
            char curChar;
            cin >> curChar;
            treeSums[i][j] = (curChar == '.') ? 0 : 1;
            if (i != 0) treeSums[i][j] += treeSums[i-1][j];
            if (j != 0) treeSums[i][j] += treeSums[i][j-1];
            if (i != 0 && j != 0) treeSums[i][j] -= treeSums[i-1][j-1];
        }
    }
    /*for (long int i = 0; i < n; i++) {
        for (long int j = 0; j < n; j++) {
            cout << treeSums[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/
    for (long int i = 0; i < q; i++) {
        long int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;
        x1--;
        y2--;
        x2--;
        long int queryResult = treeSums[y2][x2];
        long int horizontalSub = (y1 == 0) ? 0 : treeSums[y1-1][x2];
        long int verticalSub = (x1 == 0) ? 0 : treeSums[y2][x1-1];
        long int intersectionAdd = (x1 == 0 || y1 == 0) ? 0 : treeSums[y1-1][x1-1];
        cout << queryResult-horizontalSub-verticalSub+intersectionAdd << "\n";
    }
    
}