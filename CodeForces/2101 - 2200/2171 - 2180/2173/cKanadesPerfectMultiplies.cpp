
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n, k;

long int binary_search(long int arr[MAX_N], long int size, long int value) {
    long int l = 0;
    long int r = size;
    while (l != r-1) {
        long int mid = (l+r)/2;
        if (arr[mid] > value) {
            r = mid;
        }else {
            l = mid;
        }
    }
    return (arr[l] == value) ? l : -1;
}

int main() {
    for (cin >> t; t > 0; t--) {
        cin >> n >> k;
        long int inputArr[MAX_N];
        bool removedElements[MAX_N];
        unordered_set<long int> putElements;
        long int remainingElements = 0;
        long int trueSize = 0;
        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
            if (putElements.find(x) == putElements.end()) {
                inputArr[remainingElements] = x;
                removedElements[remainingElements] = false;
                remainingElements++;
                trueSize++;
                putElements.insert(x);
            }
        }
        sort(inputArr, inputArr+trueSize);
        long int ans = 0;
        vector<long int> ansVector;
        for (long int j = 0; j < trueSize; j++) {
            if (removedElements[j]) continue;
            long int curItem = inputArr[j];
            bool succesfulPick = true;
            for (long int i = curItem; i <= k; i += curItem) {
                if (binary_search(inputArr, trueSize, i) == -1) {
                    succesfulPick = false;
                    break;
                }
            }
            if (!succesfulPick) continue;
            ans++;
            ansVector.push_back(curItem);
            for (long int i = curItem; i <= k; i += curItem) {
                long int foundIndex = binary_search(inputArr, trueSize, i);
                if (!removedElements[foundIndex]) {
                    remainingElements--;
                    removedElements[foundIndex] = true;
                }
            }
        }
        // cout << "Ans: ";
        if (remainingElements == 0) {
            cout << ans << "\n";
            for (long int i = 0; i < ans; i++)
                cout << ansVector[i] << " ";
            cout << "\n";
        }else {
            cout << -1 << "\n";
        }
    }
}
