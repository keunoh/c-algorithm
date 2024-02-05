#include <iostream>
using namespace std;

int main() {
    int test = 4, x1, y1, p1, q1, x2, y2, p2, q2;
    while (test--) {
        cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;
        if (x1 > p2 || y1 > q2 || x2 > p1 || y2 > q1)
            cout << "d" << endl;
        else if ((x1 == p2 && y1 == q2) || (x2 == p1 && y2 == q1) || (x1 == p2 && q1 == y2) || (x2 == p1 && q2 == y1))
            cout << "c" << endl;
        else if (x1 == p2 || y1 == q2 || x2 == p1 || y2 == q1)
            cout << "b" << endl;
        else 
            cout << "a" << endl;
    }
}