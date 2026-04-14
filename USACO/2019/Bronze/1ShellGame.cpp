
using namespace std;

#include <iostream>

int n;
int guesses[3];
int places[3];

int main() {
    places[0] = 0;
    places[1] = 1;
    places[2] = 2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, q;
        cin >> a >> b >> q;
        a--; b--; q--;
        int _a = places[a];
        places[a] = places[b];
        places[b] = _a;
        guesses[places[q]]++;
    }
    cout << max(max(guesses[0], guesses[1]), guesses[2]);
    return 0;
}