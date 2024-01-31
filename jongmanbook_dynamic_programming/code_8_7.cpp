//와일드카드 문제를 해결하는 동적 계획법 알고리즘
#include <string>
using namespace std;

//-1은 아직 답이 계산되지 않았음을 의미한다.
//1은 해당 입력들이 서로 대응됨을 의미한다.
//0은 해당 입력들이 서로 대응되지 않음을 의미한다.
int cache[101][101];
//패턴과 문자열
string W, S;
//와일드카드 패턴 W[w..]가 문자열 S[s..]에 대응되는지 여부를 반환한다.
bool matchMemoized(int w, int s) {
    //메모이제이션
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    //W[w]와 S[s]를 맞춰나간다.
    while(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        ++w;
        ++s;
    }
}