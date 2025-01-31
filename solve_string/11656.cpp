#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000

int main()
{
  string word;
  int len;

  cin >> word;
  len = word.length();
  // 배열의 변수는 동적일 수 없으므로 심볼릭 상수로 대체
  string arr[MAX] = {};

  for (int i = 0; i < len; i++)
  {
    // word의 인덱스 i부터 len 전까지 문자열 자르기
    arr[i] = word.substr(i, len);
  }

  // 배열의 시작점 주소 arr에서 마지막 주소인 arr + len 까지 오름차순 재정렬
  sort(arr, arr + len);

  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << '\n';
  }

  return 0;
}