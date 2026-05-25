#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string X, string Y)
{
	string answer = "";
	int arr[10] = {0};

	if (X.size() > Y.size())
		swap(X, Y);

	for (char &y : Y)
	{
		arr[y - '0']++;
	}

	for (char &x : X)
	{
		if (arr[x - '0'])
		{
			answer += x;
			arr[x - '0']--;
		}
	}

	//     for (char& x : X) {
	//         for (char &y : Y)
	//         {
	//             if (x == y)
	//             {

	//                 if (arr[y-'0'] != 0) {
	//                     arr[y-'0']--;
	//                     answer += y;
	//                     break;
	//                 }
	//             }

	//         }

	//     }

	sort(answer.rbegin(), answer.rend());
	if (answer == "")
		return "-1";
	else if (answer[0] == '0')
		return "0";
	else
		return answer;

	return answer;
}