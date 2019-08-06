#include <iostream>
#include <queue>
using namespace std;

// ��������
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int map[50][50];	// ��
int aircleaner[2][2] = { -1, -1, -1, -1 };	// ���� û���� ��ġ
int r, c;			// ��, ��

// �ݽð� ���� : ���ϼ���
int ccw[4] = { 0, 3, 1, 2 };
// �ð� ���� : ��������
int cw[4] = { 0, 2, 1, 3 };

void spread()
{
	queue<pair<int, int>> q;

	// �̼������� �ִٸ� vector�� ����
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

	// tmp �迭�� ���� �迭 ����
	int tmp[50][50] = { 0, };
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			tmp[i][j] = map[i][j];
		}
	}

	// �̼����� Ȯ��
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
	// tmp �迭�� ���� �迭 ����
	int tmp[50][50] = { 0, };
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			tmp[i][j] = map[i][j];
		}
	}

	// ���� - �ݽð�
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

	// �Ʒ��� - �ð�
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
		spread();	// �̼����� Ȯ��
		activate();	// ����û���� �۵�
	}
}

int main(void)
{
	// �ð�
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