
#include <bits/stdc++.h>
using namespace std;

const long long MAX_NM = 800;

long long n, m, arr[MAX_NM][MAX_NM], groups[MAX_NM][MAX_NM], left_most[MAX_NM][MAX_NM];
struct coord {
    public:
    long long i, j;
    coord() : i(-1), j(-1) {}
    coord(long long i, long long j) : i(i), j(j) {}
};
coord dp[MAX_NM][MAX_NM];

int main() {
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        long long prev_value = -1;
        long long curr_group = 0;
        for (long long j = 0; j < m; j++) {
            cin >> arr[i][j];
            long long curr_value = arr[i][j];
            if (curr_value >= prev_value) {
                curr_group++;
            }
            arr[i][j] = curr_group;
        }
    }

    for (long long i = 0; i < n-1; i++) {
        for (long long j = m-1; j >= 0; j--) {
            long long curr_value = arr[i][j];
            long long left_most_index = j;
            while (left_most_index != -1 && arr[i+1][left_most_index] > curr_value) {
                left_most_index--;
            }
            left_most[i][j] = left_most_index;
        }
    }

    // First row
    long long prev_group = -1;
    long long prev_group_start = -1;
    for (long long j = 0; j < m; j++) {
        long long curr_group = groups[0][j];
        if (curr_group != prev_group) {
            prev_group_start = j;
        }
        dp[0][j] = coord(0, prev_group_start);
    }
    // Other rows
    for (long long i = 1; i < n; i++) {

    }

    return 0;
}
