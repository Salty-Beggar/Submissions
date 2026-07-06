
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int t;
long int n;
vector<long int> prefixSums;

int main() {
    cin >> t;
    for (; t > 0; t--) {
        prefixSums.clear();
        cin >> n;
        string numbers;
        cin >> numbers;
        for (long int i = 0; i < n; i++) {
            long int a = numbers[i] - '0';
            a--;
            if (prefixSums.empty()) {
                prefixSums.push_back(a);
            }else {
                prefixSums.push_back(prefixSums.back()+a);
            }
        }
        prefixSums.push_back(0);
        sort(prefixSums.begin(), prefixSums.end());
        // for (long int i = 0; i < n+1; i++) {
        //     cout << prefixSums[i] << " ";
        // }
        // cout << "\n";
        long long int ans = 0;
        long long int streak = 1;
        long long int lastNumber = prefixSums[0];
        for (int i = 1; i < n+1; i++) {
            if (prefixSums[i] != lastNumber) {
                lastNumber = prefixSums[i];
                ans += streak*(streak-1)/2;
                streak = 1;
            }else {
                streak++;
            }
        }
        ans += streak*(streak-1)/2;
        cout << ans << "\n";
    }
    return 0;
}