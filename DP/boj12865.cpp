// 2020.06.13 04:46~05:07
// 백준 12865 평범한 배낭
// DP

#include <iostream>
#include <algorithm>
using namespace std;

int n, k, w[101], v[101], dp[100001];

void Solve()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = k; j >= 1; --j)
		{
			if (w[i] <= j)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}

	cout << dp[k];
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> w[i] >> v[i];

	Solve();
}
