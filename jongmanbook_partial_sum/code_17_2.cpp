//배열의 부분합과 제곱의 부분합을 입력받고 특정 구간의 분산을 계산하는 함수의 구현

#include <vector>
using namespace std;
//A[]의 제곱의 부분 합 벡터 sqpsum, A[]의 부분 합 벡터 psum이 주어질 때
//A[a..b]의 분산을 반환한다.
double variance(const vector<int>& sqpsum,
                const vector<int>& psu, int a, int b) {
                    //우선 해당 구간의 평균을 계산한다.
    double mean = rangeSum(psum, a, b) / double(b - a + 1);
    double ret = rangeSum(sqpsum, a, b) 
            - 2 * mean * rangeSum(psum, a, b)
            + (b - a + 1) * mean * mean;
    return ret / (b - a + 1);
}