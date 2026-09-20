
#include <string>
#include <iostream>
using namespace std;

const long long MAX_SIZE = 10;
string a, b, new_a, new_b;

int main() {
    cin >> a >> b;
    while (a.size() < MAX_SIZE) a = "0"+a;
    while (b.size() < MAX_SIZE) b = "0"+b;
    bool a_zero = true;
    bool b_zero = true;
    bool a_zero_right = false;
    bool b_zero_right = false;
    for (long long i = 0; i < MAX_SIZE; i++) {
        long long a_digit = a[i]-'0';
        long long b_digit = b[i]-'0';
        a_zero = a_zero && a_digit == 0;
        b_zero = b_zero && b_digit == 0;
        if (a_digit < b_digit) {
            new_b += b_digit+'0';
            if (!b_zero && b_digit == 0) b_zero_right = true;
        }else if (b_digit < a_digit) {
            new_a += a_digit+'0';
            if (!a_zero && a_digit == 0) a_zero_right = true;
        }else {
            new_a += a_digit+'0';
            new_b += b_digit+'0';
            if (!a_zero && a_digit == 0) a_zero_right = true;
            if (!b_zero && b_digit == 0) b_zero_right = true;
        }
    }
    long long 
        new_a_numb = stoi(new_a), 
        new_b_numb = stoi(new_b);
    if (new_a_numb == 0 && !a_zero_right) new_a_numb = -1;
    if (new_b_numb == 0 && !b_zero_right) new_b_numb = -1;
    if (new_a_numb < new_b_numb) {
        cout << new_a_numb << " " << new_b_numb;
    } else {
        cout << new_b_numb << " " << new_a_numb;
    }
}
