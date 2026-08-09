
#include <iostream>
#include <functional>
using namespace std;

const long long MAX_N = 60000, PRECISION = 1000000, MAX_VALUE = 1000000000;
const double TOLERANCE = 0.000001;
long long n;
long long coordenates[MAX_N], speeds[MAX_N];

long long minimum_value(long long l, long long r, function<long long(long long)> func) {
    while (l != r-1) {
        long long mid = (l+r)/2;
        if (func(mid-1) > func(mid)) {
            l = mid;
        }else {
            r = mid;
        }
    }
    return func(l);
}

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> coordenates[i];
        coordenates[i] *= PRECISION;
    }
    for (long long i = 0; i < n; i++) {
        cin >> speeds[i];
        speeds[i] *= PRECISION;
    }
    cout << ((double)minimum_value(PRECISION, MAX_VALUE*PRECISION+1, [&](long long meeting_coord) {
        double biggest_time = 0;
        for (long long i = 0; i < n; i++) {
            long long cur_coord = coordenates[i];
            long long cur_speed = speeds[i];
            biggest_time = max(biggest_time, (cur_coord - meeting_coord != 0) ? (abs(cur_coord - meeting_coord)/(double)cur_speed) : 0);
        }
        return biggest_time;
    }))/((double)PRECISION);
}