// 2020.08.05 21:20~21:30
// 백준 1912 연속합
// DP

#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[100000], answer;

int main()
{
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	cin >> n;
	cin >> dp[0];
	answer = dp[0];

	for (int i = 1; i < n; ++i)
	{
		int a; cin >> a;
		dp[i] = a;

		if (dp[i - 1] + dp[i] > dp[i]) dp[i] = dp[i - 1] + dp[i];

		answer = max(answer, dp[i]);
	}

	cout << answer;
}
