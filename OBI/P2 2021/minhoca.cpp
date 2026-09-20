// 50/100

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
    info biggest_info_1;
    info biggest_info_2;
    long long curr_cycle_amount = 1;
    bool bifurcated = false;
    vector<long long> equal_branch_sizes;
    for (auto child : adj_list[index]) {
        if (child == prev) continue;
        info curr_info = solve(child, index);
        if (biggest_info_1 < curr_info) {
            bifurcated = false;
            biggest_info_2 = biggest_info_1;
            biggest_info_1 = curr_info;
            curr_cycle_amount = biggest_info_2.amount * biggest_info_1.amount;
        }
        else if (biggest_info_1 == curr_info) {
            if (!bifurcated) {
                bifurcated = true;
                equal_branch_sizes.clear();
                equal_branch_sizes.push_back(biggest_info_1.amount);
                curr_cycle_amount = 0;
            }
            for (auto value : equal_branch_sizes) {
                curr_cycle_amount += value*curr_info.amount;
            }
            equal_branch_sizes.push_back(curr_info.amount);
            biggest_info_1.amount += curr_info.amount;
        }
        else if (biggest_info_2 < curr_info) {
            if (!bifurcated) {
                curr_cycle_amount = biggest_info_2.amount * biggest_info_1.amount;
            }
            biggest_info_2 = curr_info;
        }
        else if (biggest_info_2 == curr_info) {
            if (!bifurcated) {
                curr_cycle_amount += biggest_info_2.amount * biggest_info_1.amount;
            }
            biggest_info_2.amount += curr_info.amount;
        }
    }

    // cout << "Index: " << index+1 << "\n";
    // cout << biggest_info_1.length << " " << biggest_info_1.amount 
        // << " | " << biggest_info_2.length << " " << biggest_info_2.amount << "\n";
        
    if (bifurcated) {
        // cout << curr_cycle_amount << " " << biggest_info_1.length*2+1 << "\n";
        amount_per_cycle[biggest_info_1.length*2+1] 
            += curr_cycle_amount;
    } else {
        // cout << curr_cycle_amount << " " << biggest_info_1.length+biggest_info_2.length+1 << "\n";
        amount_per_cycle[biggest_info_1.length+biggest_info_2.length+1] 
            += curr_cycle_amount;
    }
    return info(biggest_info_1.length+1, biggest_info_1.amount);
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
