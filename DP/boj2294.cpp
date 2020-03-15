#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k, arr[100], dp[10001];

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	for (int i = 0; i <= k; ++i) dp[i] = 100001;
	dp[0] = 0;

	for (int i = 0; i < n; ++i)
		for (int j = arr[i]; j <= k; ++j)
			if (dp[j] > dp[j - arr[i]] + 1)
				dp[j] = dp[j - arr[i]] + 1;

	if (dp[k] == 100001) cout << "-1";
	else cout << dp[k];
}