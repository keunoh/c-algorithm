#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int k;
char sign[11];  //부둥호 담은 수열
int num[11];    //조합으로 만들어진 수열
bool ch[11];    //숫자 중복 불허
vector<string> ans; //부등호를 만족하는 수열을 저장하는 벡터
string maxnum, minnum;

bool SignCheck(char a, char b, char oper) { //부등호를 만족시키는지 검사
    if(oper == '<') {
        if(a > b) return false;
    }
    else {
        if(a < b) return false;
    }
    return true;
}

void Combination(int index, string num) {
    //index: 선택해야 할 (수열에서의) 숫자 자리, 0부터 9까지
    if(index == (k+1)) {
        ans.push_back(num);
        return;
    }
    for(int i = 0; i <= 9; i++) {
        if(ch[i]) continue; //이미 사용한 숫자라면 지나감

        //첫번째 자리 숫자를 고르는 거라면, 무조건 선택(index == 0)
        //그게 아니라면, 앞자리 숫자 num[index-1]과 현재 선택하려는 숫자 i와 부등호를 넘긴다.
        if(index == 0 || SignCheck(num[index-1], i+'0', sign[index-1])) {
            ch[i] = true;   //선택
            Combination(index+1, num + to_string(i)); //다음 자리수 선택을 위해 재귀호출
            ch[i] = false;
        }
    }
}

int main(){

    cin >> k;

    for(int i = 0; i < k; i++) {
        cin >> sign[i];
    }

    Combination(0, "");

    sort(ans.begin(), ans.end());

    cout << ans[ans.size()-1] << '\n' << ans[0];

    return 0;
}