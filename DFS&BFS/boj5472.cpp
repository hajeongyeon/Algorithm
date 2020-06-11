// 2020.06.12 03:05~04:46
// 백준 5472 
// BFS

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct info {
	int x, y, t;
};

int n, m;
char board[1002][1002];
pair<int, int> sg;
queue<pair<int, int>> fire_q;
int check[1002][1002][2];

int dx[4] = { 0, 0 ,-1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int BFS()
{
	while (!fire_q.empty())
	{
		int x = fire_q.front().first;
		int y = fire_q.front().second;
		fire_q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
			if (board[nx][ny] == '#' || check[nx][ny][0] != 0) continue;

			check[nx][ny][0] = check[x][y][0] + 1;
			fire_q.push({ nx, ny });
		}
	}

	queue<info> human_q;
	human_q.push({ sg.first, sg.second, 1 });
	check[sg.first][sg.second][1] = 1;
	bool flag = false;
	int answer = 0;

	while (!human_q.empty())
	{
		int x = human_q.front().x;
		int y = human_q.front().y;
		int t = human_q.front().t;
		human_q.pop();

		if (x == 0 || y == 0 || x == m + 1 || y == n + 1) return t - 1;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx > m + 1 || ny > n + 1) continue;
			if (board[nx][ny] == '*' || board[nx][ny] == '#') continue;
			if (check[nx][ny][0] != 0 && check[nx][ny][0] <= t + 1) continue;
			if (check[nx][ny][1]) continue;

			check[nx][ny][1] = 1;
			human_q.push({ nx, ny, t + 1 });
		}
	}

	return -1;
}

void Init()
{
	for (int i = 0; i <= m + 1; ++i)
		for (int j = 0; j <= n + 1; ++j)
			board[i][j] = '.';

	memset(check, 0, sizeof(check));
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	for (int tc = 0; tc < t; ++tc)
	{
		Init();

		cin >> n >> m;

		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				cin >> board[i][j];

				if (board[i][j] == '*')
				{
					fire_q.push({ i, j });
					check[i][j][0] = 1;
				}
				else if (board[i][j] == '@') sg = make_pair(i, j);
			}
		}

		int answer = BFS();

		if (answer != -1) cout << answer << "\n";
		else cout << "IMPOSSIBLE\n";
	}
}
