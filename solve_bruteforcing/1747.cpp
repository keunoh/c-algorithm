#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;

    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }

    return true;
}

bool checkPalindrome(string str) {
    string front, back;

    front = str;
    reverse(str.begin(), str.end());
    back = str;

    if(front == back) return true;
    else return false;
}

int main() {
    int n;
    cin >> n;

    for(int i = n; ;i++) {
        if(isPrime(i) && checkPalindrome(to_string(i))) {
            cout << i;
            break;
        }
    }
}