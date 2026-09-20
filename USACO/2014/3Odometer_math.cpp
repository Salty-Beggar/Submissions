
#include <iostream>
#include <cmath>
using namespace std;

const long long MAX_SIZE = 18;

long long n, m;
string lower_str, upper_str;

long long factorial(long long value) {
    long long ans = 1;
    for (long long i = 2; i <= value; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    cin >> lower_str >> upper_str;
    n = upper_str.size();
    m = lower_str.size();

    long long ans = 0;
    // General cases until upper_str with 1 removed digit, and including the lower_str.
    for (long long i = m; i < n; i++) {
        for (long long k = i/2+1; k <= n; k++) {
            ans += // Assuming one of the repeated digits is the first digit.
                factorial(i-1)/(factorial(i-k) * factorial(k-1))    // The repeated numbers themselves    
                *pow(10, i-k)    // The random choosing of the other numbers
                ;
            ans += // Assuming the repeating digit is 0.
                factorial(i-1)/(factorial(i-1-k) * factorial(k))    // The repeated numbers themselves    
                *9
                *pow(10, i-1-k)    // The random choosing of the other numbers, other than the first one which can't be 0.
                ;
        }
        if (i%2 == 0) { // Certain cases have been repeated twice.
            // The cases contain 0.
            ans -= factorial();
        }
    }

    return 0;
}
