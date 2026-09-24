
#include <iostream>
using namespace std;

const long long MAX_N = 20000;
long long n;
string senhas[MAX_N];

long long contem(string word, string sub_word) {
    if (sub_word.size() > word.size()) return contem(sub_word, word);

    long long n = word.size();
    long long m = sub_word.size();

    long long sub_curr = 0;
    long long sub_repeat = -1;
    for (long long i = 0; i < n; i++) {
        if (word[i] != sub_word[sub_curr]) {
            cout << sub_curr << " " << sub_repeat << "\n";
            if (sub_repeat != -1) {
                sub_curr = sub_repeat+1;
                sub_repeat -= sub_curr - sub_repeat;
                sub_repeat++;
                continue;
            }
            sub_repeat = -1;
            sub_curr = 0;
            if (word[i] == sub_word[0]) {
                sub_curr = 1;
                if (sub_word[1] == sub_word[0]) {
                    sub_repeat = 0;
                }
            }
            // if (n-1-i < m) {
            //     return 0;
            // }
        }else {
            if (sub_repeat != -1) {
                if (sub_word[sub_repeat] == sub_word[sub_curr]) {
                    sub_repeat++;
                } else {
                    sub_repeat = -1;
                }
            } else {
                if (sub_word[sub_curr] == sub_word[0]) {
                    sub_repeat = 0;
                }
            }
            sub_curr++;
            if (sub_curr == m) {
                return n == m ? 2 : 1;
            }
        }
    }

    return 0;
}

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> senhas[i];
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = i+1; j < n; j++) {
            long long bruh = contem(senhas[i], senhas[j]);
            ans += bruh;
        }
    }
    cout << ans;
    return 0;
}
