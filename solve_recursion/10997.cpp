#include <iostream>
        
        
          
          using namespace std;
        
        
          
          

        
        
          
          const int MAX = 4 * 100 + 100;
        
        
          
          

        
        
          
          char starMap[MAX][MAX];
        
        
          
          

        
        
          
          void func(int y, int x, int depth)
        
        
          
          {
        
        
          
          	if (depth == 2)
        
        
          
          	{
        
        
          
          		for (int i = 0; i < 5; i++)
        
        
          
          		{
        
        
          
          			starMap[y][x + i] = '*';
        
        
          
          			starMap[y + 6][x + i] = '*';
        
        
          
          		}
        
        
          
          

        
        
          
          		for (int i = 1; i < 6; i++)
        
        
          
          		{
        
        
          
          			starMap[y + i][x] = '*';
        
        
          
          		}
        
        
          
          

        
        
          
          		for (int i = 2; i < 6; i++)
        
        
          
          		{
        
        
          
          			starMap[y + i][x + 4] = '*';
        
        
          
          

        
        
          
          			if (i > 4)
        
        
          
          			{
        
        
          
          				continue;
        
        
          
          			}
        
        
          
          

        
        
          
          			starMap[y + i][x + 2] = '*';
        
        
          
          		}
        
        
          
          

        
        
          
          		starMap[y + 2][x + 3] = '*';
        
        
          
          

        
        
          
          		return;
        
        
          
          	}
        
        
          
          

        
        
          
          	// 맨위, 맨아래
        
        
          
          	for (int i = 0; i < 4 * (depth - 1) + 1; i++)
        
        
          
          	{
        
        
          
          		starMap[y][x + i] = '*';
        
        
          
          		starMap[y + 7 + 4 * (depth - 2) - 1][x + i] = '*';
        
        
          
          	}
        
        
          
          

        
        
          
          	// 맨 왼쪽, 오른쪽
        
        
          
          	for (int i = 1; i < 7 + 4 * (depth - 2); i++)
        
        
          
          	{
        
        
          
          		starMap[y + i][x] = '*';
        
        
          
          

        
        
          
          		if (i == 1)
        
        
          
          		{
        
        
          
          			continue;
        
        
          
          		}
        
        
          
          

        
        
          
          		starMap[y + i][x + 4 * (depth - 1)] = '*';
        
        
          
          	}
        
        
          
          

        
        
          
          	// (맨 위에서 세 번쨰, 맨 오른쪽에서 두 번쨰)
        
        
          
          	starMap[y + 2][x + 4 * (depth - 1) - 1] = '*';
        
        
          
          

        
        
          
          	func(y + 2, x + 2, depth - 1);
        
        
          
          

        
        
          
          	return;
        
        
          
          }
        
        
          
          

        
        
          
          int main(void)
        
        
          
          {
        
        
          
          	int N;
        
        
          
          	cin >> N;
        
        
          
          

        
        
          
          	if (N == 1)
        
        
          
          	{
        
        
          
          		cout << "*\n";
        
        
          
          

        
        
          
          		return 0;
        
        
          
          	}
        
        
          
          

        
        
          
          	func(0, 0, N);
        
        
          
          

        
        
          
          	for (int i = 0; i < 7 + 4 * (N - 2); i++)
        
        
          
          	{
        
        
          
          		if (i == 1)
        
        
          
          		{
        
        
          
          			cout << "*\n";
        
        
          
          

        
        
          
          			continue;
        
        
          
          		}
        
        
          
          

        
        
          
          		for (int j = 0; j < 4 * (N - 1) + 1; j++)
        
        
          
          		{
        
        
          
          			char c = starMap[i][j] == '*' ? '*' : ' ';
        
        
          
          

        
        
          
          			cout << c;
        
        
          
          		}
        
        
          
          

        
        
          
          		cout << "\n";
        
        
          
          	}
        
        
          
          

        
        
          
          	return 0;
        
        
          
          }