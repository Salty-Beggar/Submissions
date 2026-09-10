
#include <iostream>
#include <string>
#include <queue>
using namespace std;

const long long MAX_N = 100000;
long long n, k;
string arr[MAX_N];
priority_queue<pair<long long, long long>> number_pqueue;

int main() {
    cin >> n >> k;
    long long tail = 0;
    for (long long i = 0; i <n; i++) {
        string num;
        cin >> num;
        arr[i] = num;
        long long length = num.size();
        long long value = stoi(num);
        if (value > stoi(arr[tail])) {
            tail = i;
        }
        number_pqueue.push(make_pair(length, value));
    }
    string ans = to_string(stoi(arr[tail]));
    for (long long i = 0; i < k; i++)  {
        auto top_number = number_pqueue.top();
        number_pqueue.pop();
        ans += to_string(top_number.second);
    }
}
