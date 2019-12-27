#include <iostream>
using namespace std;

int arr[2][100001];
int dp[2][100001];

int MAX(int a, int b) { return a > b ? a : b; }

void cleararr()
{
	for (int i = 0; i < 100001; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			arr[j][i] = 0;
			dp[j][i] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		cleararr();

		int n;
		cin >> n;

		for (int i = 1; i <= n; ++i) cin >> arr[0][i];
		for (int i = 1; i <= n; ++i) cin >> arr[1][i];

		dp[0][1] = arr[0][1]; dp[1][1] = arr[1][1];

		for (int i = 2; i <= n; ++i)
		{
			dp[0][i] = MAX(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = MAX(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}

		cout << MAX(dp[0][n], dp[1][n]) << "\n";
	}
}