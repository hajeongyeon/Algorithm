#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k, arr[100], dp[10001] = { 0, };
	cin >> n >> k;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	dp[0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = arr[i]; j <= k; ++j)
			if (j - arr[i] >= 0)
				dp[j] += dp[j - arr[i]];

	cout << dp[k];
}