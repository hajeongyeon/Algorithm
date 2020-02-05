#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct info {
	int x, y, c;
};

bool operator < (info a, info b)
{
	return a.c < b.c;
}

int N, M, cost[51][51], check[51][51];
char board[51][51];
pair<int, int> start, flower;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	memset(check, -1, sizeof(check));
}

void MakeCost()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == 'S') start = { i, j };
			else if (board[i][j] == 'F') flower = { i, j };
			else if (board[i][j] == 'g') cost[i][j] = 3000;
			else
			{
				bool isAround = false;

				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

					if (board[nx][ny] == 'g') isAround = true;
				}

				if (isAround) cost[i][j] = 1;
			}
		}
	}
}

void Dijkstra()
{
	priority_queue<info> pq;
	pq.push({ start.first, start.second, cost[start.first][start.second] });

	while (!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int c = -1 * pq.top().c;
		pq.pop();

		if (check[x][y] != -1) continue;

		check[x][y] = c;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

			pq.push({ nx, ny, -1 * (c + cost[nx][ny]) });
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	MakeCost();
	Dijkstra();

	cout << check[flower.first][flower.second] / 3000 << " " << check[flower.first][flower.second] % 3000;
}