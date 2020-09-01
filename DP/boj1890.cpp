// 2020.09.01 22:49~23:00
// 백준 1890 점프
// DP

#include <iostream>
using namespace std;

int n, arr[101][101];
long dp[101][101];

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> arr[i][j];
}

void Solve()
{
	dp[1][1] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == n && j == n)
			{
				cout << dp[i][j];
				return;
			}

			if (dp[i][j] > 0)
			{
				if (j + arr[i][j] <= n) dp[i][j + arr[i][j]] += dp[i][j];
				if (i + arr[i][j] <= n) dp[i + arr[i][j]][j] += dp[i][j];
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
