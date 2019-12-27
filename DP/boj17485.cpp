#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int fuel[1001][1001];
int dp[1001][1001][3];

void FindRoute(int x, int y)
{
	int f = fuel[x][y];

	if (y == 0)
	{
		dp[x][y][0] = min(dp[x - 1][y + 1][1], dp[x - 1][y + 1][2]) + f;
		dp[x][y][1] = dp[x - 1][y][0] + f;
	}
	else if (y == M - 1)
	{
		dp[x][y][1] = dp[x - 1][y][2] + f;
		dp[x][y][2] = min(dp[x - 1][y - 1][0], dp[x - 1][y - 1][1]) + f;
	}
	else
	{
		dp[x][y][0] = min(dp[x - 1][y + 1][1], dp[x - 1][y + 1][2]) + f;
		dp[x][y][1] = min(dp[x - 1][y][0], dp[x - 1][y][2]) + f;
		dp[x][y][2] = min(dp[x - 1][y - 1][0], dp[x - 1][y - 1][1]) + f;
	}
}

void Solve()
{
	int answer = 1e9;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			dp[0][i][j] = fuel[0][i];
		}
	}

	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			FindRoute(i, j);
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (dp[N - 1][i][j])
				answer = min(answer, dp[N - 1][i][j]);
		}
	}

	cout << answer;
}

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> fuel[i][j];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}