
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct law {
    public:
        long long left, right, minimum;
    law() : left(0), right(0), minimum(0) {}
    bool operator <(const law& other) const {
        return minimum > other.minimum;
    }
};

const long long MAX_NK = 100000;
long long n, t, k, trees[MAX_NK];
law laws[MAX_NK];
priority_queue<law> law_pqueue;

class Compare {
    public:
        bool operator()(const long long a, const long long b) {
            return laws[a].right > laws[b].right;
        }
};

int main() {
    for (cin >> t; t > 0; t--) {
        while (!law_pqueue.empty()) law_pqueue.pop();
        cin >> n >> k;
        for (long long i = 0; i < n; i++) {
            cin >> trees[i];
        }
        sort(trees, trees+n);
        for (long long i = 0; i < k; i++) {
            cin >> laws[i].left >> laws[i].right >> laws[i].minimum;
        }
        sort(laws, laws+k, [](const law& a, const law& b) {
            return a.left < b.left;
        });

        priority_queue<long long, vector<long long>, Compare> law_time_pqueue;
        long long curr_law_index = 0;
        for (long long i = 0; i < n; i++) {
            long long curr_tree = trees[i];
            while (curr_law_index != k && laws[curr_law_index].left <= curr_tree) {
                laws[curr_law_index].minimum += i;
                law_time_pqueue.push(curr_law_index);
                curr_law_index++;
            }
            while (!law_time_pqueue.empty() && laws[law_time_pqueue.top()].right < curr_tree) {
                laws[law_time_pqueue.top()].minimum = i - laws[law_time_pqueue.top()].minimum;
                law_time_pqueue.pop();
            }
        }
        while (!law_time_pqueue.empty()) {
            laws[law_time_pqueue.top()].minimum = n - laws[law_time_pqueue.top()].minimum;
            law_time_pqueue.pop();
        }

        // for (long long i = 0; i < k; i++) {
        //     cout << laws[i].minimum << " ";
        // }
        // cout << "\n";

        curr_law_index = 0;
        long long cut_tree_amount = 0;
        for (long long i = 0; i < n; i++) {
            long long curr_tree = trees[i];
            while (curr_law_index != k && laws[curr_law_index].left <= curr_tree) {
                law new_law = laws[curr_law_index];
                new_law.minimum += cut_tree_amount;
                law_pqueue.push(new_law);
                curr_law_index++;
            }
            while (!law_pqueue.empty() && law_pqueue.top().right < curr_tree) {
                law_pqueue.pop();
            }
            // if (!law_pqueue.empty()) cout << law_pqueue.top().minimum << "\n";
            if (law_pqueue.empty() || cut_tree_amount < law_pqueue.top().minimum) {
                cut_tree_amount++;
            }
        }
        cout << cut_tree_amount << "\n";
    }
}
