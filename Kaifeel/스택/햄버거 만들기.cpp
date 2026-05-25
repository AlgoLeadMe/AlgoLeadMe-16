#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient)
{
	//     즐거운 벡터문제

	vector<int> setting;

	int answer = 0;
	for (auto &food : ingredient)
	{
		setting.push_back(food);

		if (setting.size() >= 4)
		{
			int n = setting.size();
			if (setting[n - 1] == 1 && setting[n - 2] == 3 && setting[n - 3] == 2 && setting[n - 4] == 1)
			{
				setting.pop_back();
				setting.pop_back();
				setting.pop_back();
				setting.pop_back();
				answer++;
			}
		}
	}

	return answer;
}