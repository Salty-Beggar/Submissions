
#include <vector>
#include <iostream>
using namespace std;

int t;
long int n;
string sequence;

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> sequence;
        long int z = 0, o = 0;
        for (long int i = 0; i < n; i++) {
            char curChar = sequence[i];

            if (curChar == '0') z++;
            else o++;
        }
        if (z == 0 || o == 0) {
            cout << "Bob\n";
            continue;
        }

        vector<long int> subSeq;
        for (long int i = 0; i < z; i++) { // Extra one's
            char curChar = sequence[i];
            if (curChar == '1') {
                subSeq.push_back(i);
            }
        }
        for (long int i = z; i < n; i++) { // Extra zero's
            char curChar = sequence[i];
            if (curChar == '0') {
                subSeq.push_back(i);
            }
        }

        long int m = subSeq.size();
        if (m == 0) {
            cout << "Bob\n";
            continue;
        }
        cout << "Alice" << "\n" << m << "\n";
        for (long int i = 0; i < m; i++) {
            cout << subSeq[i]+1 << " ";
        }
    }
}