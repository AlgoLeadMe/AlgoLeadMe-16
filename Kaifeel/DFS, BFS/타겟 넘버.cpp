#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int total, int start, int end, vector<int> numbers, int target)
{
	if (start == end)
	{
		if (total == target)
			answer++;
		return;
	}

	dfs(total + numbers[start], start + 1, end, numbers, target);
	dfs(total - numbers[start], start + 1, end, numbers, target);
}

int solution(vector<int> numbers, int target)
{

	int n = numbers.size();

	dfs(0, 0, n, numbers, target);

	return answer;
}