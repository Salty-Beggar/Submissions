
#include <iostream>

using namespace std;

int sizes[3][2];

char _char(int value) {
    switch (value) {
        case 0: return 'A';
        case 1: return 'B';
    }
    return 'C';
}

int main() {
    cin >> sizes[0][0] >> sizes[0][1] >> sizes[1][0] >> sizes[1][1] >> sizes[2][0] >> sizes[2][1];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            // sizes[i][j]--;
        }
    }

    for (int i = 0; i < 3; i++) {
        int baseW = max(sizes[i][0], sizes[i][1]);
        int baseH = min(sizes[i][0], sizes[i][1]);
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            int counterW = sizes[j][0];
            int counterH = sizes[j][1];
            if (baseH+counterW == baseW) {
                int _w = counterW;
                counterW = counterH;
                counterH = _w;
            }
            if (baseH+counterH != baseW) {}
            else {
                int remainW = min(baseW - counterW, baseW - baseH);
                int remainH = max(baseW - counterW, baseW - baseH);
                int remainIndex = 3-i-j;
                if (min(sizes[remainIndex][0], sizes[remainIndex][1]) == remainW && max(sizes[remainIndex][0], sizes[remainIndex][1]) == remainH) {
                    cout << baseW << "\n";
                    for (int y = 0; y < baseH; y++) {
                        for (int x = 0; x < baseW; x++) {
                            cout << _char(i);
                        }
                        cout << "\n";
                    }
                    for (int y = baseH; y < baseW; y++) {
                        for (int x = 0; x < baseW; x++) {
                            if (x < counterW) cout << _char(j);
                            else cout << _char(remainIndex);
                        }
                        cout << "\n";
                    }

                    return 0;
                }
            }

            int stackW = baseW;
            if (max(sizes[j][0], sizes[j][1]) != stackW) continue;
            int stackH = min(sizes[j][0], sizes[j][1]);
            int remainIndex = 3-i-j;
            int remainW = baseW;
            if (max(sizes[remainIndex][0], sizes[remainIndex][1]) != stackW) continue;
            int remainH = baseW - baseH - stackH;
            if (min(sizes[remainIndex][0], sizes[remainIndex][1]) != remainH) continue;

            cout << baseW << "\n";
            for (int y = 0; y < baseW; y++) {
                for (int x = 0; x < baseW; x++) {
                    if (y < baseH) cout << _char(i);
                    else if (y < baseH+stackH) cout << _char(j);
                    else cout << _char(remainIndex);
                }
                cout << "\n";
            }
            return 0;
        }
    }

    cout << -1;

    return 0;
}