// 2020.08.15 19:05~20:10
// 백준 2225 합분해
// DP

#include <iostream>
using namespace std;

int n, k;
// dp[k][n] = k개를 더해서 합이 n인 경우
long long int dp[201][201];
long long int mod = 1000000000;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i <= n; ++i)
	{
		dp[1][i] = 1;
	}

	for (int i = 1; i <= k; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			for (int k = 0; k <= j; ++k)
			{
				dp[i][j] += dp[i - 1][j - k];
				dp[i][j] %= 1000000000;
			}
		}
	}

	cout << dp[k][n];
}
