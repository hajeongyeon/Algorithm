#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, arr[4000][4];

void Input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 4; ++j)
			cin >> arr[i][j];
}

void Solve()
{
	vector<int> vec1, vec2;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int sum = arr[i][0] + arr[j][1];
			vec1.push_back(sum);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int sum = arr[i][2] + arr[j][3];
			vec2.push_back(sum);
		}
	}

	sort(vec2.begin(), vec2.end());

	long long answer = 0;
	for (int i = 0; i < vec1.size(); ++i)
	{
		auto ub = upper_bound(vec2.begin(), vec2.end(), -vec1[i]) - vec2.begin() + 1;
		auto lb = lower_bound(vec2.begin(), vec2.end(), -vec1[i]) - vec2.begin() + 1;

		answer += (ub - lb);
	}

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}