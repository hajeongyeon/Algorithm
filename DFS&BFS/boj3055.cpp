#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;
pair<int, int> start, finish;
char board[51][51];

vector<pair<int, int>> water;
int watertime[51][51] = { 0, };

void WaterBFS()
{
	int dx[4] = { 0, 0, -1 ,1 };
	int dy[4] = { -1, 1, 0, 0 };

	queue<pair<int, int>> q;

	for (int i = 0; i < water.size(); ++i)
	{
		q.push({ water[i].first, water[i].second });
		watertime[water[i].first][water[i].second] = 0;
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (watertime[nx][ny]) continue;
			if (board[nx][ny] == 'D' || board[nx][ny] == 'X') continue;

			q.push({ nx, ny });
			watertime[nx][ny] = watertime[x][y] + 1;
		}
	}
}

void TimeBFS()
{
	int visited[51][51] = { 0, };

	int dx[4] = { 0, 0, -1 ,1 };
	int dy[4] = { -1, 1, 0, 0 };

	queue<pair<int, int>> q;
	q.push(start);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (board[x][y] == 'D')
		{
			cout << visited[x][y];
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (visited[nx][ny]) continue;
			if (board[nx][ny] == '*' || board[nx][ny] == 'X') continue;

			if (!watertime[nx][ny])
			{
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx, ny });
			}
			else
			{
				if (watertime[nx][ny] > visited[x][y] + 1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}

	cout << "KAKTUS";
	return;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 'S')
			{
				start.first = i;
				start.second = j;
			}
			else if (board[i][j] == '*')
				water.push_back({ i, j });
		}
	}

	WaterBFS();
	TimeBFS();
}