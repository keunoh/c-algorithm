#include <iostream>
#include <vector>

using namespace std;

void printPicked(vector<int>& picked) {
	for (auto& v : picked)
		cout << v << ' ';
	cout << '\n';
}

//n: 전체 원소의 수
//picked: 지금까지 고른 원소들의 번호
// toPick: 더 고를 원소의 수
// 일 때, 앞으로 toPick개의 원소를 고르는 모든 방법을 출력한다.
void pick(int n, vector<int>& picked, int toPick){
    //기저사례: 더 고를 원소가 없을 때 원소들을 출력한다.
    if(toPick == 0) { printPicked(picked); return; }
    //고를 수 있는 가장 작은 번호를 계산한다.
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    //이 단계에서 원소 하나를 고른다.
    for(int next=smallest;next<n;++next){
        picked.push_back(next);
        pick(n,picked,toPick-1);
        picked.pop_back();
    }

}

int main(){
    int n = 7;
    vector<int> v;

    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            for(int k=j+1;k<n;++k)
                for(int l=k+1;l<n;++l)
                    cout << i << " " << j << " " << k << " " << l << endl;

//위 코드 조각이 하는 작업은 네 개의 조각 -> 각 조각에서 하나의 원소 고르기
/* 남은 원소들을 고르는 '작업'
- 원소들의 총 개수
- 더 골라야 할 원소들의 개수
- 지금까지 고른 원소들의 번호
*/
    pick(n, v, 4);
}