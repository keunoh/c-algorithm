#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
  int N;
  map<string, int> book;
  string input;
  int max_sales_rate;
  string best_seller;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> input;

    if (book.find(input) == book.end())
    {
      book.insert({input, 1});
    }
    else
    {
      book[input]++;
    }
  }

  max_sales_rate = 0;
  for (auto i = book.begin(); i != book.end(); i++)
  {
    max_sales_rate = max(max_sales_rate, i->second);
  }

  for (auto i = book.begin(); i != book.end(); i++)
  {
    if (max_sales_rate == i->second)
    {
      best_seller = i->first;
      break;
    }
  }

  cout << best_seller;

  return 0;
}