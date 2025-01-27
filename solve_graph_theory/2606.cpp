#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int counttt = 0;
int N, Pair;
queue<int> Q;
int G[MAX][MAX];
bool visited[MAX] = {
    0,
};

void BFS(int s)
{
  Q.push(s);
  visited[s] = true;

  while (!Q.empty())
  {
    s = Q.front();
    Q.pop();

    for (int i = 0; i <= N; i++)
    {
      if (G[s][i] == 1 && visited[i] == 0)
      {
        Q.push(i);
        visited[i] = true;
        counttt++;
      }
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> Pair;

  for (int i = 0; i < Pair; i++)
  {
    int start, end;
    cin >> start >> end;
    G[start][end] = 1;
    G[end][start] = 1;
  }
  BFS(1);
  cout << counttt << '\n';
  return 0;
}