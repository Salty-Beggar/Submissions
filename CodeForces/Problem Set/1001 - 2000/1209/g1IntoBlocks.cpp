
#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

long int n, counts[200000];
bool hasAppeared[200000];
set<long int> values;
map<long int, long int> compression;
vector<long int> blocks;

int main() {
    cin >> n;
    int a; cin >> a;

    for (long int i = 0; i < n; i++) {
        long int x;
        cin >> x;
        blocks.push_back(x);
        values.insert(x);
    }

    long int index = 0;
    for (long int value : values) {
        compression[value] = index++;
    }

    for (long int &block : blocks) {
        block = compression[block];
        counts[block]++;
    }

    long int curCount = 0;
    long int curMax = 0;
    long int curIndex = 0;
    long int ans = 0;

    for (long int curBlock : blocks) {
        if (!hasAppeared[curBlock]) {
            hasAppeared[curBlock] = true;
            curCount += counts[curBlock]-1;
            curMax = max(curMax, counts[curBlock]);
        }else {
            curCount--;
        }
        curIndex++;
        if (curCount == 0) {
            ans += curIndex - curMax;
            curMax = 0;
            curIndex = 0;
        }
    }

    cout << ans << "\n";

}