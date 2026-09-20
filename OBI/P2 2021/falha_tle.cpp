
#include <iostream>
using namespace std;

const long long MAX_N = 20000;
long long n;
string senhas[MAX_N];

bool contem(string word, string sub_word) {
    // if (sub_word.size() > word.size()) return contem(sub_word, word);


    long long n = word.size();
    long long m = sub_word.size();

    for (long long i = 0; i <= n-m; i++) {
        bool possible = true;
        for (long long j = 0; j < m; j++) {
            if (word[i+j] != sub_word[j]) {
                possible = false;
                break;
            }
        }
        if (possible) return true;
    }

    return false;
}

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> senhas[i];
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = i+1; j < n; j++) {
            long long bruh = contem(senhas[i], senhas[j])+contem(senhas[j], senhas[i]);
            ans += bruh;
        }
    }
    cout << ans;
    return 0;
}
