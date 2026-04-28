
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const long int MAX_N = 200000;
long int n;
string cows;

int main() {
    cin >> n >> cows;
    long int evenGuernseys = 0;
    long int oddGuernseys = 0;
    long int swaps = 0;
    for (long int i = 0; i < n/2; i++) {
        char odd = cows[i*2], even = cows[i*2+1];
        bool oddHas = odd=='G', evenHas = even=='G';
        // if (i == 2) {
        //     cout << evenGuernseys << " " << oddGuernseys << "\n";
        // }
        if (
            abs(evenGuernseys+evenHas-oddGuernseys-oddHas) < abs(oddGuernseys+evenHas-evenGuernseys-oddHas)
        ) {
            swap(oddGuernseys, evenGuernseys);
            // swap(oddHas, evenHas);
            swaps++;
        }
        oddGuernseys += oddHas;
        evenGuernseys += evenHas;
    }
    if (oddGuernseys > evenGuernseys) swaps++;

    cout << swaps;

    return 0;
}