// http://m.blog.daum.net/rhaoslikesan/369?tp_nil_a=2 Âü°í

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T; cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		int N; cin >> N;

		vector<int> dp(N + 1, 0);
		int u[2] = { 3, 2 };

		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 5;

		if (N > 2)
		{
			for (int i = 3; i <= N; ++i)
			{
				dp[i] = dp[i - 1] + 4 * dp[i - 2];

				for (int j = 3; j <= i; ++j)
					dp[i] += (u[j % 2] * dp[i - j]);
			}
		}

		cout << dp[N] << "\n";
	}
}