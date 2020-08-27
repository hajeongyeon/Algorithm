#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct iceinfo {
	int x, y, h;
};

int n, m, board[300][300], dx[4] = { -1, 1, 0, 0, }, dy[4] = { 0, 0, -1, 1 };
vector<iceinfo> ice;

void Input()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
			if (board[i][j]) ice.push_back({ i, j, board[i][j] });
		}
	}
}

int FindLump()
{
	bool visited[300][300] = { 0, };
	int lumpcnt = 0;

	for (int i = 0; i < ice.size(); ++i)
	{
		if (!ice[i].h) continue;

		int ix = ice[i].x;
		int iy = ice[i].y;

		if (visited[ix][iy]) continue;

		lumpcnt++;
		queue<pair<int, int>> lump;
		lump.push({ ix, iy });
		visited[ix][iy] = true;

		while (!lump.empty())
		{
			int x = lump.front().first;
			int y = lump.front().second;
			lump.pop();

			for (int j = 0; j < 4; ++j)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m || !board[nx][ny] || visited[nx][ny]) continue;

				lump.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}

	return lumpcnt;
}

void Solve()
{
	int answer = 0;

	while (1)
	{
		int lumpcnt = FindLump();
		if (lumpcnt == 0)
		{
			answer = 0;
			break;
		}
		if (lumpcnt >= 2) break;

		for (int i = 0; i < ice.size(); ++i)
		{
			if (!ice[i].h) continue;

			int empty = 0;

			for (int j = 0; j < 4; ++j)
			{
				int nx = ice[i].x + dx[j];
				int ny = ice[i].y + dy[j];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

				if (board[nx][ny] == 0) empty++;
			}

			ice[i].h -= empty;
			if (ice[i].h < 0) ice[i].h = 0;
		}

		for (int i = 0; i < ice.size(); ++i)
			board[ice[i].x][ice[i].y] = ice[i].h;

		answer++;
	}

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
