#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int tmp;
    while ( b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int T, a, b;

    cin >> T;
    while(T > 0) {
        T--;
        cin >> a >> b;
        cout << lcm(a, b) << ' ' << gcd(a, b) << endl;
    }
}