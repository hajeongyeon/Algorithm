#include <iostream>
#include <string>
#include <queue>
using namespace std;

int board[1001][1001];
int check[1001][1001][2];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int n, m;

struct info {
	int x, y, destroy;
};

int BFS()
{
	queue<info> q;
	q.push({ 0, 0, 1 });
	check[0][0][1] = 1;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().destroy;
		q.pop();

		if (x == n - 1 && y == m - 1) return check[x][y][d];
		
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (board[nx][ny] && d)
			{
				check[nx][ny][d - 1] = check[x][y][d] + 1;
				q.push({ nx, ny, d - 1 });
			}
			else if (!board[nx][ny] && !check[nx][ny][d])
			{
				check[nx][ny][d] = check[x][y][d] + 1;
				q.push({ nx, ny, d });
			}
		}
	}

	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		
		for (int j = 0; j < m; ++j) board[i][j] = str[j] - '0';
	}

	cout << BFS();
}