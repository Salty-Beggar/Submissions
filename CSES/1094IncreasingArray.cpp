#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    long int n;
    cin >> n;
    long int result = 0;
    long int prevValue;
    for (int i = 0; i < n; i++) {
        long int value;
        cin >> value;
        if (i != 0) {
            result += max(0L, prevValue-value);
            value = max(value, prevValue);
        }
        prevValue = value;
    }
    cout << result;
    return 0;
}