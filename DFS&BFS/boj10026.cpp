#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
char board[100][100];
bool visited[100][100];

void Solve()
{
	int rg = 0, nrg = 0;
	int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
	queue<pair<int, int>> q;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (visited[i][j]) continue;
			q.push({ i, j });
			visited[i][j] = true;

			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; ++k)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (visited[nx][ny] || board[nx][ny] != board[x][y]) continue;

					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}

			rg++;
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (visited[i][j]) continue;
			q.push({ i, j });
			visited[i][j] = true;

			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; ++k)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (visited[nx][ny]) continue;
					if ((board[x][y] == 'R' || board[x][y] == 'G') && board[nx][ny] == 'B') continue;
					if (board[x][y] == 'B' && (board[nx][ny] == 'R' || board[nx][ny] == 'G')) continue;

					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}

			nrg++;
		}
	}

	cout << rg << " " << nrg;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];

	Solve();
}