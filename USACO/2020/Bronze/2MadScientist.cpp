
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n;
string targ, src;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    cin >> n >> targ >> src;
    bool doing = false;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!doing && targ[i] != src[i]) {
            doing = true;
            ans++;
        }else if (doing && targ[i] == src[i]) {
            doing = false;
        }
    }
    cout << ans;
    return 0;
}