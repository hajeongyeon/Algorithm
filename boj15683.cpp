#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 8;

int n, m;				// 세로, 가로
int arr[MAX][MAX];		// 사무실 크기
bool visited[MAX][MAX];

int answer = 100;

typedef struct {
	int i, j;	// 좌표
	int num;	// CCTV 번호
	int dir;	// 방향
} CCTV;

vector<CCTV> cctv;

void cctvlen(int dir, int x, int y)
{
	// 동쪽부터 시계방향으로
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	while (1)
	{
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
		if (arr[nx][ny] == 6) break;

		if (arr[nx][ny] == 0) arr[nx][ny] = -1;
		nx += dx[dir];
		ny += dy[dir];
	}
}

void monitor(int vecsize)
{
	if (cctv[vecsize].num == 1)			// 1번
	{
		cctvlen(cctv[vecsize].dir, cctv[vecsize].i, cctv[vecsize].j);
	}
	else if (cctv[vecsize].num == 2)	// 2번
	{
		// CCTV 2번은 상하/좌우 2개뿐이기 때문에 dir 2개만
		if (cctv[vecsize].dir < 2)
		{
			cctvlen(cctv[vecsize].dir, cctv[vecsize].i, cctv[vecsize].j);
			cctvlen(cctv[vecsize].dir + 2, cctv[vecsize].i, cctv[vecsize].j);
		}
	}
	else if (cctv[vecsize].num == 3)	// 3번
	{
		if (cctv[vecsize].dir == 3)
		{
			cctvlen(cctv[vecsize].dir, cctv[vecsize].i, cctv[vecsize].j);
			cctvlen(0, cctv[vecsize].i, cctv[vecsize].j);
		}
		else
		{
			cctvlen(cctv[vecsize].dir, cctv[vecsize].i, cctv[vecsize].j);
			cctvlen(cctv[vecsize].dir + 1, cctv[vecsize].i, cctv[vecsize].j);
		}
	}
	else if (cctv[vecsize].num == 4)	// 4번
	{
		if (cctv[vecsize].dir % 2 == 0)
		{
			cctvlen(cctv[vecsize].dir, cctv[vecsize].i, cctv[vecsize].j);
			cctvlen(1, cctv[vecsize].i, cctv[vecsize].j);
			cctvlen(3, cctv[vecsize].i, cctv[vecsize].j);
		}
		else
		{
			cctvlen(cctv[vecsize].dir, cctv[vecsize].i, cctv[vecsize].j);
			cctvlen(0, cctv[vecsize].i, cctv[vecsize].j);
			cctvlen(2, cctv[vecsize].i, cctv[vecsize].j);
		}
	}
	else if (cctv[vecsize].num == 5)	// 5번
	{
		cctvlen(0, cctv[vecsize].i, cctv[vecsize].j);
		cctvlen(1, cctv[vecsize].i, cctv[vecsize].j);
		cctvlen(2, cctv[vecsize].i, cctv[vecsize].j);
		cctvlen(3, cctv[vecsize].i, cctv[vecsize].j);
	}
}

void DFS(int vecsize)
{
	// 기저 조건
	if (vecsize == cctv.size())
	{
		// 현재 맵을 tmp에 저장
		int tmparr[MAX][MAX] = { 0, };
		memcpy(tmparr, arr, sizeof(arr));

		for(int i = 0; i < vecsize; ++i)
			monitor(i);

		int tmpmin = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (arr[i][j] == 0) tmpmin++;
			}
		}

		if (answer > tmpmin) answer = tmpmin;
		memcpy(arr, tmparr, sizeof(tmparr));

		return;
	}

	// 재귀 조건
	for (int i = 0; i < 4; ++i)		// CCTV 4방향
	{
		cctv[vecsize].dir = i;
		DFS(vecsize + 1);
	}
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];

			if (arr[i][j] > 0 && arr[i][j] < 6)	// CCTV면
			{
				CCTV c;
				c.i = i;
				c.j = j;
				c.num = arr[i][j];

				cctv.push_back(c);
			}
		}
	}

	DFS(0);

	cout << answer;
}