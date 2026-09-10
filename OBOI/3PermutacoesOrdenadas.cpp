// Y5x7XXd

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const long long MAX_N = 20, MAX_K = 1000000;
long long t, n, k;
vector<pair<long long, long long>> queries;
map<pair<long long, long long>, vector<long long>> answers;
vector<long long> perm_indexes[MAX_N+1];

vector<long long> permute(long long n, vector<long long> curr_vec) {
    for (auto i = curr_vec.rbegin()+1; i != curr_vec.rend(); i++) {
        if (*i < *(i-1)) {
            long long _i = n - distance(curr_vec.rbegin(), i) - 1;
            long long _j = n;
            for (long long j = n-1; j > _i; j--) {
                if (curr_vec[j] > curr_vec[_i] && (_j == n || curr_vec[j] < curr_vec[_j])) {
                    _j = j;
                }
            }
            long long _old = curr_vec[_i];
            curr_vec[_i] = curr_vec[_j];
            curr_vec[_j] = _old;

            sort(curr_vec.rbegin(), i, [&](long long a, long long b){ return a > b; });
            return curr_vec;
        }
        // if (curr_vec[i] < curr_vec[i+1]) {
        //     sort();
        // }
    }
    return curr_vec;
}

int main() {
    cin >> t;
    for (long long i = 0; i < t; i++) {
        cin >> n >> k;
        queries.push_back(make_pair(n, k));
        perm_indexes[n].push_back(k);
    }
    for (long long i = 1; i <= MAX_N; i++) {
        sort(perm_indexes[i].begin(), perm_indexes[i].end());
        vector<long long> curr_perm;
        for (long long j = 1; j <= i; j++) {
            curr_perm.push_back(j);
        }
        long long curr_k_index = 0;
        for (long long j = 1; j <= MAX_K && curr_k_index < perm_indexes[i].size(); j++) {
            if (j == perm_indexes[i][curr_k_index]) {
                vector<long long> new_vec = vector(curr_perm);
                answers.insert({{i, perm_indexes[i][curr_k_index]}, new_vec});
                curr_k_index++;
            }
            curr_perm = permute(i, curr_perm);
        }
    }
    for (auto query : queries) {
        for (long long i : answers[query]) {
            cout << i << " ";
        }
        cout << "\n";
    }
}