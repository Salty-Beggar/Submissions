
#include <algorithm>
#include <iostream>
using namespace std;

const long long MAX_N = 300000, MODULO = 998244353;
long long n;
pair<long long, long long> meetings[MAX_N];

long long pow(long long value) {
    if (value == 1) return 2;
    return ((pow(value/2)) * (pow((value+1)/2))) % MODULO;
}

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long s, t;
        cin >> s >> t;
        meetings[i] = {s, t};
    }
    sort(meetings, meetings+n);
    long long meeting_streaks = 0;
    long long lower_meeting_end = -1;
    long long upper_meeting_end = -1;
    for (long long i = 0; i < n; i++) {
        pair<long long, long long> cur_meeting = meetings[i];
        if (cur_meeting.first < lower_meeting_end) {
            cout << 0;
            return 0;
        }
        if (cur_meeting.first >= upper_meeting_end) {
            meeting_streaks++;
            lower_meeting_end = -1;
        }else {
            lower_meeting_end = upper_meeting_end;
        }
        upper_meeting_end = cur_meeting.second;
        if (lower_meeting_end > upper_meeting_end) {
            swap(lower_meeting_end, upper_meeting_end);
        }
    }
    cout << pow(meeting_streaks);
}