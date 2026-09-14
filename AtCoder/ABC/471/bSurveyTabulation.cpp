
#include <cctype>
#include <iostream>
#include <string>
#include <set>
using namespace std;

long long n;
set<string> words_set;
multiset<string> words;

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        string word;
        cin >> word;
        for (auto& l : word) {
            l = tolower(l);
        }
        words_set.insert(word);
        words.insert(word);
    }
    long long ans = 0;
    for (const auto word : words_set) {
        string curr_word = word;
        ans = max(ans, (long long)words.count(curr_word));
    }

    cout << ans;

    return 0;
}
