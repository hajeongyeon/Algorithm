#include <iostream>
#include <queue>
using namespace std;

int n, m, visited[100][100];
char board[100][100];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
			visited[i][j] = 1e9;
		}
	}
	visited[0][0] = 1;

	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == '0') continue;

			if (visited[nx][ny] > visited[x][y] + 1)
			{
				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}

	cout << visited[n - 1][m - 1];
}