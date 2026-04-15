
#include <iostream>

using namespace std;

int n;
long int apples[20];
long long int appleSum;

long long int _solve(int index, long long int sum) {
    if (index == n) return abs(appleSum - 2ll*sum);
    return min(_solve(index+1, sum), _solve(index+1, sum+apples[index]));
}

long long int solve() {
    return _solve(0, 0);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> apples[i];
        appleSum += apples[i];
    }
    cout << solve();
}