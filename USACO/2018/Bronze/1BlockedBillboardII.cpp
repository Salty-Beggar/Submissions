
#include <iostream>
#include <cstdio>

using namespace std;

struct Rect {
    int x1, y1, x2, y2;
    long int area() {
        return ((long int)(x2-x1))*(y2-y1);
    }
    void rotate() {
        this->mirror();
        int _x1 = this->x1, _y1 = this->y1, _x2 = this->x2, _y2 = this->y2;
        this->y1 = min(_x1, _x2);
        this->y2 = max(_x1, _x2);
        this->x1 = min(_y1, _y2);
        this->x2 = max(_y1, _y2);
    }
    void mirror() {
        int _x1 = this->x1, _y1 = this->y1, _x2 = this->x2, _y2 = this->y2;
        // this->y1 = _y2;
        // this->y2  = _y1;
        this->x1 = _x2*-1;
        this->x2 = _x1*-1;
    }
};

Rect feed, lawnmover;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    cin >> lawnmover.x1 >> lawnmover.y1 >> lawnmover.x2 >> lawnmover.y2;
    cin >> feed.x1 >> feed.y1 >> feed.x2 >> feed.y2;

    for (int i = 0; i < 4; i++) {
        if (feed.x1 > lawnmover.x1 || feed.x2 < lawnmover.x2) {
            feed.rotate();
            lawnmover.rotate();
            // cout << feed.y2 << " " << lawnmover.y2 << "\n";
        }else break;
    }

    if (feed.x1 <= lawnmover.x1 && feed.x2 >= lawnmover.x2) {
        // cout << (lawnmover.y2-lawnmover.y1) << "a\n";
        cout << ((long int)((lawnmover.y2-lawnmover.y1) - max(0l, min(lawnmover.y2, feed.y2) - max(lawnmover.y1, feed.y1))))*(lawnmover.x2 - lawnmover.x1);
        return 0;
    }
    cout << (lawnmover.area());
    return 0;
}