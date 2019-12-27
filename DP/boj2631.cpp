#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	int arr[201] = { 0, };
	int dp[201] = { 0, };
	int answer = 0;

	cin >> N;

	for (int i = 0; i < N; ++i) cin >> arr[i];

	for (int i = 0; i < N; ++i)
	{
		dp[i] = 1;

		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	for (int i = 0; i < N; ++i)
		answer = max(answer, dp[i]);

	cout << N - answer;
}