#include <iostream>
#include <queue>
using namespace std;

struct sqr {
	int depth, rx, ry, bx, by;
};

int n, m, answer = -1;
char board[10][10];
pair<int, int> red, blue;
bool visited[10][10][10][10];

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void Move(int& x, int& y, int dir)
{
	while (1)
	{
		x += dx[dir];
		y += dy[dir];

		if (board[x][y] == 'O') break;
		else if (board[x][y] == '#')
		{
			x -= dx[dir];
			y -= dy[dir];
			break;
		}
	}
}

void BFS()
{
	queue<sqr> q;
	q.push({ 0, red.first, red.second, blue.first, blue.second });
	visited[red.first][red.second][blue.first][blue.second] = true;

	int cnt = 0;

	while (!q.empty())
	{
		sqr s = q.front();
		q.pop();

		if (s.depth > 10) break;
		if (board[s.rx][s.ry] == 'O')
		{
			answer = s.depth;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int rx = s.rx, ry = s.ry, bx = s.bx, by = s.by;
			Move(rx, ry, i), Move(bx, by, i);

			if (board[bx][by] == 'O') continue;
			if (rx == bx && ry == by)
			{
				if (i == 0) s.rx < s.bx ? bx++ : rx++;
				else if (i == 1) s.rx < s.bx ? rx-- : bx--;
				else if (i == 2) s.ry < s.by ? by++ : ry++;
				else s.ry < s.by ? ry-- : by--;
			}

			if (!visited[rx][ry][bx][by])
			{
				q.push({ s.depth + 1, rx ,ry, bx, by });
				visited[rx][ry][bx][by] = true;
			}
		}
	}

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 'R') red = { i, j };
			else if (board[i][j] == 'B') blue = { i, j };
		}
	}

	BFS();
}