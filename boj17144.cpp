#include <iostream>
#include <queue>
using namespace std;

// 동서남북
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int map[50][50];	// 맵
int aircleaner[2][2] = { -1, -1, -1, -1 };	// 공기 청정기 위치
int r, c;			// 행, 열

// 반시계 방향 : 동북서남
int ccw[4] = { 0, 3, 1, 2 };
// 시계 방향 : 동남서북
int cw[4] = { 0, 2, 1, 3 };

void spread()
{
	queue<pair<int, int>> q;

	// 미세먼지가 있다면 vector에 저장
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (map[i][j] != 0)
			{
				q.push({i, j});
			}
		}
	}

	// tmp 배열에 현재 배열 저장
	int tmp[50][50] = { 0, };
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			tmp[i][j] = map[i][j];
		}
	}

	// 미세먼지 확산
	while(!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		int spreadDust = tmp[y][x] / 5;
		for (int j = 0; j < 4; ++j)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;

			if (tmp[ny][nx] >= 0)
			{
				map[ny][nx] += spreadDust;
				map[y][x] -= spreadDust;
			}
		}
	}
}

void activate()
{
	// tmp 배열에 현재 배열 저장
	int tmp[50][50] = { 0, };
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			tmp[i][j] = map[i][j];
		}
	}

	// 위쪽 - 반시계
	int x = aircleaner[0][0] + 1;
	int y = aircleaner[0][1];
	map[y][x] = 0;

	for (int i = 0; i < 4; ++i)
	{
		while (1)
		{
			int nx = x + dx[ccw[i]];
			int ny = y + dy[ccw[i]];

			if (nx == aircleaner[0][0] && ny == aircleaner[0][1]) break;
			if (nx < 0 || ny < 0 || nx >= c || ny >= r) break;

			map[ny][nx] = tmp[y][x];
			x = nx, y = ny;
		}
	}

	// 아래쪽 - 시계
	x = aircleaner[1][0] + 1;
	y = aircleaner[1][1];
	map[y][x] = 0;

	for (int i = 0; i < 4; ++i)
	{
		while (1)
		{
			int nx = x + dx[cw[i]];
			int ny = y + dy[cw[i]];

			if (nx == aircleaner[1][0] && ny == aircleaner[1][1]) break;
			if (nx < 0 || ny < 0 || nx >= c || ny >= r) break;

			map[ny][nx] = tmp[y][x];
			x = nx, y = ny;
		}
	}
}

void solve(int t)
{
	for (int i = 0; i < t; ++i)
	{
		spread();	// 미세먼지 확산
		activate();	// 공기청정기 작동
	}
}

int main(void)
{
	// 시간
	int t;
	cin >> r >> c >> t;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> map[i][j];

			if (map[i][j] == -1)
			{
				if (aircleaner[0][0] == -1)
				{
					aircleaner[0][0] = j;
					aircleaner[0][1] = i;
				}
				else
				{
					aircleaner[1][0] = j;
					aircleaner[1][1] = i;
				}
			}
		}
	}

	solve(t);

	int answer = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (map[i][j] >= 1)
			{
				answer += map[i][j];
			}
		}
	}

	cout << answer << endl;
}