
#include <iostream>
using namespace std;

const long long MAX_NKT = 300;
long long n, k, t, arr[MAX_NKT], dp[MAX_NKT][MAX_NKT+1][2], amigos[MAX_NKT];
// k, t, 0 - Índice em que foi posto, 1 - Brigadeiros atuais.

int main() {
    cin >> n >> k >> t;
    t = min(t, MAX_NKT);
    for (long long i = 0; i < k; i++) {
        for (long long j = 0; j <= t; j++) {
            dp[i][j][0] = -1;
        }
    }
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long amigo_i = 0;
    for (long long i = 0; i < n; i++) {
        long long is_amigo;
        cin >> is_amigo;
        if (is_amigo) {
            amigos[amigo_i++] = i;
        }
    }
    long long ans = 0;
    for (long long i = 0; i < k; i++) {
        long long curr_amigo = amigos[i];
        long long prev_amigo = (i == 0) ? -1 : amigos[i-1];
        long long next_amigo = (i == k-1) ? n : amigos[i+1];
        for (long long j = 0; j < n; j++) {
            if (i == 0) {
                long long curr_cost = abs(curr_amigo - j);
                if (curr_cost > t) continue;
                dp[0][curr_cost][0] = j;
                dp[0][curr_cost][1] = arr[j];
                ans = max(ans, dp[0][curr_cost][1]);
                continue;
            }
            for (long long w = 0; w <= t; w++) {
                auto prev_dp = dp[i-1][w];
                if (prev_dp[0] != -1 && prev_dp[0] < j) {
                    long long new_cost = w+abs(curr_amigo - j);
                    if (new_cost > t) continue;
                    dp[i][new_cost][0] = j;
                    dp[i][new_cost][1] = prev_dp[1]+arr[j];
                    ans = max(ans, dp[i][new_cost][1]);
                }
            }
        }
    }
    for (long long i = 0; i < k; i++) {
        for (long long j = 0; j <= t; j++) {
            cout << dp[i][j][0] << " " << dp[i][j][1] << " | ";
        }
        cout << "\n";
    }
    cout << ans;
    return 0;
}
