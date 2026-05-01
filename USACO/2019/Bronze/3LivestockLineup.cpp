
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int n;
bool visited[8];
vector<vector<int>> adjList;

int _cow(string cow) {
    if (cow == "Beatrice")  return 0;
    else if (cow == "Belinda")  return 1;
    else if (cow == "Bella")  return 2;
    else if (cow == "Bessie")  return 3;
    else if (cow == "Betsy")  return 4;
    else if (cow == "Blue")  return 5;
    else if (cow == "Buttercup")  return 6;
    else if (cow == "Sue")  return 7;
    return 8;
}

string _value(int cow) {
    switch (cow) {
        case 0: return "Beatrice";
        case 1: return "Belinda";
        case 2: return "Bella";
        case 3: return "Bessie";
        case 4: return "Betsy";
        case 5: return "Blue";
        case 6: return "Buttercup";
        case 7: return "Sue";
    }
    return "AA";
}

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    for (int i = 0; i < 8; i++) {
        adjList.push_back({});
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        string cowStr1, cowStr2, none;
        cin >> cowStr1 >> none >> none >> none >> none >> cowStr2;
        int cow1 = _cow(cowStr1), cow2 = _cow(cowStr2);

        adjList[cow1].push_back(cow2);
        adjList[cow2].push_back(cow1);
    }

    for (int i = 0; i < 8; i++) {
        if (!visited[i] && adjList[i].size() != 2) {
            int curNode = i;
            while (!visited[curNode]) {
                cout << _value(curNode) << "\n";
                visited[curNode] = true;
                if (adjList[curNode].size() == 0) break;
                curNode = (adjList[curNode].size() == 1 || !visited[adjList[curNode][0]]) ? adjList[curNode][0] : adjList[curNode][1];
            }
        }
    }
    return 0;
}