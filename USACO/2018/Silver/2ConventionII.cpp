
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

struct cow {
    public:
        long long arrival, duration, seniority;
    cow() : arrival(0), duration(0), seniority(0) {}
    cow(long long arrival, long long duration, long long seniority) : arrival(arrival), duration(duration), seniority(seniority) {}
    bool operator <(const cow& b) const {
        return seniority > b.seniority;
    }
};

const long long MAX_N = 100000;
long long n;
cow cows[MAX_N];
priority_queue<cow> cow_queue;

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cows[i].seniority = i;
        cin >> cows[i].arrival >> cows[i].duration;
    }
    sort(cows, cows+n, [](cow a, cow b) {
        return (a.arrival != b.arrival) ? a.arrival < b.arrival : a < b;
    });

    long long freeing_time = -1;
    long long max_waiting_time = 0;
    for (long long i = 0; i < n; i++) {
        cow curr_cow = cows[i];
        while (!cow_queue.empty() && curr_cow.arrival > freeing_time) {
            cow top_cow = cow_queue.top();
            cow_queue.pop();
            max_waiting_time = max(max_waiting_time, freeing_time - top_cow.arrival);
            freeing_time += top_cow.duration;
            freeing_time = max(freeing_time, top_cow.arrival+top_cow.duration);
        }
        cow_queue.push(curr_cow);
    }
    while (!cow_queue.empty()) {
        cow top_cow = cow_queue.top();
        cow_queue.pop();
        max_waiting_time = max(max_waiting_time, freeing_time - top_cow.arrival);
        freeing_time += top_cow.duration;
        freeing_time = max(freeing_time, top_cow.arrival+top_cow.duration);
    }
    cout << max_waiting_time;
}
