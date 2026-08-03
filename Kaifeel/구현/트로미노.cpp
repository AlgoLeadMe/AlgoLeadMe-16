#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[200][200];

bool isRange(int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= m)
		return false;
	return true;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}

	// Please write your code here.

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
		for (int j = 0; j < m; j++)
		{

			if (isRange(i, j + 1) && isRange(i + 1, j))
			{
				t1 = grid[i][j] + grid[i][j + 1] + grid[i + 1][j];
			}

			if (isRange(i + 1, j + 1) && isRange(i + 1, j))
			{
				t2 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 1][j];
			}

			if (isRange(i, j + 1) && isRange(i + 1, j + 1) && isRange(i + 1, j))
			{
				t3 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 1][j];
			}

			if (isRange(i, j) && isRange(i, j + 1) && isRange(i + 1, j + 1))
			{
				t4 = grid[i][j] + grid[i][j + 1] + grid[i + 1][j + 1];
			}

			if (isRange(i, j) && isRange(i, j + 1) && isRange(i, j + 2))
			{
				t5 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
			}

			if (isRange(i, j) && isRange(i + 1, j) && isRange(i + 2, j))
			{
				t6 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
			}
			result = max({result, t1, t2, t3, t4, t5, t6});
		}
	}

	cout << result;

	return 0;
}
