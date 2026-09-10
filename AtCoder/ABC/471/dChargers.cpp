
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long MAX_Q = 300000;
priority_queue<
    long long,
    vector<long long>,
    greater<long long>
> plugged_batteries;
// priority_queue<long long> off_batteries;
long long q, v;

int main() {
    cin >> q >> v;
    for (long long i = 0; i < q; i++) {
        long long type;
        cin >> type;
        if (type == 1) {
            long long t, w;
            cin >> t >> w;
            plugged_batteries.push(t - w);
        }else {
            long long t;
            cin >> t;
            if (plugged_batteries.empty()) {
                cout << "-1\n";
                continue;
            }
            long long top_battery = plugged_batteries.top();
            plugged_batteries.pop();
            cout << min(v, t - top_battery) << "\n";
        }
    }

    return 0;
}