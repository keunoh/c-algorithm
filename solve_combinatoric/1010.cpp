#include <iostream>

int main()
{
  int T = 0;

  std::cin >> T;

  for (int i = 0; i < T; i++)
  {
    long long result = 1;
    int N = 0;
    int M = 0;

    std::cin >> N >> M;

    int r = 1;
    for (int j = M; j > M - N; j--)
    {
      result = result * j;
      result = result / r;
      r++;
    }

    std::cout << result << std::endl;
  }
}