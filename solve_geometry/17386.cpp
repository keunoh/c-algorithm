#include <iostream>
using namespace std;

struct Point {
    long long x;
    long long y;
};

long long CCW(Point A, Point B, Point C) {
    long long result = A.x * B.y + B.x*C.y + C.x*A.y - B.x*A.y - C.x*B.y - A.x*C.y;

    if(result>0) return 1;
    else if(result<0) return -1;
    return 0;
}

int main() {
    Point A, B, C, D;

    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;

    long long ABC = CCW(A, B, C);
    long long ABD = CCW(A, B, D);
    long long CDA = CCW(C, D, A);
    long long CDB = CCW(C, D, B);

    if((ABC*ABD)<=0 && (CDA*CDB)<=0) std::cout << "1\n";
    else std::cout << "0\n";
}