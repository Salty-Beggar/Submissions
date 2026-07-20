
#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = 5000, MAX_N2 = 25000000;
long int n, x;
long int stackArr[MAX_N];
pair<long int, long int> arr[MAX_N];
pair<long int, pair<long int, long int>> arrSquared[MAX_N2];

int main() {
    cin >> n >> x;
    for (long int i = 0; i < n; i++) {
        long int a;
        cin >> a;
        arr[i] = {a, i};
    }
    sort(arr, arr+n);
    long int squaredIndex = 0;
    long int stackIndex = 1;
    while (stackIndex != n) {
        // RIGHT_NOW: Understand why this hell of a code is not giving the sorted sum pairs.
        long int curSumIndex = stackArr[stackIndex]++;
        arrSquared[squaredIndex++] = {arr[curSumIndex].first+arr[stackIndex].first, {curSumIndex, stackIndex}};
        if (curSumIndex+1 == stackIndex) {
            stackIndex++;
            continue;
        }
        int add = 0;
        if (stackIndex < n-1 && arr[stackArr[stackIndex+1]].first+arr[stackIndex+1].first < arr[stackArr[stackIndex]].first+arr[stackIndex].first) {
            add = 1;
        }
        if (stackArr[stackIndex-1] < stackIndex-1 && arr[stackArr[stackIndex-1]].first+arr[stackIndex-1].first < arr[stackArr[stackIndex+add]].first+arr[stackIndex+add].first) {
            add = -1;
        }
        stackIndex += add;
    }
    for (long int i = 0; i < squaredIndex; i++) {
        cout << arrSquared[i].first << " ";
    }
    cout << "\n";
    squaredIndex--;
    for (long int i = 0; i < n; i++) {
        while (arrSquared[squaredIndex].first+arr[i].first > x) {
            squaredIndex--;
            if (squaredIndex < 0) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
        if (arrSquared[squaredIndex].first+arr[i].first == x) {
            if (i != arrSquared[squaredIndex].second.first && i != arrSquared[squaredIndex].second.second) {
                cout << arr[i].second+1 << " " << arr[arrSquared[squaredIndex].second.first].second+1 << " " << arr[arrSquared[squaredIndex].second.second].second+1;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}