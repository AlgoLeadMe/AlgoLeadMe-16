#include <string>
#include <vector>
#include <deque>
#include <map>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
	int answer = 0;

	deque<string> dq;
	map<string, int> mp;

	// LRU 최근에 사용된 것 사용하기 페이지 폴트 큐를 사용

	if (cacheSize == 0)
		return cities.size() * 5;

	for (auto &city1 : cities)
	{
		string city = "";
		for (char &c : city1)
			city += tolower(c);
		if (dq.size() != cacheSize)
		{
			if (mp[city])
			{
				answer += 1;
				// 가장 최근 값으로 옮기기
				auto it = dq.begin();
				for (; it < dq.end(); it++)
				{
					if (*it == city)
					{
						it = dq.erase(it);
						dq.push_back(city);
						break;
					}
				}
				continue;
			}
			dq.push_back(city);
			mp[city] = 1;
			answer += 5;
		}
		else
		{
			if (mp[city])
			{
				answer += 1;

				// 가장 최근 값으로 옮기기
				auto it = dq.begin();
				for (; it < dq.end(); it++)
				{
					if (*it == city)
					{
						it = dq.erase(it);
						dq.push_back(city);
						break;
					}
				}

				continue;
			}
			string back = dq[0];
			mp[back] = 0;
			dq.push_back(city);
			dq.pop_front();
			mp[city] = 1;
			answer += 5;
		}
	}

	return answer;
}