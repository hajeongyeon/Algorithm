#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 30;

struct coord {
	int z, y, x;	// 3차원 좌표
	int dist;		// 거리
};

int BFS(string s[][30], int *start, int *end, int L, int R, int C)
{
	queue<coord> q;
	// z, y, x 순으로 push
	q.push({ start[0], start[1], start[2], 0 });

	bool visited[MAX][MAX][MAX] = { 0, };
	// z, y, x
	visited[start[0]][start[1]][start[2]] = true;

	int dx[6] = { 0, 0, 1, -1, 0, 0 };
	int dy[6] = { 1, -1, 0, 0, 0, 0 };
	int dz[6] = { 0, 0, 0, 0, 1, -1 };

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int dist = q.front().dist;
		q.pop();

		// 도착
		if (z == end[0] && y == end[1] && x == end[2])
		{
			return dist;
		}

		// 6방향
		for (int i = 0; i < 6; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			// 맵을 벗어나면
			if (nx < 0 || ny < 0 || nz < 0 || nx >= C || ny >= R || nz >= L) continue;
			// 막혀있거나, 이미 방문했다면
			if (s[nz][ny][nx] == '#' || visited[nz][ny][nx]) continue;

			visited[nz][ny][nx] = true;
			q.push({ nz, ny, nx, dist + 1 });
		}
	}

	return -1;
}

int main(void)
{
	while (1)
	{
		// 층, 행, 열
		int L, R, C;
		cin >> L >> R >> C;

		// 맵 정보 --> z, y, x 순으로 저장
		string map[MAX][MAX];
		// 시작 지점과 출구 좌표 --> z, y, x 순으로 저장
		int start[3], end[3];

		if (L == 0 && R == 0 && C == 0) break;

		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < R; ++j)
			{
				cin >> map[i][j];

				for (int k = 0; k < C; ++k)
				{
					if (map[i][j][k] == 'S')
					{
						start[0] = i, start[1] = j, start[2] = k;
					}
					else if (map[i][j][k] == 'E')
					{
						end[0] = i, end[1] = j, end[2] = k;
					}
				}
			}
		}

		int result = BFS(map, start, end, L, R, C);
		if (result == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << result << " minute(s).\n";
	}
}