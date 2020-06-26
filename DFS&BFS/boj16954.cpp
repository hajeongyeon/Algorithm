// 2020.06.27 01:44~03:23
// 백준 16954 움직이는 미로 탈출
// BFS

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

struct info {
	int x, y, cnt;
};

char board[8][8], tmpboard[8][8][8];
vector<pair<int, int>> wall;

int dx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

void Input()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == '#')
			{
				tmpboard[0][i][j] = '#';
				wall.push_back({ i, j });
			}
		}
	}

	for (int t = 0; t < 8; t++)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (tmpboard[t][i][j] == '#') continue;
				tmpboard[t][i][j] = '.';
			}
		}
	}
}

void MakeMap()
{
	for (int i = 0; i < wall.size(); ++i)
	{
		int x = wall[i].first;
		int y = wall[i].second;
		int t = 1;

		while(1)
		{
			int nx = x + 1;
			int ny = y;

			if (nx >= 8) break;

			tmpboard[t][nx][ny] = '#';
			t++;
			x = nx;
			y = ny;
		}
	}
}

bool Finish(int x, int cnt)
{
	for (int i = x - 1; i >= 0; --i)
		for (int j = 0; j < 8; ++j)
			if (tmpboard[cnt][i][j] != '.') return false;

	return true;
}

void Solve()
{
	if (!wall.size())
	{
		cout << 1;
		return;
	}

	MakeMap();

	queue<info> q;
	q.push({ 7, 0, 0 });

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		if (x == 0 || Finish(x, cnt))
		{
			cout << "1";
			return;
		}

		for (int i = 0; i < 9; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ncnt = cnt + 1;

			if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
			if (tmpboard[cnt][nx][ny] == '#' || tmpboard[ncnt][nx][ny] == '#') continue;

			q.push({ nx, ny, ncnt });
		}
	}

	cout << "0";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
