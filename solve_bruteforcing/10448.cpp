#include <iostream>
#define ll long long
using namespace std;
int triagleNum[1001];
int t;

bool ck(int num){
    for(int i=1;i<=50;i++)
        for(int j=1;j<=50;j++)
            for(int k=1;k<=50;k++)
                if(triagleNum[i] + triagleNum[j] + triagleNum[k] == num)
                    return true;
    return false;
}

int main(){
    for(int i=1;i<=1000;i++)
        triagleNum[i] = triagleNum[i-1] + i;

    cin >> t;
    while(t--){
        int num;
        cin >> num;
        cout << ck(num) << '\n';
    }
}