
#include <iostream>
#include <algorithm>
#include <functional>
#include <span>
#include <cstdio>
using namespace std;

const long long MAX_NKB = 1000;
long long n, k, berries[MAX_NKB], berry_count[MAX_NKB+1];

int main()
{
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    cin >> n >> k;
    for (auto &berry : span(berries).subspan(0, n)) {
        cin >> berry;
    }

    long long bessie_gain = 0;
    for (long long i = 1; i <= MAX_NKB; i++) {
        for (auto &count : span(berry_count).subspan(1, i)) {
            count = 0;
        }
        for (auto &berry : span(berries).subspan(0, n)) {
            berry_count[i] += berry/i;
            berry_count[berry%i]++;
        }
        long long free_baskets = k;
        long long cur_bessie_gain = 0;
        for (long long j = i; j > 0; j--) {
            if (free_baskets > k/2) {
                long long basket_occupy = min(free_baskets - k/2, berry_count[j]);
                free_baskets -= basket_occupy;
                berry_count[j] -= basket_occupy;
            }
            if (free_baskets <= k/2 && free_baskets > 0) {
                long long basket_occupy = min(free_baskets, berry_count[j]);
                cur_bessie_gain += j*basket_occupy;
                free_baskets -= basket_occupy;
            }
        }

        bessie_gain = max(bessie_gain, cur_bessie_gain);
    }

    cout << bessie_gain;

    return 0;
}