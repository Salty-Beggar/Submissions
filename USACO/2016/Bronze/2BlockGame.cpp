
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int n, letters[26];
string words[100][2];

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string word1, word2;
        cin >> word1 >> word2;
        int k = word1.length();

        int curLetters[26];
        for (int j = 0; j < 26; j++) curLetters[j] = 0;
        for (int j = 0; j < k; j++) {
            curLetters[word1[j]-'a']++;
        }

        k = word2.length();
        int curLetters2[26];
        for (int j = 0; j < 26; j++) curLetters2[j] = 0;
        for (int j = 0; j < k; j++) {
            curLetters2[word2[j]-'a']++;
        }

        for (int j = 0; j < 26; j++) letters[j] += max(curLetters[j], curLetters2[j]);
    }

    // for (int i = 0; i < n; i++) {
    //     string curWord = words[i][0];
    //     int k = curWord.length();
    //     for (int j = 0; j < k; j++) {
    //         letters1[curWord[j]-'a']++;
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     string curWord = words[i][1];
    //     int k = curWord.length();
    //     for (int j = 0; j < k; j++) {
    //         letters2[curWord[j]-'a']++;
    //     }
    // }

    for (int i = 0; i < 26; i++) {
        cout << letters[i] << "\n";
    }

    return 0;
}