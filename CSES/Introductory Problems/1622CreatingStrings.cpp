
#include <iostream>
#include <string>

using namespace std;

int n, letterAmount[26];
string word;

void _solve(int index, string curPerm) {
    if (index == n) {
        cout << curPerm+"\n";
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (letterAmount[i] == 0) continue;
        // cout << "|" << ((char)('a'+i)) << "|";
        letterAmount[i]--;
        char curChar = 'a'+i;
        _solve(index+1, curPerm+curChar);
        letterAmount[i]++;
    }
}

int main() {    
    cin >> word;
    n = word.length();
    int permAmount = 1;
    int permDiv = 1;
    for (int i = 0; i < n; i++) {
        permAmount *= i+1;
        letterAmount[word[i]-'a']++;
        // cout << (word[i]-'a');
        permDiv *= letterAmount[word[i]-'a'];
    }
    cout << permAmount/permDiv << "\n";
    _solve(0, "");
}