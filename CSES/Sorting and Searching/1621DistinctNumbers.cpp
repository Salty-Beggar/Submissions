#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    long int n;
    cin >> n;
    vector<long int> list;
    for (long int i = 0; i < n; i++) {
        long int value;
        cin >> value;
        list.push_back(value);
    }
    sort(list.begin(), list.end());
    long int prevValue = -1;
    long int distinctAmount = 0;
    for (long int i = 0; i < n; i++) {
        long int curValue = list[i];
        if (curValue != prevValue) distinctAmount++;
        prevValue = curValue;
    }
    cout << distinctAmount;
    return 0;
}