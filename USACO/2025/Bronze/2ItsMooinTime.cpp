
#include <iostream>
#include <set>
#include <map>

using namespace std;

long int n, numbers[1000000];
map<long int, long int> mooPerNumber;
set<long int> doubleMoos;

int main() {
    cin >> n;
    for (long int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (long int i = n-1; i >= 0; i--) {
        long int curMoo = numbers[i];
        bool hasMoo = mooPerNumber.count(curMoo) == 0;
        if (hasMoo) mooPerNumber[curMoo] = 1;
        mooPerNumber[curMoo] = doubleMoos.size() - doubleMoos.count(curMoo);

        if (!hasMoo) doubleMoos.insert(curMoo);
    }

    long long int mooCount = 0;
    for (pair<long int, long int> moo : mooPerNumber) {
        mooCount += moo.second;
    }
    cout << mooCount;
}