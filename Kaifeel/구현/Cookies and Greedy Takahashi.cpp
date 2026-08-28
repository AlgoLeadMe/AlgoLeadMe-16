#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<ll> plus;

	vector<ll> minus;

	while (n--)
	{
		ll num;
		cin >> num;
		if (num > 0)
			plus.push_back(num);
		else
			minus.push_back(num);
	}

	sort(plus.begin(), plus.end());
	sort(minus.rbegin(), minus.rend());

	int i = 0, j = 0;
	ll ans = 0;
	ll cur = 0;

	while (i != minus.size() || j != plus.size())
	{

		ll leftD = LLONG_MAX;
		ll rightD = LLONG_MAX;

		if (i < minus.size())
			leftD = abs(minus[i] - cur);
		if (j < plus.size())
			rightD = abs(plus[j] - cur);

		if (leftD <= rightD)
		{
			ans += leftD;
			cur = minus[i];
			i++;
		}
		else
		{
			ans += rightD;
			cur = plus[j];
			j++;
		}
	}

	cout << ans;
}