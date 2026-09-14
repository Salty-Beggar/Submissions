
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct word {
    public:
    string str;
    long long id, length, value;
    word(long long id, string str) : id(id), str(str) {
        length = str.size();
        value = stoi(str);
    }
    bool operator<(const word& other) const {
        return (length != other.length) ? length < other.length : value < other.value;
    }
};

long long MAX_N = 100000;
long long n, k;
priority_queue<word> word_pqueue;

int main() {
    cin >> n >> k;
    long long max_value = -1;
    long long max_value_id = -1;
    for (long long i = 0; i < n; i++) {
        string curr_str;
        cin >> curr_str;
        word curr_word = word(i, curr_str);
        if (curr_word.value > max_value) {
            max_value = curr_word.value;
            max_value_id = curr_word.id;
        }
        word_pqueue.push(curr_word);
    }

    string ans = to_string(max_value);
    for (long long i = 0; i < k; i++) {
        word top_word = word_pqueue.top();
        word_pqueue.pop();
        if (top_word.id == max_value_id) continue;
        ans += top_word.str;
    }
    cout << ans;
}
