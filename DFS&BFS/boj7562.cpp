// 2020.08.01 19:22~19:39
// 백준 7562 나이트의 이동
// BFS

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int s;
pair<int, int> from, to;
int board[300][300];

void Solve()
{
	board[from.first][from.second] = 0;

	int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	queue<pair<int, int>> q;
	q.push({ from.first, from.second });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == to.first && y == to.second)
		{
			cout << board[x][y] << "\n";
			return;
		}

		for (int i = 0; i < 8; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= s || ny >= s || board[nx][ny]) continue;

			board[nx][ny] = board[x][y] + 1;
			q.push({ nx, ny });
		}

		if (x == 0 && y == 0) board[x][y] = -1;
	}
}

int main()
{
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	int tc; cin >> tc;

	for (int t = 0; t < tc; ++t)
	{
		memset(board, 0, sizeof(board));

		cin >> s;
		cin >> from.first >> from.second;
		cin >> to.first >> to.second;

		Solve();
	}
}
