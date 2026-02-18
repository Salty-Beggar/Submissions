
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

#define COMP compressionMap
const long int MAX_NQ = 200000, MAX_VALUES = 400000;
long int n, q, values, biTree[MAX_VALUES+1];
long long int employees[MAX_NQ], queryChange[MAX_NQ][2], queryCount[MAX_NQ][2];
bool queryTypes[MAX_NQ];
unordered_map<long long int, long int> compressionMap;

long int query(long int index) {
    long int sum = 0;
    for (index++; index > 0; index -= index&(-index)) {
        sum += biTree[index-1];
    }
    return sum;
}

void update(long int index, long int value) {
    for (index++; index <= values; index += index&(-index)) {
        biTree[index-1] += value;
    }
}

/*void updateRange(long int l, long int r, long int value) {
    update(l, value);
    update(r, -value);
}*/

int main() {
    cin >> n >> q;
    set<long long int> compressionSet;
    for (long int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        employees[i] = x;
        compressionSet.insert(x);
    }
    long int countIndex = 0; // Also the amount of counting queries.
    long int changeIndex = 0; // Also the amount of change queries.
    for (long int i = 0; i < q; i++) {
        char type;
        long long int a, b;
        cin >> type >> a >> b;
        if (type == '?') {
            queryCount[countIndex][0] = a;
            queryCount[countIndex][1] = b;
            countIndex++;
        }else {
            queryChange[changeIndex][0] = a-1;
            queryChange[changeIndex][1] = b;
            compressionSet.insert(b);
            changeIndex++;
            queryTypes[i] = true;
        }
    }
    //sort(compressionVector.begin(), compressionVector.end());
    values = compressionSet.size();

    long long int _i = 0;
    for (auto it = compressionSet.begin(); it != compressionSet.end(); it++) {
        COMP.insert_or_assign(*it, _i);
        _i++;
    }

    for (long int i = 0; i < n; i++) {
        update(COMP[employees[i]], 1);
    }

    countIndex = 0;
    changeIndex = 0;
    for (long int i = 0; i < q; i++) {
        if (queryTypes[i]) { // Changing type
            long long int curQuery[2] = {queryChange[changeIndex][0], queryChange[changeIndex][1]};
            update(COMP[employees[curQuery[0]]], -1);
            update(COMP[curQuery[1]], 1);
            employees[curQuery[0]] = curQuery[1];
            //cout << curQuery[0] << " " << curQuery[1] << "\n";
            changeIndex++;
        }else { // Counting type
            long long int curQuery[2] = {queryCount[countIndex][0], queryCount[countIndex][1]};
            set<long long int>::iterator l = compressionSet.lower_bound(curQuery[0]);
            set<long long int>::iterator r = compressionSet.upper_bound(curQuery[1]);
            r--;
            if (l != compressionSet.end()) {
                if (l == compressionSet.begin()) cout << query(distance(compressionSet.begin(), r));
                else cout << query(distance(compressionSet.begin(), r)) - query((distance(compressionSet.begin(), l)) - 1);

            }else {
                cout << 0;
            }
            cout << "\n";
            countIndex++;
        }
    }
    
    return 0;
}