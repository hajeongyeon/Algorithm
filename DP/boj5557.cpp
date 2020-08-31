// 2020.08.31 21:31~22:18
// 백준 5557 1학년
// DP

#include <iostream>
using namespace std;

int n, arr[101], result;
long dp[101][21];

void Input()
{
	cin >> n;
	for (int i = 1; i < n; ++i)
		cin >> arr[i];
	cin >> result;
}

void Solve()
{
	dp[1][arr[1]]++;

	for (int i = 2; i < n; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			if (dp[i - 1][j])
			{
				if (j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];
				if (j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[n - 1][result];
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
