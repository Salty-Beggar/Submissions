
#include <string>
#include <iostream>

using namespace std;

int n, m, genomesSrc[500][50], genomesTarg[500][50];
long long int triplets[19600];
bool tripletsIsPossible[19600];

int _gene(char gene) {
    switch (gene) {
        case 'A': return 0;
        case 'G': return 1;
        case 'C': return 2;
    }
    return 3;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string genome = "";
        cin >> genome;
        for (int j = 0; j < m; j++) {
            int curGene = _gene(genome[j]);
            genomesSrc[i][j] = curGene;
        }
    }
    for (int i = 0; i < n; i++) {
        string genome = "";
        cin >> genome;
        for (int j = 0; j < m; j++) {
            int curGene = _gene(genome[j]);
            genomesTarg[i][j] = curGene;
        }
    }

    int count = 0;
    for (int a = 0; a < m; a++) {
        for (int b = a+1; b < m; b++) {
            for (int c = b+1; c < m; c++) {
                for (int i = 0; i < n; i++) {
                    triplets[count] |= 1ll << (genomesSrc[i][a] * 1 + genomesSrc[i][b] * 4 + genomesSrc[i][c] * 16);
                }
                count++;
            }
        }
    }
    count = 0;
    for (int a = 0; a < m; a++) {
        for (int b = a+1; b < m; b++) {
            for (int c = b+1; c < m; c++) {
                for (int i = 0; i < n; i++) {
                    long long int curTriplet = 1ll << (genomesTarg[i][a] * 1 + genomesTarg[i][b] * 4 + genomesTarg[i][c] * 16);
                    if ((triplets[count] & curTriplet) != 0) {
                        tripletsIsPossible[count] = true;
                        break;
                    }
                }
                count++;
            }
        }
    }

    int tripletAmnt = 0; // ans
    for (long int i = 0; i < (m*(m-1)*(m-2))/6; i++) {
        tripletAmnt += (!tripletsIsPossible[i]);
    }
    cout << tripletAmnt;

    return 0;
}