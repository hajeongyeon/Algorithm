// 2020.08.31 20:11~20:58
// 백준 2638 치즈
// BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct info {
	int x, y;
	bool isMelt;
};

int n, m, board[100][100], ans;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
vector<info> cheese;

void Input()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 1) cheese.push_back({ i, j, false });
		}
	}
}

void FindInner()
{
	queue<pair<int, int>> q;

	q.push({ 0, 0 });
	board[0][0] = 2;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] ) continue;

			q.push({ nx, ny });
			board[nx][ny] = 2;
		}
	}
}

void Solve()
{
	while (1)
	{
		ans++;

		FindInner();

		for (int i = 0; i < cheese.size(); ++i)
		{
			if (cheese[i].isMelt) continue;

			int empty = 0;
			int x = cheese[i].x;
			int y = cheese[i].y;

			for (int j = 0; j < 4; ++j)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

				if (board[nx][ny] == 2) empty++;
			}

			if (empty >= 2) cheese[i].isMelt = true;
		}

		int meltcnt = 0;

		for (int i = 0; i < cheese.size(); ++i)
		{
			if (cheese[i].isMelt)
			{
				meltcnt++;
				board[cheese[i].x][cheese[i].y] = 2;
			}
		}

		if (meltcnt == cheese.size()) break;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (board[i][j] == 2)
					board[i][j] = 0;
	}

	cout << ans;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
