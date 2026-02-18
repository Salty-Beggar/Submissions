
#include <iostream>
#include <string>
using namespace std;

int t, j, k;
string n;

int main() {
    cin >> t;
    int permutations1[] = {12, 21};
    int permutations2[] = {123, 132, 213, 231, 312, 321};
    int permutations3[] = {1234, 1243, 1324, 1342, 1423, 1432, 2134, 2143, 2314, 2341, 2413, 2431, 3124, 3142, 3214, 3241, 3412, 3421, 4123, 4132, 4213, 4231, 4312, 4321};
    for (; t > 0; t--) {
        cin >> n >> j >> k;
        j--; k--;
        string permJ, permK;
        int amnt = 0;
        if (n == "12") {
            permJ = to_string(permutations1[j]);
            permK = to_string(permutations1[k]);
        }else if (n == "123") {
            permJ = to_string(permutations2[j]);
            permK = to_string(permutations2[k]);
        }else {
            permJ = to_string(permutations3[j]);
            permK = to_string(permutations3[k]);
        }

        for (int i = 0; i < permJ.size(); i++) {
            if (permJ[i] == permK[i])
                amnt++;
        }
        cout << amnt << "A" << permJ.size()-amnt << "B\n";
    }
}