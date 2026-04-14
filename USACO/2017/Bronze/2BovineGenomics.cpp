
#include <iostream>
#include <string>

using namespace std;

int n, m;

int _gene(int gene) {
    switch (gene) {
        case 'A': return 0; break;
        case 'G': return 1; break;
        case 'C': return 2; break;
        case 'T': return 3; break;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string genome;
        cin >> genome;
        for (int j = 0; j < m; j++) {
            char gene = genome[j];
            int geneValue = _gene(gene);
        }
    }
    return 0;
}