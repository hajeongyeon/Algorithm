#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, row;
pair<int, int> depth[40001];
vector<int> hole;

void Solve()
{
	for (int i = 0; i < hole.size(); ++i)
	{
		int x = hole[i];
		int h = depth[x].first;
		depth[x].second = h;

		for (int j = x - 1; j >= 0; --j)
		{
			h = min(h, depth[j].first);
			depth[j].second = max(depth[j].second, h);
		}
		h = depth[x].first;
		for (int j = x + 1; j < row; ++j)
		{
			h = min(h, depth[j].first);
			depth[j].second = max(depth[j].second, h);
		}
	}

	int answer = 0;
	for (int i = 0; i < row; ++i)
		answer += (depth[i].first - depth[i].second);
	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int a, b, c, d;
	cin >> n;
	cin >> a >> b;
	for (int i = 0; i < n / 2 - 1; ++i)
	{
		cin >> a >> b >> c >> d;
		for (int j = a; j < c; ++j)
			depth[j].first = b;
	}
	cin >> row >> b;

	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> a >> b >> c >> d;
		hole.push_back(a);
	}

	Solve();
}