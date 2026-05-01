
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, nextNode[8];
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
    throw runtime_error("No cows were found");
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

    cin >> n;
    for (int i = 0; i < 8; i++) {
        nextNode[i] = -1;
        visited[i] = false;
        adjList.push_back({});
    }
    for (int i = 0; i < n; i++) {
        string cow1, cow2;
        cin >> cow1 >> cow2 >> cow2 >> cow2 >> cow2 >> cow2;

        adjList[_cow(cow1)].push_back(_cow(cow2));
        adjList[_cow(cow2)].push_back(_cow(cow1));
    }
    int prevNode = -1;
    int curNode = 0;
    for (int i = 0; i < 7; i++) {
        if (!visited[i] && adjList[i].size() < 2) {
            prevNode = -1;
            int curNode = i;
            while (!visited[curNode]) {
                cout << _value(curNode) << "\n";
                visited[curNode] = true;
                if (adjList[curNode].size() == 0) break;
                curNode = (adjList[curNode].size() == 1 && adjList[curNode][0] == prevNode) ? adjList[curNode][1] : adjList[curNode][0];
                if (visited[curNode]) break;
            }
        }
    }
    return 0;
}