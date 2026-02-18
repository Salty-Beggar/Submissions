
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int t;
string word1, word2;
long int n, m;
vector<int> list1, list2;

int main() {
    cin >> t;
    for (int T = 0; T < t; T++) {
        cin >> word1 >> word2;
        list1.clear();
        list2.clear();
        n = word1.size();
        m = word2.size();
        long int letterCounts[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        long int letterTotal = 0;
        for (int i = 0; i < n; i++) {
            char curChar = word1[i];
            letterTotal++;
            letterCounts[curChar-'a']++;
            list1.push_back(curChar);
        }
        for (int i = 0; i < m; i++) {
            char curChar = word2[i];
            if (letterCounts[curChar-'a'] > 0) {
                letterCounts[curChar-'a']--;
                letterTotal--;
            }else
                list2.push_back(curChar);
        }
        if (letterTotal > 0) {
            cout << "Impossible\n";
            continue;
        }
        sort(list2.begin(), list2.end());

        long int nPointer = 0;
        long int mPointer = 0;
        for (long int i = 0; i < m; i++) {
            if (nPointer == n || (mPointer != m-n && list2[mPointer] < list1[nPointer])) {
                cout << (char) list2[mPointer];
                mPointer++;
            }else {
                cout << (char) list1[nPointer];
                nPointer++;
            }
        }
        cout << "\n";
    }
}
