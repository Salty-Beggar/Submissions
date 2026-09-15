
#include <iostream>
using namespace std;

const long long MAX_NK = 30000;
long long n, k;

#pragma region Interactions

long long ask_and(long long i, long long j) {
    cout << "AND " << i << " " << j << "\n";
    fflush(stdout);
    long long x;
    cin >> x;
    return x;
}

long long ask_or(long long i, long long j) {
    cout << "OR " << i << " " << j << "\n";
    fflush(stdout);
    long long x;
    cin >> x;
    return x;
}

#pragma endregion

int main() {
    cin >> n >> k;
    cout << ask_and(1, 3) << "\n";
    cout << ask_or(0, 3) << "\n";
}
