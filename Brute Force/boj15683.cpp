#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 8;

int n, m;				// ����, ����
int arr[MAX][MAX];		// �繫�� ũ��
bool visited[MAX][MAX];

int answer = 100;

typedef struct {
	int i, j;	// ��ǥ
	int num;	// CCTV ��ȣ
	int dir;	// ����
} CCTV;

vector<CCTV> cctv;

void cctvlen(int dir, int x, int y)
{
	// ���ʺ��� �ð��������
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
	if (cctv[vecsize].num == 1)			// 1��
	{
		cctvlen(cctv[vecsize].dir, cctv[vecsize].i, cctv[vecsize].j);
	}
	else if (cctv[vecsize].num == 2)	// 2��
	{
		// CCTV 2���� ����/�¿� 2�����̱� ������ dir 2����
		if (cctv[vecsize].dir < 2)
		{
			cctvlen(cctv[vecsize].dir, cctv[vecsize].i, cctv[vecsize].j);
			cctvlen(cctv[vecsize].dir + 2, cctv[vecsize].i, cctv[vecsize].j);
		}
	}
	else if (cctv[vecsize].num == 3)	// 3��
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
	else if (cctv[vecsize].num == 4)	// 4��
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
	else if (cctv[vecsize].num == 5)	// 5��
	{
		cctvlen(0, cctv[vecsize].i, cctv[vecsize].j);
		cctvlen(1, cctv[vecsize].i, cctv[vecsize].j);
		cctvlen(2, cctv[vecsize].i, cctv[vecsize].j);
		cctvlen(3, cctv[vecsize].i, cctv[vecsize].j);
	}
}

void DFS(int vecsize)
{
	// ���� ����
	if (vecsize == cctv.size())
	{
		// ���� ���� tmp�� ����
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

	// ��� ����
	for (int i = 0; i < 4; ++i)		// CCTV 4����
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

			if (arr[i][j] > 0 && arr[i][j] < 6)	// CCTV��
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