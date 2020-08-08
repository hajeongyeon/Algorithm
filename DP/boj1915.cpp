#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < m; ++j)
			if (str[j] - '0' == 1)
				dp[i][j + 1] = min(dp[i - 1][j], min(dp[i - 1][j + 1], dp[i][j])) + 1;
	}

	int answer = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (answer < dp[i][j]) answer = dp[i][j];

	cout << answer * answer;
}
