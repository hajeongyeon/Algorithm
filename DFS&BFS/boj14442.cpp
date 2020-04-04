#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct info {
	int x, y, dtr;
};

int n, m, k;
int board[1001][1001], chk[1001][1001][11];
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { -1, 1, 0, 0 };
queue<info> q;

int BFS()
{
	q.push({ 1, 1, 0 });
	for (int i = 0; i <= k; ++i) chk[1][1][i] = 1;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().dtr;
		q.pop();

		if (x == n && y == m) return chk[x][y][d];

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;

			if (board[nx][ny] && d < k && !chk[nx][ny][d])
			{
				chk[nx][ny][d + 1] = chk[x][y][d] + 1;
				q.push({ nx, ny, d + 1 });
			}
			else if (!board[nx][ny] && !chk[nx][ny][d])
			{
				chk[nx][ny][d] = chk[x][y][d] + 1;
				q.push({ nx, ny, d });
			}
		}
	}

	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
	{
		string str; cin >> str;

		for (int j = 1; j <= m; ++j)
			board[i][j] = str[j - 1] - '0';
	}

	cout << BFS();
}