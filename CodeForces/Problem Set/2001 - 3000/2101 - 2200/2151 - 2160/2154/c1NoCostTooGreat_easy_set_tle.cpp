
#include <vector>
#include <iostream>
#include <set>
using namespace std;

const long int MAX_N = 200000;
int t;
long int n;
set<long int> numbers;

// Erasthotenes' Sieve
bool sieve[MAX_N+1];
vector<long int> primes;

int main() {
    for (long int i = 2; i <= MAX_N; i++) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (long int j = i; j <= MAX_N/2+1; j += i) {
                sieve[j] = true;
            }
        }
    }

    for (cin >> t; t > 0; t--) {
        numbers.clear();
        cin >> n;
        bool hasEven = false;
        long int evenOne = -1;
        bool hasTwoEvens = false;
        bool hasEquals = false;
        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
            if (hasTwoEvens || hasEquals) continue;
            if (x%2 == 0) {
                if (hasEven) {
                    hasTwoEvens = true;
                    continue;
                }
                evenOne = x;
                hasEven = true;
                numbers.insert(evenOne);
                continue;
            }
            if (numbers.find(x) != numbers.end()) {
                hasEquals = true;
                continue;
            }
            if (x != 1) numbers.insert(x);
            numbers.insert(x+1);
        }
        for (long int i = 0; i < n; i++) {
            long int x;
            cin >> x;
        }
        
        if (hasTwoEvens || hasEquals) {
            cout << 0 << "\n";
            continue;
        }

        bool isAnsOne = hasEven;
        bool isAnsZero = false;
        for (long int i = 1; i < primes.size(); i++) {
            long int curPrime = primes[i];
            long int curValue = curPrime;
            auto curIt = numbers.begin();
            bool hasOdd = false;
            bool hasEven = false;
            while (curIt != numbers.end()) {
                curIt = numbers.upper_bound(curValue);
                if (curIt != numbers.begin()) {
                    curIt--;
                    // cout << curValue << "|" << (*curIt) << " <- value\n";
                    if (*curIt == curValue) {
                        if (curValue == evenOne) {
                            if (hasOdd) {
                                isAnsZero = true;
                                break;
                            }else if (hasEven) {
                                isAnsOne = true;
                            }
                            hasOdd = true;
                        }else {
                            if ((*curIt)%2 == 0) {
                                if (!isAnsOne) {
                                    if (hasOdd) {
                                        isAnsOne = true;
                                    }
                                    hasEven = true;
                                }
                            }else {
                                if (hasOdd) {
                                    isAnsZero = true;
                                    break;
                                }else if (hasEven) {
                                    isAnsOne = true;
                                }
                                hasOdd = true;
                            }
                        }
                    }
                    curIt++;
                }
                long int diff = (*curIt) - curValue;
                if (diff%curPrime != 0) diff += curPrime-(diff%curPrime);
                curValue += diff;
            }
            if (isAnsZero) {
                break;
            }
        }

        if (isAnsZero) {
            cout << 0 << "\n";
        }else if (isAnsOne) {
            cout << 1 << "\n";
        }else {
            cout << 2 << "\n";
        }
    }
}