
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const long long MAX_N = 200000;
long long n, arrivals[MAX_N], room_order[MAX_N];
priority_queue<
    pair<long long, long long>, 
    vector<pair<long long, long long>>, 
    greater<pair<long long, long long>>
> departures;
pair<pair<long long, long long>, long long> customers[MAX_N];

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        arrivals[i] = a;
        customers[i] = {{a, b}, i};
    }
    sort(arrivals, arrivals+n);
    sort(customers, customers+n);
    departures.push({0, 1});
    long long k = 1;
    for (long long i = 0; i < n; i++) {
        auto cur_customer = customers[i].first;
        pair<long long, long long> soonest_departure = departures.top();
        // cout << soonest_departure.first << " ";
        if (cur_customer.first > soonest_departure.first) {
            departures.pop();
            departures.push(make_pair(cur_customer.second, soonest_departure.second));
            room_order[customers[i].second] = soonest_departure.second;
        }else {
            long long next_room = departures.size()+1;
            departures.push(make_pair(cur_customer.second, next_room));
            k = max(k, next_room);
            room_order[customers[i].second] = next_room;
        }
    }
    cout << k << "\n";
    for (long long i = 0; i < n; i++) {
        cout << room_order[i] << " ";
    }
}
