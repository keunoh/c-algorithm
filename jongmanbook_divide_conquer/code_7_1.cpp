#include <iostream>
using namespace std;
//1부터 n까지의 합을 구하는 분할 정복 알고리즘

//필수 조건: n은 자연수
//1 + 2 + ... + n을 반환한다.
int fastSum(int n) {
    
    //기저사례
    if(n == 1) {
        cout << n << " : 기저사례 호출" << endl;     
        return 1;
    }
    if(n % 2 == 1) {
        cout << n << " : n이 홀수인 경우 호출" << endl;  
        return fastSum(n - 1) + n;
    }
    cout << n << " : n이 짝수인 경우 호출" << endl;
    return 2*fastSum(n/2) + (n/2)*(n/2);
}

int main() {
    int number = 10;

    cout << fastSum(number) << endl;
}