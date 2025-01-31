#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int N, M, count = 0;
  std::string str;
  std::vector<std::string> v;
  std::cin >> N >> M;

  while (N--)
  {
    std::cin >> str;
    v.push_back(str);
  }

  std::sort(v.begin(), v.end());

  while (M--)
  {
    std::cin >> str;

    if (std::binary_search(v.begin(), v.end(), str))
      count++;
  }
  std::cout << count;
}