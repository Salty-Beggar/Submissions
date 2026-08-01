
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const long int MAX_N = 200000, MAX_X = 1000000002;
int t;
long int n, m;
vector<long int> swords, monsterHps, monsterAtks, miscMonsters;
set<long int> leaves;
set<pair<long int, long int>> increases;

int main() {
    for (cin >> t; t > 0; t--) {
        swords.clear();
        monsterAtks.clear();
        monsterHps.clear();
        leaves.clear();
        increases.clear();
        miscMonsters.clear();
        
        cin >> n >> m;
        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
            swords.push_back(x);
        }
        for (long int i = 0; i < m; i++) {
            long int x;
            cin >> x;
            monsterHps.push_back(x);
        }
        for (long int i = 0; i < m; i++) {
            long int x;
            cin >> x;
            monsterAtks.push_back(x);
        }

        sort(swords.begin(), swords.end());
        for (long int i = 0; i < m; i++) {
            long int curHp = monsterHps[i];
            long int curAtk = monsterAtks[i];
            if (curAtk == 0)
                leaves.insert(curHp);
            else if (curHp < curAtk) {
                increases.insert({curHp, curAtk});
            }else {
                miscMonsters.push_back(curHp);
            }
        }
        long int leafAmount = leaves.size();
        long int ans = 0;
        // long int leafPointer = 0;
        // auto leafIt = leaves.begin();
        long int biggestAtk = swords[n-1];
        for (long int i = 0; i < n && !leaves.empty(); i++) {
            long int curLeaf = *leaves.begin();
            long int curSword = swords[i];
            
            bool bruh = false;
            while (curSword < curLeaf) {
                if (!increases.empty()) {
                    auto curIncreaseIt = increases.upper_bound({curSword, MAX_X});
                    if (increases.empty() || curIncreaseIt == increases.begin()) {
                        bruh = true;
                        break;
                    }
                    curIncreaseIt--;
                    if ((*curIncreaseIt).second <= curSword) {
                        bruh = true;
                        break;
                    }
                    curSword = (*curIncreaseIt).second;
                }else {
                    bruh = true;
                    break;
                }
            }
            
            if (bruh) continue;

            auto _it = leaves.upper_bound(curSword);
            _it--;
            curLeaf = *_it;
            curSword = swords[i];
            
            // cout << "Leaf defeat: " << curSword << " " << curLeaf << "\n";
            
            ans++;
            while (curSword < curLeaf) {
                auto curIncreaseIt = increases.upper_bound({curSword, MAX_X});
                curIncreaseIt--;
                curSword = (*curIncreaseIt).second;
                biggestAtk = max(biggestAtk, curSword);
                increases.erase(curIncreaseIt);
                ans++;
            }
            
            leaves.erase(_it);
            
            // cout << "Showing leaves: ";
            // for (auto _it2 = leaves.begin(); _it2 != leaves.end(); _it2++) {
            //     cout << *_it2 << " ";
            // }
            // cout << "\n";
        }
        
        while (!increases.empty()) {
            auto curIncrease = *increases.begin();
            if (biggestAtk < curIncrease.first) break;
            biggestAtk = max(curIncrease.second, biggestAtk);
            increases.erase(increases.begin());
            ans++;
        }
        for (long int i = 0; i < miscMonsters.size(); i++) {
            if (biggestAtk >= miscMonsters[i]) ans++;
        }
        
        cout << ans << "\n";
    }
}
