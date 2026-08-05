
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

long long n, m, r, cur_profit;
priority_queue<long long> cow_daily_milks;
priority_queue<long long, vector<long long>, greater<long long>> rent_prices;
priority_queue<pair<long long, long long>> milk_gallons;

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    cin >> n >> m >> r;
    for (long long i = 0; i < n; i++) {
        long long cow;
        cin >> cow;
        cow_daily_milks.push(cow);
    }

    for (long long i = 0; i < m; i++) {
        long long gallons, cent_per_gallon;
        cin >> gallons >> cent_per_gallon;
        milk_gallons.push({cent_per_gallon, gallons});
    }

    for (long long i = 0; i < r; i++) {
        long long rent_price;
        cin >> rent_price;
        cur_profit += rent_price;
        rent_prices.push(rent_price);
    }
    for (long long i = 0; i < n-r; i++) {
        rent_prices.push(0);
    }
    for (long long i = 0; i < r-n; i++) {
        cur_profit -= rent_prices.top();
        rent_prices.pop();
    }

    long long max_profit = cur_profit;
    for (long long i = 0; i < n; i++) {
        cur_profit -= rent_prices.top();
        rent_prices.pop();

        long long cur_cow_milk = cow_daily_milks.top();
        cow_daily_milks.pop();

        while (!milk_gallons.empty() && cur_cow_milk > 0) {
            pair<long long, long long> cur_milk_gallon = milk_gallons.top();
            milk_gallons.pop();
            long long cur_milk_use = min(cur_cow_milk, cur_milk_gallon.second);
            cur_cow_milk -= cur_milk_use;
            cur_profit += cur_milk_use*cur_milk_gallon.first;
            if (cur_milk_use != cur_milk_gallon.second) {
                milk_gallons.push({cur_milk_gallon.first, cur_milk_gallon.second - cur_milk_use});
            }
        }
        max_profit = max(max_profit, cur_profit);
    }

    cout << max_profit;
}
