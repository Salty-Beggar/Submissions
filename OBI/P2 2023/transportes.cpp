
#include <iostream>
#include <queue>
#include <queue>
using namespace std;

struct edge {
    long long targ, sistema;
    edge(long long targ, long long sistema) : targ(targ), sistema(sistema) {}
};

struct choice {
    long long targ, cost, sistema;
    choice(long long targ, long long cost, long long sistema) : targ(targ), cost(cost), sistema(sistema) {}
    bool operator<(const choice& other) const {
        return cost > other.cost;
    }
};

const long long MAX_NK = 100000, INF = 100000001;
long long n, m, k, costs[MAX_NK], weight_node[MAX_NK];
vector<edge> adj_list[MAX_NK];

int main() {
    cin >> n >> m >> k;
    for (long long i = 0; i < n; i++) {
        weight_node[i] = INF;
    }
    for (long long i = 0; i < k; i++) {
        cin >> costs[i];
    }
    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--; v--; w--;
        adj_list[u].push_back(edge(v, w));
        adj_list[v].push_back(edge(u, w));
    }
    
    long long a, b;
    cin >> a >> b;
    a--; b--;
    priority_queue<choice> choice_pqueue;
    choice_pqueue.push(choice(a, 0, -1));
    while (!choice_pqueue.empty()) {
        choice curr_choice = choice_pqueue.top();
        // if (curr_choice.targ == b) {
        //     cout << curr_choice.cost;
        //     return 0;
        // }
        choice_pqueue.pop();
        if (curr_choice.cost > weight_node[curr_choice.targ]) continue;
        weight_node[curr_choice.targ] = curr_choice.cost;
        for (edge child : adj_list[curr_choice.targ]) {
            long long new_cost = curr_choice.cost;
            if (curr_choice.sistema != child.sistema) {
                new_cost += costs[child.sistema];
            }
            choice_pqueue.push(choice(child.targ, new_cost, child.sistema));
        }
    }
    cout << (weight_node[b] == INF) ? -1 : weight_node[b];
    return 0;
}
