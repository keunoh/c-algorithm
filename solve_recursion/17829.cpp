#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[1024][1024];
int n;

int divisionConquer(int half, int x, int y){
    vector<int> v;
    //기저사례 (x,y)는 2*2크기 배열의 왼쪽 상단 좌표
    if(half==1){
        v.push_back(matrix[y][x]);
        v.push_back(matrix[y][x+1]);
        v.push_back(matrix[y+1][x]);
        v.push_back(matrix[y+1][x+1]);
        sort(v.begin(), v.end());
        return v[2];
    }
    //n*n 크기의 배열을 (n/2)*(n/2) 크기의 배열 4개로 쪼개서 분할정복
    else{
        v.push_back(divisionConquer(half/2,x,y));
        v.push_back(divisionConquer(half/2,x+half,y));
        v.push_back(divisionConquer(half/2,x,y+half));
        v.push_back(divisionConquer(half/2,x+half,y+half));
        sort(v.begin(),v.end());
        return v[2];
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> matrix[i][j];
    cout << divisionConquer(n/2,0,0) << endl;
}