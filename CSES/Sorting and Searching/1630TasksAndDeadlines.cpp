#include <iostream>
#include <algorithm>
#include <span>
using namespace std;

const long long MAX_N = 200000;
long long n, ans;
pair<long long, long long> tasks[MAX_N];

int main()
{
    cin >> n;

    for (long long i = 0; i < n; i++) {
        long long a, d;
        cin >> a >> d;
        ans += d;
        tasks[i] = {a, d};
    }
    sort(tasks, tasks+n);

    long long cur_sub = 0;
    for (auto[cur_duration, cur_deadline] : span(tasks).subspan(0, n)) {
        cur_sub += cur_duration;
        ans -= cur_sub;
    }

    cout << ans;

    return 0;
}