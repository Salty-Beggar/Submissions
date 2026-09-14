#include <iostream>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    if (a+b == 9 || a/b == 9 || a*b == 9 || a-b == 9) {
        cout << "Nine";
        return 0;
    }
    cout << "Nein";
    return 0;
}