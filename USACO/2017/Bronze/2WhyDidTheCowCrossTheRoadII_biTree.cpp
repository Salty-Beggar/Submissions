
#include <iostream>

using namespace std;

int startingPoints[26], biTree[27];

// Binary indexed tree
int query(int pos) {
    int sum = 0;
    for (int i = pos+1; i >= 1; i -= i&(-i)) {
        sum += biTree[i];
    }
    return sum;
}
void update(int pos, int value) {
    for (int i = pos+1; i <= 26; i += i&(-i)) {
        biTree[i] += value;
    }
}

int main() {
    for (int i = 0; i < 26; i++) {
        startingPoints[i] = -1;
    }
    string road;
    cin >> road;
    int counter = 0;
    int ans = 0;
    
    for (int i = 0; i < 52; i++) {
        int curChar = road[i]-'A';
        if (startingPoints[curChar] == -1) {
            startingPoints[curChar] = counter;
            update(25-counter, 1);
            counter++;
        }else {
            update(25-startingPoints[curChar], -1);
            /*if (curChar == 0) {
                cout << startingPoints[curChar] << "\n";
                for (int j = 0; j < 26; j++) {
                    cout << biTree[j] << " ";
                }
                cout << "\n";
            }*/
            ans += query(25-startingPoints[curChar]);
        }
    }

    cout << ans << "\n";
}

// ABCABCDEDEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZ