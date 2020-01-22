#include <iostream>
using namespace std;

int dp[200001][22];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int m; cin >> m;

	for (int i = 1; i <= m; ++i)
		cin >> dp[i][0];

	for (int i = 1; i <= 21; ++i)
		for (int j = 1; j <= m; ++j)
			dp[j][i] = dp[dp[j][i - 1]][i - 1];

	int q; cin >> q;

	for (int i = 0; i < q; ++i)
	{
		int n, x;
		cin >> n >> x;

		for (int j = 21; j >= 0; --j)
		{
			if (n >= (1 << j))
			{
				n -= (1 << j);
				x = dp[x][j];
			}
		}

		cout << x << "\n";
	}
}