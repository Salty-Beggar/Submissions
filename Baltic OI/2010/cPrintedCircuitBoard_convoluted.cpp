
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const long long MAX_N = 100000, MAX_X = 1000000;
long long n;
vector<pair<pair<long long, long long>, long long>> wires;

// Fenwick trees
long long bottom_ft[MAX_X+1], top_ft[MAX_X+1];
long long query(long long fen_tree[MAX_X+1], long long index) {
    long long curr_sum = fen_tree[0];
    for (; index > 0; index -= index&(-index)) {
        curr_sum += fen_tree[index];
    }
    return curr_sum;
}
void add(long long (&fen_tree)[MAX_X+1], long long index, long long value) {
    for (; index <= MAX_X; index += index&(-index)) {
        fen_tree[index] += value;
    }
}

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long u, v;
        cin >> u >> v;
        u++; v++;
        if (u <= v) {
            wires.push_back({{u, v}, -1});
        }else {
            wires.push_back({{v, u}, 1});
        }
    }
    sort(wires.begin(), wires.end());

    long long ans = 1;
    priority_queue<
        pair<long long, long long>, 
        vector<pair<long long, long long>>, 
        greater<pair<long long, long long>>
        > bottom_pqueue, top_pqueue;
    for (auto wire : wires) {
        long long wire_start = wire.first.first;
        long long wire_end = wire.first.second;
        long long wire_type = wire.second;

        long long bottom_layers = 0;
        while (!bottom_pqueue.empty() && wire_start >= bottom_pqueue.top().first) {
            auto last_node = bottom_pqueue.top();
            bottom_pqueue.pop();
            bottom_layers = max(bottom_layers, query(bottom_ft, last_node.second));
            // ans = max(ans, (long long) (query(bottom_ft, last_node)+top_pqueue.size()+1));
            add(bottom_ft, last_node.second, -1);
        }
        ans = max(ans, bottom_layers);
        while (!top_pqueue.empty() && wire_start >= top_pqueue.top().first) {
            auto last_node = top_pqueue.top();
            top_pqueue.pop();
            ans = max(ans, (long long) (query(top_ft, last_node.second)+bottom_layers));
            add(top_ft, last_node.second, -1);
        }

        if (wire_type == -1) {
            bottom_pqueue.push({wire_end, wire_start});
            add(bottom_ft, wire_start, 1);
        }else {
            top_pqueue.push({wire_end, wire_start});
            add(top_ft, wire_start, 1);
        }
    }

    long long bottom_layers = 0;
    while (!bottom_pqueue.empty()) {
        auto last_node = bottom_pqueue.top();
        bottom_pqueue.pop();
        bottom_layers = max(bottom_layers, query(bottom_ft, last_node.second));
        for (long long i = 0; i < 10; i++) {
            cout << query(bottom_ft, i) << ' ';
        }
        cout << "\n";
        // cout << bottom_layers << " ";
        // ans = max(ans, (long long) (query(bottom_ft, last_node)+top_pqueue.size()+1));
        add(bottom_ft, last_node.second, -1);
    }
    ans = max(ans, bottom_layers);
    while (!top_pqueue.empty()) {
        auto last_node = top_pqueue.top();
        top_pqueue.pop();
        ans = max(ans, (long long) (query(top_ft, last_node.second)+bottom_layers));
        add(top_ft, last_node.second, -1);
    }

    cout << ans;
    return 0;
}
