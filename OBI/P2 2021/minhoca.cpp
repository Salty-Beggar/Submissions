#include <vector>
#include <iostream>
using namespace std;

const long long MAX_N = 50000;

long long n, amount_per_cycle[MAX_N+1];
vector<long long> adj_list[MAX_N];

struct info {
    long long length, amount;
    info() : length(0), amount(1) {}
    info(long long length, long long amount) : length(length), amount(amount) {}
    bool operator==(const info& other) const {
        return length == other.length;
    }
    bool operator<=(const info& other) const {
        return length <= other.length;
    }
    bool operator<(const info& other) const {
        return length < other.length;
    }
};

info solve(long long index, long long prev) {
    vector<info> child_infos;
    info returned_info;
    long long biggest_length_1 = -1;
    long long biggest_length_sum = 0;
    long long biggest_length_2 = -1;
    for (auto child : adj_list[index]) {
        if (child == prev) continue;
        info curr_info = solve(child, index);
        if (curr_info.length >= biggest_length_1) {
            if (biggest_length_1 != curr_info.length) {
                returned_info = info(curr_info.length+1, curr_info.amount);
                biggest_length_sum = 0;
            } else {
                returned_info = info(curr_info.length+1, returned_info.amount+curr_info.amount);
            }
            biggest_length_2 = biggest_length_1;
            biggest_length_1 = curr_info.length;
            biggest_length_sum += curr_info.amount;
        } else if (curr_info.length > biggest_length_2) {
            biggest_length_2 = curr_info.length;
        }
        child_infos.push_back(curr_info);
    }
    if (biggest_length_1 == -1 && biggest_length_2 == -1) return info(1, 1);

    long long curr_cycle_length = returned_info.length;
    long long curr_cycle_amount = returned_info.amount;
    if (biggest_length_1 == biggest_length_2) {
        curr_cycle_length = biggest_length_1*2+1;
        curr_cycle_amount = 0;
        for (info child_info : child_infos) {
            if (child_info.length == biggest_length_1) {
                biggest_length_sum -= child_info.amount;
                curr_cycle_amount += child_info.amount * biggest_length_sum;
            }
        }
    }
    else if (biggest_length_2 != -1) {
        curr_cycle_length = biggest_length_1+biggest_length_2+1;
        long long biggest_amount = -1;
        curr_cycle_amount = 0;
        for (info child_info : child_infos) {
            if (child_info.length == biggest_length_1) {
                biggest_amount = child_info.amount;
            } else if (child_info.length == biggest_length_2) {
                curr_cycle_amount += child_info.amount;
            }
        }
        curr_cycle_amount *= biggest_amount;
    }

    amount_per_cycle[curr_cycle_length] += curr_cycle_amount;

    return returned_info;
}

int main() {
    cin >> n;
    for (long long i = 0; i < n-1; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // for (long long i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (long long child : adj_list[i]) {
    //         cout << child << " ";
    //     }
    //     cout << "\n";
    // }

    info ans = solve(0, -1);

    // cout << ans.length << "\n" << ans.amount;
    // return 0;

    long long ans_size = 0;
    for (long long i = 0; i <= n; i++) {
        if (amount_per_cycle[i] != 0) {
            ans_size = i;
        }
    }

    cout << ans_size << "\n" << amount_per_cycle[ans_size];
    return 0;
}
