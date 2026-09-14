
#include <bits/stdc++.h>
using namespace std;

int main() {    
    string word;
    cin >> word;
    for (char letter : word) {
        cout << (letter == 'A' ? 'A' : '.');
    }
    return 0;
}
