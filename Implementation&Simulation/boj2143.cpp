#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;
int a[1000], b[1000];

void Input()
{
	cin >> t;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> b[i];
}

void Solve()
{
	vector<int> vec1, vec2;

	for (int i = 0; i < n; ++i)
	{
		int sum = a[i];
		vec1.push_back(sum);

		for (int j = i + 1; j < n; ++j)
		{
			sum += a[j];
			vec1.push_back(sum);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int sum = b[i];
		vec2.push_back(sum);

		for (int j = i + 1; j < m; ++j)
		{
			sum += b[j];
			vec2.push_back(sum);
		}
	}

	sort(vec2.begin(), vec2.end());

	long long answer = 0;
	for (int i = 0; i < vec1.size(); ++i)
	{
		auto ub = upper_bound(vec2.begin(), vec2.end(), t - vec1[i]) - vec2.begin() + 1;
		auto lb = lower_bound(vec2.begin(), vec2.end(), t - vec1[i]) - vec2.begin() + 1;

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