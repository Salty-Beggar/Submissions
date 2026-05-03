
#include <iostream>
#include <cstdio>

using namespace std;

struct Rect {
    int x1, y1, x2, y2;
    long int getArea() {
        return (x2-x1) * (y2-y1);
    }
    // Rect operator-(const Rect &b) {
        
    // }
};

Rect billboards[2];
Rect truck;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    for (int i = 0; i < 2; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        billboards[i] = {x1, y1, x2, y2};
    }

    cin >> truck.x1 >> truck.y1 >> truck.x2 >> truck.y2;

    long int sum = 0;
    for (int i = 0; i < 2; i++) {
        Rect curBillboard = billboards[i];
        sum += curBillboard.getArea();
        sum -= max(
            0, 
            (
                max(curBillboard.x1, min(curBillboard.x2, truck.x2))
                -min(curBillboard.x2, max(curBillboard.x1, truck.x1))
            )
            * (
                max(curBillboard.y1, min(curBillboard.y2, truck.y2))
                -min(curBillboard.y2, max(curBillboard.y1, truck.y1))
            )
        );
    }
    cout << sum;

    return 0;
}