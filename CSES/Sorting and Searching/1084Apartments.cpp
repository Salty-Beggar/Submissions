
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    long long int k;
    vector<long long int> applicants, apartments;

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        long long int value;
        cin >> value;
        applicants.push_back(value);
    }
    for (int i = 0; i < m; i++) {
        long long int value;
        cin >> value;
        apartments.push_back(value);
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    vector<long long int>::iterator appIt = applicants.begin();
    vector<long long int>::iterator apaIt = apartments.begin();

    int settledApps = 0;
    while (appIt != applicants.end() && apaIt != apartments.end()) {
        while (*appIt - *apaIt > k) {
            apaIt++;
            if (apaIt == apartments.end()) break;
        }
        if (apaIt == apartments.end()) break;
        if (*apaIt - *appIt <= k) {
            settledApps++;
            apaIt++;
        }
        appIt++;
    }

    cout << settledApps;

    return 0;
}