#include <iostream>
#include <queue>
using namespace std;

struct info {
	int x, y, cnt, key;
};

int N, M;

char board[51][51];
pair<int, int> start;

// x, y, key(bit)
bool visited[55][55][64];

int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };

void Solve()
{
	queue<info> q;
	q.push({ start.first, start.second, 0, 0 });
	visited[start.first][start.second][0] = true;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int key = q.front().key;
		q.pop();

		if (board[x][y] == '1')
		{
			cout << cnt;
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny][key]) continue;
			if (board[nx][ny] == '#') continue;

			if ('a' <= board[nx][ny] && board[nx][ny] <= 'f')
			{
				// key의 (board[nx][ny] - 'a')번째 bit를 킴
				int newKey = key | (1 << ((int)(board[nx][ny] - 'a')));
				if (!visited[nx][ny][newKey])
				{
					visited[nx][ny][key] = true;
					visited[nx][ny][newKey] = true;

					q.push({ nx, ny, cnt + 1, newKey });
				}
			}
			else if ('A' <= board[nx][ny] && board[nx][ny] <= 'F')
			{
				// key의 (board[nx][ny] - 'A')번째 bit가 켜져있으면
				if (key & 1 << ((int)(board[nx][ny] - 'A')))
				{
					visited[nx][ny][key] = true;
					q.push({ nx, ny, cnt + 1, key });
				}
			}
			else
			{
				visited[nx][ny][key] = true;
				q.push({ nx, ny, cnt + 1, key });
			}
		}
	}

	cout << "-1";
	return;
}

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == '0')
			{
				start.first = i;
				start.second = j;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}