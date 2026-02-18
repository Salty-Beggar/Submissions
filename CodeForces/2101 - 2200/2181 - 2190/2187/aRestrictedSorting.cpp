
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int t;
long int n;

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n;
        vector<long long int> ogVector, targVector;
        long long int minX = -1, maxX = -1;
        for (long int i = 0; i < n; i++) {
            long long int x;
            cin >> x;
            ogVector.push_back(x);
            targVector.push_back(x);
            minX = (minX == -1) ? x : min(minX, x);
            maxX = (maxX == -1) ? x : max(maxX, x);
        }
        sort(targVector.begin(), targVector.end());
        long long int k = -1;
        for (long int i = 0; i < n; i++) {
            if (ogVector[i] != targVector[i]) {
                k = (k == -1) ? min(max(maxX-ogVector[i], ogVector[i]-minX), max(maxX-targVector[i], targVector[i]-minX)) : min(k, min(max(maxX-ogVector[i], ogVector[i]-minX), max(maxX-targVector[i], targVector[i]-minX)));
            }
        }
        cout << k << "\n";
    }
    return 0;
}
