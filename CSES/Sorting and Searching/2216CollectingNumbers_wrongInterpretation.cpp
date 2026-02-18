
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// In this solution, I interpreted that you could only collect numbers in an ascending order in each round, without necessarily being consecutive.
// It actually does solve it for that different interpretation.

vector<long int> lds; // longest decreasing subsequence

long int my_upper_bound(long int value) {
    long int n = size(lds);
    long int l = 0;
    long int r = n+1;
    while (l != r-1) {
        long int m = (l+r-1)/2;
        if (value > lds[m]) {
            r = m+1;
        }else {
            //cout << value << " ";
            l = m+1;
        }
        
    }
    return l;
}

int main() {
    long int n;
    cin >> n;

    for (long int i = 0; i < n; i++) {
        long int value;
        cin >> value;
        long int upperBound = my_upper_bound(value);
        if (upperBound == (long int) size(lds)) lds.push_back(value);
        else lds[upperBound] = value;
    }
    cout << size(lds);
    return 0;
}