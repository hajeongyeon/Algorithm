#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, arr[1001] = { 0, }, dp[1001] = { 0, }, answer = 0;

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];

	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int MIN = 0;

		for (int j = 0; j < i; ++j)
			if (arr[j] < arr[i])
				if (MIN < dp[j])
					MIN = dp[j];

		dp[i] = MIN + 1;
		if (answer < dp[i]) answer = dp[i];
	}

	cout << answer;
}