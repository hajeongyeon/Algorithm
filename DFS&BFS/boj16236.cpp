// 좌표와 거리 저장
// 거리가 짧은 것 먼저
// 거리가 같으면 y가 작은 것 먼저
// y도 같다면 x가 작은 것 먼저

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 상어 구조체
struct shark {
	int x, y;	// 좌표
	int dist;	// 거리

	bool operator < (const shark &s) const
	{
		if (dist == s.dist)
		{
			if (y == s.y)
			{
				return x > s.x;
			}
			else
			{
				return y > s.y;
			}
		}
		else
		{
			return dist > s.dist;
		}
	}
};

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int n;							// 공간 크기
int map[20][20];				// 공간
priority_queue<shark> q;		// shark 정보 저장 우선순위 큐

int BFS()
{
	bool check[20][20];			// 방문했는지
	memset(check, false, sizeof(check));

	int sharkage = 2;			// 상어 나이
	int eat = 0;				// 먹은 물고기 수
	int answer = 0;

	while (!q.empty())
	{
		int x = q.top().x, y = q.top().y, dist = q.top().dist;
		q.pop();

		// 물고기 먹을 수 있으면
		if (map[y][x] > 0 && map[y][x] < sharkage)
		{
			map[y][x] = 0;	// 물고기 먹음
			eat++;

			if (eat == sharkage)	// 먹은 물고기의 수가 나이랑 같으면
			{
				sharkage++;
				eat = 0;
			}

			answer += dist;

			dist = 0;

			memset(check, false, sizeof(check));
			while (!q.empty()) q.pop();
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;	// 공간을 넘어가면
			if (check[ny][nx]) continue;							// 이미 방문했다면
			if (map[ny][nx] > sharkage) continue;					// 물고기의 크기가 상어보다 크면

			q.push({ nx, ny, dist + 1 });
			check[ny][nx] = true;
		}
	}

	return answer;
}

int main(void)
{
	cin >> n;

	// i가 세로, j가 가로
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];

			// 아기 상어가 있는 위치
			if (map[i][j] == 9)
			{
				q.push({ i, j, 0 });
				map[i][j] = 0;
			}
		}
	}

	cout << BFS() << endl;
}