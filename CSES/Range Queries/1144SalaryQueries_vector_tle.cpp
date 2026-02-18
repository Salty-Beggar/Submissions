
// This submission resulted in TLE. I assume its due to constant optimization. The last test case had some black magic which led into the solution not working, despite being smaller.

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
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
    vector<long long int> compressionVector;
    for (long int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        employees[i] = x;
        compressionVector.push_back(x);
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
            compressionVector.push_back(b);
            changeIndex++;
            queryTypes[i] = true;
        }
    }
    sort(compressionVector.begin(), compressionVector.end());
    values = changeIndex+n;
 
    for (long int i = 0; i < values; i++) {
        COMP.insert_or_assign(compressionVector[i], i);
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
            vector<long long int>::iterator l = lower_bound(compressionVector.begin(), compressionVector.end(), queryCount[countIndex][0]);
            vector<long long int>::iterator r = upper_bound(compressionVector.begin(), compressionVector.end(), queryCount[countIndex][1])-1;
            if (l != compressionVector.end()) {
                if (l == compressionVector.begin()) cout << query(r - compressionVector.begin());
                else cout << query(r - compressionVector.begin()) - query((l - compressionVector.begin()) - 1);
 
            }else {
                cout << 0;
            }
            cout << "\n";
            countIndex++;
        }
    }
    
    return 0;
}
