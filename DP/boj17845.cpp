#include <iostream>
using namespace std;

#define MAX(a, b) a > b ? a : b

int N, K;

int dp[10001];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < K; ++i)
	{
		int importance, studytime;
		cin >> importance >> studytime;

		for (int t = N; t - studytime >= 0; --t)
		{
			if (dp[t - studytime] + importance > dp[t])
			{
				dp[t] = dp[t - studytime] + importance;
			}
		}
	}

	int answer = -1e9; 
	for (int i = 0; i <= N; ++i)
	{
		answer = MAX(answer, dp[i]);
	}

	cout << answer;
}