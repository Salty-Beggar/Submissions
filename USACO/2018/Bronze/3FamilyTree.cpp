
#include <iostream>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 100, MAX_COW_AMNT = MAX_N*2+2;
int n, depth[MAX_COW_AMNT], nexts[MAX_COW_AMNT];
unordered_map<string, int> compression;
// vector<pair<vector<int>, vector<int>>> familyTree;
bool visited[MAX_COW_AMNT];
string cow1, cow2;

string parent(string type, int distance) {
    string prefix;
    for (int i = 0; i < distance-1; i++)
        prefix += "great-";
    if (distance >= 1) prefix += (type == "mother") ? "grand-" : "great-";
    return prefix+type;
}

void parentPhrase(string type, string cowStr1, string cowStr2) {
    cout << cowStr2 << " is the " << type << " of " << cowStr1;
}

int main() {
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    for (int i = 0; i < MAX_COW_AMNT; i++) {
        nexts[i] = -1;
        depth[i] = -1;
    }

    cin >> n >> cow1 >> cow2;
    compression.insert({cow1, 0});
    compression.insert({cow2, 1});

    int compressionIndex = 1;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (!compression.count(a)) {
            compressionIndex++;
            compression.insert({a, compressionIndex});
        }
        if (!compression.count(b)) {
            compressionIndex++;
            compression.insert({b, compressionIndex});
        }
        nexts[compression[b]] = compression[a];
    }

    int c = compression.size();
    string uncompression[c];
    for (pair<string, int> cow : compression) {
        uncompression[cow.second] = cow.first;
    }

    int cowPointer1 = compression[cow1];
    int cowPointer2 = compression[cow2];
    int curDepth = 0;
    bool doing = true;
    if (nexts[cowPointer1] == -1 ) {
        swap(cowPointer1, cowPointer2);
        swap(cow1, cow2);
    }
    while (cowPointer1 != -1) {
        // cout << uncompression[cowPointer1] << " " << uncompression[cowPointer2] << "\n";

        if (nexts[cowPointer1] == -1) {
            if (nexts[cowPointer2] == -1) break;
            swap(cowPointer1, cowPointer2);
            swap(cow1, cow2);
        }

        depth[cowPointer1] = curDepth;
        visited[cowPointer1] = true;
        if (!visited[cowPointer2]) {
            depth[cowPointer2] = curDepth;
            visited[cowPointer2] = true;
        }

        int next1 = nexts[cowPointer1];
        int next2 = nexts[cowPointer2];
        if (next1 != -1 && next1 == next2) {
            if (curDepth == 0) cout << "SIBLINGS";
            else cout << "COUSINS";
            return 0;
        }
        
        if (next2 != -1 && depth[next2] != -1) {
            swap(cowPointer1, cowPointer2);
            swap(next1, next2);
            swap(cow1, cow2);
        }
        // cout << uncompression[next1] << " ";
        // if (next2 != -1) cout << uncompression[next2];
        // cout << "\n\n";
        // cout << uncompression[cowPointer1] << " " << uncompression[next1] << "\n";
        // cout << uncompression[cowPointer2] << "\n";
        if (depth[next1] != -1) {
            if (depth[next1] == 0) {
                // cout << curDepth << "\n";
                parentPhrase(parent("mother", curDepth), cow1, cow2);
                return 0;
            }else if (depth[next1] == 1) {
                parentPhrase(parent("aunt", curDepth-1), cow1, cow2);
                return 0;
            }else {
                cout << "COUSINS";
                return 0;
            }
        }
        
        cowPointer1 = nexts[cowPointer1];
        if (nexts[cowPointer2] != -1) {
            cowPointer2 = nexts[cowPointer2];
        }
        curDepth++;
    }
    cout << "NOT RELATED";
    return 0;
}
