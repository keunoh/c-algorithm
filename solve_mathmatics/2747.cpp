#include <iostream>
using namespace std;

int main()
{
  int n;
  int DP[45];

  cin >> n;

  DP[0] = 0;
  DP[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    DP[i] = DP[i - 1] + DP[i - 2];
  }

  cout << DP[n] << endl;

  return 0;
}