#include <iostream>
using namespace std;

int n, dp[1000][10];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < 10; ++i) dp[1][i] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i][0] = 1;

		for (int j = 1; j < 10; ++j)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
	}

	int answer = 0;
	for (int i = 0; i < 10; ++i)
		answer += dp[n][i];

	cout << answer % 10007;
}