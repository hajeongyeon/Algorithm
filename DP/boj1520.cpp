#include <iostream>
using namespace std;

int m, n;

int board[500][500];
int dp[500][500];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int DFS(int y, int x)
{
	if (x == 0 && y == 0) return 1;

	if (dp[y][x] == -1)
	{
		dp[y][x] = 0;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (board[y][x] < board[ny][nx]) dp[y][x] += DFS(ny, nx);
		}
	}

	return dp[y][x];
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> m >> n;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	cout << DFS(m - 1, n - 1);
}