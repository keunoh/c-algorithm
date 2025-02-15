#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M;
vector<int> f1;
string result = "Messi Gimossi";
int search(int Step, int order);
int main()
{
  cin >> M;
  f1.push_back(5);
  f1.push_back(13);

  int a = 5;
  int b = 13;
  int mm = 0;

  while (mm < M)
  {
    mm = a + b + 1;
    a = b;
    b = mm;
    f1.push_back(mm);
  }
  int size = f1.size();
  int answer = search(size, M);
  if (answer == -1 || answer == 6)
  {
    cout << "Messi Messi Gimossi" << endl;
  }
  else
  {
    cout << result[answer - 1];
  }
}

int search(int Step, int order)
{
  if (order <= f1[1])
    return order;
  if (order <= f1[Step - 1])
    return search(Step - 1, order);
  else if (order == f1[Step - 1] + 1)
    return -1;
  else
    return search(Step - 2, order - f1[Step - 1] - 1);
}