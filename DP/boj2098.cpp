#include <iostream>
#include <algorithm>
using namespace std;

int n;
int city[17][17];
int dp[17][1 << 17];

void Input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> city[i][j];
	}
}

int TSP(int curr, int visited)
{
	if (visited == (1 << n) - 1)
	{
		if (city[curr][0]) return city[curr][0];
		return 1e9;
	}

	int& ret = dp[curr][visited];
	if (ret) return ret;
	ret = 1e9;

	for (int i = 0; i < n; ++i)
	{
		if (visited & (1 << i)) continue;
		if (city[curr][i] == 0) continue;

		ret = min(ret, TSP(i, visited | (1 << i)) + city[curr][i]);
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	cout << TSP(0, 1);
}