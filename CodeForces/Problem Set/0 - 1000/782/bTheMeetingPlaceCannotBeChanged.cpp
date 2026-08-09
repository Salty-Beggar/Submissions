
#include <iostream>
#include <functional>
using namespace std;

const long long MAX_N = 60000;
const double TOLERANCE = 0.000001;
long long n;
double coordenates[MAX_N], speeds[MAX_N];

double minimum_value(double l, double r, function<double(double)> func) {
    while (abs(l-r) > TOLERANCE) {
        double mid = (l+r)/2.0;
        if (func(mid) > func(mid+TOLERANCE)) {
            l = mid;
        }else {
            r = mid;
        }
    }
    return func(r);
}

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> coordenates[i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> speeds[i];
    }
    cout << fixed << minimum_value(1.0, 1000000000.0+TOLERANCE, [&](double meeting_coord) {
        double biggest_time = 0.0;
        for (long long i = 0; i < n; i++) {
            double cur_coord = coordenates[i];
            double cur_speed = speeds[i];
            biggest_time = max(biggest_time, (cur_coord - meeting_coord != 0.0) ? abs(cur_coord - meeting_coord)/cur_speed : 0);
        }
        return biggest_time;
    });
}