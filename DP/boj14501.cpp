#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[16], t[16], p[16], answer = -1;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> t[i] >> p[i];

	for (int i = 1; i <= n + 1; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			dp[i] = max(dp[i], dp[j]);
			
			if (j + t[j] == i)
				dp[i] = max(dp[i], dp[j] + p[j]);
		}

		answer = max(answer, dp[i]);
	}

	cout << answer;
}