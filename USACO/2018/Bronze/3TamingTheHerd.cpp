
#include <iostream>
#include <cstdio>

using namespace std;

int n, days[100];

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }
    if (days[0] > 0) {
        cout << -1;
        return 0;
    }
    days[0] = 0;
    bool blocking = days[n-1] == -1;
    int ansMin = 0;
    int ansMax = 0;
    for (int i = n-1; i >= 0; i--) {
        int curDay = days[i];
        if (curDay == -1) {
            if (i == n-1 || days[i+1] == 0) {
                ansMax++;
                if (!blocking) {
                    blocking = true;
                    ansMin++;
                }
                days[i] = 0;
            }else {
                days[i] = days[i+1]-1;
                if (days[i] == 0) {
                    ansMin++;
                    ansMax++;
                    blocking = true;
                }else {
                    blocking = false;
                }
            }
        }else {
            if (i != n-1 && days[i+1] != 0 && days[i] != days[i+1]-1) {
                cout << -1;
                return 0;
            }
            if (days[i] == 0) {
                ansMin++;
                ansMax++;
                blocking = true;
            }else {
                blocking = false;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << days[i] << " ";
    // }
    // cout << "\n";
    cout << ansMin << " " << ansMax;
    return 0;
}