#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable)
{
	string answer = "";
	sort(timetable.begin(), timetable.end());

	deque<int> times;

	for (auto &time : timetable)
	{
		int t = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
		times.push_back(t);
	}

	int shuttle = 9 * 60;
	int ptime = 0;

	for (int bus = 0; bus < n; ++bus)
	{

		int member_cnt = 0;
		int lastTime = 0;

		while (!times.empty() && times.front() <= shuttle && member_cnt < m)
		{
			lastTime = times.front();
			times.pop_front();

			member_cnt++;
		}

		if (bus == n - 1)
		{
			if (member_cnt == m)
			{
				ptime = lastTime - 1;
			}
			else
			{
				ptime = shuttle;
			}
		}

		shuttle += t;
	}

	string hour = to_string(ptime / 60);
	string minute = to_string(ptime % 60);

	if (hour.size() == 1)
		hour = "0" + hour;

	if (minute.size() == 1)
		minute = "0" + minute;

	return hour + ":" + minute;
}