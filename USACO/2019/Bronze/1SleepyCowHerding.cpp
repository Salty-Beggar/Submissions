
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long int arr[3];

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    cin >> arr[0] >> arr[1] >> arr[2];

    sort(arr, arr+3);

    if (arr[2] == arr[0]+2 && arr[1] == arr[0]+1) {
        cout << "0\n0";
        return 0;
    }

    if (arr[1]-arr[0] == 2 || arr[2]-arr[1] == 2) {
        cout << "1\n";
    }else {
        cout << "2\n";
    }

    long int biggerDist = arr[1]-arr[0]-1;
    long int smallerDist = arr[2]-arr[1]-1;

    cout << max(smallerDist, biggerDist);

    return 0;
}