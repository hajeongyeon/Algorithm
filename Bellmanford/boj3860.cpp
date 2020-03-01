#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct info {
	int f, t, c;
};

int w, h, g, board[31][31], hole[31][31], dist[31 * 31];
vector<info> route;

bool bellmanford()
{
	bool cycle = false;

	for (int i = 0; i < w * h - 1 - g && !cycle; ++i)
	{
		cycle = true;

		for (auto j : route)
		{
			if (dist[j.f] == 1e9) continue;
			if (j.f == w * h - 1) continue;
			if (dist[j.t] > dist[j.f] + j.c)
			{
				cycle = false;
				dist[j.t] = dist[j.f] + j.c;
			}
		}
	}

	cycle = false;
	for (auto i : route)
	{
		if (dist[i.f] == 1e9) continue;
		if (i.f == w * h - 1) continue;
		if (dist[i.t] > dist[i.f] + i.c)
		{
			cycle = true;
			break;
		}
	}

	if (cycle) return true;
	else return false;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (cin >> w >> h)
	{
		int e, dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

		if (!w && !h) break;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				board[i][j] = i * w + j;
				hole[i][j] = 0;
				dist[board[i][j]] = 1e9;
			}
		}

		route.clear();
		dist[0] = 0;

		cin >> g;

		for (int i = 0; i < g; ++i)
		{
			int x, y;
			cin >> x >> y;

			board[y][x] = -1;
		}

		cin >> e;

		for (int i = 0; i < e; ++i)
		{
			int x1, y1, x2, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;

			route.push_back({ board[y1][x1], board[y2][x2], t });

			hole[y1][x1] = 1;
		}

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (board[i][j] == -1 || hole[i][j]) continue;

				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
					if (board[nx][ny] == -1) continue;

					route.push_back({ board[i][j], board[nx][ny], 1 });
				}
			}
		}

		if (bellmanford()) cout << "Never\n";
		else
		{
			if (dist[w * h - 1] == 1e9) cout << "Impossible\n";
			else cout << dist[w * h - 1] << "\n";
		}
	}
}