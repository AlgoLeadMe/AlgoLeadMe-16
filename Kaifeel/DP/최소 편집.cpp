#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int editDistance(string s1, string s2, int n1, int n2)
{
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

	for (int i = 0; i <= n1; i++)
		dp[i][0] = i;
	for (int j = 0; j <= n2; j++)
		dp[0][j] = j;

	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
			}
		}
	}
	return dp[n1][n2];
}

int main()
{
	int n1, n2;
	string str1, str2;

	cin >> n1 >> str1;
	cin >> n2 >> str2;

	int result = editDistance(str1, str2, n1, n2);
	cout << result;

	return 0;
}