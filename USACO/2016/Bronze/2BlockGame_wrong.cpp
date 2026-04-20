
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int n, letters1[26], letters2[26];
string words[100][2];

int main() {
    // freopen("blocks.in", "r", stdin);
    // freopen("blocks.out", "w", stdout);

    cin >> n;
    int curLetters[26];
    for (int i = 0; i < n; i++) {
        string word1, word2;
        cin >> word1 >> word2;
        words[i][0] = word1;
        words[i][1] = word2;
    }

    for (int i = 0; i < n; i++) {
        string curWord = words[i][0];
        int k = curWord.length();
        for (int j = 0; j < k; j++) {
            letters1[curWord[j]-'a']++;
        }
    }

    for (int i = 0; i < n; i++) {
        string curWord = words[i][1];
        int k = curWord.length();
        for (int j = 0; j < k; j++) {
            letters2[curWord[j]-'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << max(letters1[i], letters2[i]) << "\n";
    }

    return 0;
}