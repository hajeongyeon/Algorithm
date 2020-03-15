#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, arr[20][20], area[20][20], answer = 1e9;
pair<int, int> edge[4];

bool CanDrawEdge(int x, int y, int d1, int d2)
{
	// (x, y) 기준 ↙ 방향
	if (x + d1 >= n || y - d1 < 0) return false;
	// (x, y) 기준 ↘ 방향
	else if (x + d2 >= n || y + d2 >= n) return false;
	// (x + d1, y - d1) 기준 ↘ 방향
	else if (x + d1 + d2 >= n || y - d1 + d2 >= n) return false;
	// (x + d2, y + d2) 기준 ↙ 방향
	else if (x + d2 + d1 >= n || y + d2 - d1 < 0) return false;

	return true;
}

void Divide(int x, int y, int d1, int d2)
{
	int ppl[6] = { 0, };

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			area[i][j] = 5;

	// 1번 선거구
	int tmp = 0;
	for (int i = 0; i < edge[1].first; ++i)
	{
		if (i >= edge[0].first) tmp++;
		for (int j = 0; j <= edge[0].second - tmp; ++j)
			area[i][j] = 1;
	}

	// 2번 선거구
	tmp = 1;
	for (int i = 0; i <= edge[2].first; ++i)
	{
		if (i > edge[0].first) tmp++;
		for (int j = edge[0].second + tmp; j < n; ++j)
			area[i][j] = 2;
	}

	// 3번 선거구
	tmp = 1;
	for (int i = n - 1; i >= edge[1].first; --i)
	{
		if (i < edge[3].first) tmp++;
		for (int j = edge[3].second - tmp; j >= 0; --j)
			area[i][j] = 3;
	}

	// 4번 선거구
	tmp = 0;
	for (int i = n - 1; i > edge[2].first; --i)
	{
		if (i <= edge[3].first) tmp++;
		for (int j = edge[3].second + tmp; j < n; ++j)
			area[i][j] = 4;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ppl[area[i][j]] += arr[i][j];

	int pmax = 0, pmin = 1e9;
	for (int i = 1; i <= 5; ++i)
	{
		if (pmax < ppl[i]) pmax = ppl[i];
		if (pmin > ppl[i]) pmin = ppl[i];
	}

	answer = min(answer, pmax - pmin);
}

void Solve()
{
	// 외곽이 될 수 있는지 따짐
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = 1; j < n - 1; ++j)
		{
			for (int d1 = 1; d1 <= j; ++d1)
			{
				for (int d2 = 1; d2 < n - j; ++d2)
				{
					if (CanDrawEdge(i, j, d1, d2))
					{
						edge[0] = { i, j };
						edge[1] = { i + d1, j - d1 };
						edge[2] = { i + d2, j + d2 };
						edge[3] = { i + d1 + d2, j - d1 + d2 };

						Divide(i, j, d1, d2);
					}
				}
			}
		}
	}

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	Solve();
}