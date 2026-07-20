
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 1500;
const long int MAX_Q = 200000;
int n;
string garland;
vector<int> letterMatrix[26];
long int q;
pair<pair<int, int>, long int> plans[MAX_Q];
int planAnswers[MAX_Q];

int main() {
    for (int i = 0; i < 26; i++) {
        letterMatrix[i] = {};
    }
    cin >> n >> garland >> q;
    for (int i = 0; i < n; i++) {
        letterMatrix[garland[i]-'a'].push_back(i);
    }
    for (long int i = 0; i < q; i++) {
        int m;
        char c;
        cin >> m >> c;
        plans[i] = {{c-'a', m}, i};
    }
    sort(plans, plans+q);

    long int _index = q-1; // Index of the current plan.
    for (int i = 25; i >= 0; i--) {
        vector<int> letterVector = letterMatrix[i];
        int k = letterVector.size();
        int l = 0, r = k-1;
        while (_index >= 0 && plans[_index].first.first == i) {
            int m = plans[_index].first.second;
            if (k == 0) {
                planAnswers[plans[_index].second] = m;
            }else {
                while (letterVector[r] - letterVector[l]-(r-l) > m) {
                    if (letterVector[r-1] - letterVector[l] < letterVector[r] - letterVector[l+1]) {
                        r--;
                    }else {
                        l++;
                    }
                }
                planAnswers[plans[_index].second] = min(r-l+1+m, n);
            }
            _index--;
        }
    }

    for (long int i = 0; i < q; i++) {
        cout << planAnswers[i] << "\n";
    }

    return 0;
}