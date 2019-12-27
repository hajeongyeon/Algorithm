#include <iostream>
#include <queue>
using namespace std;

struct info {
	int x, y;
	bool sword;
};

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int N, M, T;
int board[101][101];

int visited[101][101];		// 그람 없을 때
int visitedG[101][101];		// 그람 있을 때

void BFS()
{
	queue<info> q;
	q.push({ 0, 0, false });
	visited[0][0] = true;

	bool princess = false;

	for (int t = 0; t <= T; ++t)
	{
		int size = q.size();

		for(int i = 0; i < size; ++i)
		{
			int x = q.front().x;
			int y = q.front().y;
			bool sword = q.front().sword;
			q.pop();

			if (board[x][y] == 2) sword = true;
			if (x == N - 1 && y == M - 1)
			{
				princess = true;
				break;
			}

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				// 성 밖
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				// 그람이 없는데 벽이면
				if (!sword && board[nx][ny] == 1) continue;
				// 그람이 없는데 이미 방문했던 곳이면
				if (!sword && visited[nx][ny]) continue;
				// 그람이 있는데 이미 방문했던 곳이면
				if (sword && visitedG[nx][ny]) continue;

				if (sword) visitedG[nx][ny] = true;
				else visited[nx][ny] = true;

				q.push({ nx, ny, sword });
			}
		}

		if (princess)
		{
			cout << t;
			break;
		}
	}

	if (!princess) cout << "Fail";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> T;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	BFS();
}