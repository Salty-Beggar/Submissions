
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 5000;
int n;
long int x;
pair<long int, int> arr[MAX_N];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        long int a;
        cin >> a;
        arr[i] = {a, i+1};
    }
    sort(arr, arr+n);
    for (int i = 1; i < n-1; i++) {
        long int l = 0, r = n-1;
        while (l < i && r > i) {
            long int sum = arr[i].first+arr[l].first+arr[r].first;
            if (sum > x) {
                r--;
            }else if (sum < x) {
                l++;
            }else {
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
